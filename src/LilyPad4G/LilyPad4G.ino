/**
 * LilyPad4G.ino
 * This project uses the VEML7700, DS18B20, and SHT31 sensor to log environment data and logs it to both the SD card and also MQTT/MongoDB
 * TODO: long term test
 */

// UNCOMMENT THE FOLLOWING LINE TO NOT USE INTERNET
//#define USE_INTERNET 
// UNCOMMENT THE FOLLOWING LINE TO NOT USE RTC INTERRUPT
//#define USE_RTC_INT
#define DEBUG_DELAY 5 // Sets delay time in seconds when rtc interrupt isnt used

#include "arduino_secrets.h"

// Loom includes
#include <Loom_Manager.h>
#include <Hardware/Loom_Hypnos/Loom_Hypnos.h>
// Sensor Includes
#include <Sensors/Loom_Analog/Loom_Analog.h>
#include <Sensors/I2C/Loom_SHT31/Loom_SHT31.h>
// Internet/DB Includes
#ifdef USE_INTERNET
#include <Internet/Logging/Loom_MQTT/Loom_MQTT.h>
#include <Internet/Connectivity/Loom_LTE/Loom_LTE.h>
#endif
// OneWire Includes
#include <OneWire.h>
#include <DallasTemperature.h>
// Adafruit VEML7700 breakout include
#include "Adafruit_VEML7700.h"

Manager manager("Lilypad4G", 1); //Establish the Loom manager first
Loom_Hypnos hypnos(manager, HYPNOS_VERSION::V3_2, TIME_ZONE::PST, true); // Create a new Hypnos object
Loom_Analog analog(manager); // Add battery voltage measurement

// Create sensor classes
Loom_SHT31 sht(manager);
// Create lte and mqtt classes
#ifdef USE_INTERNET
Loom_LTE lte(manager, NETWORK_APN, NETWORK_USER, NETWORK_PASS);
Loom_MQTT mqtt(manager, lte.getClient(), SECRET_BROKER, SECRET_PORT, DATABASE, BROKER_USER, BROKER_PASS);
#endif

// Create oneWire/DallasTemperature sensor classes
#define ONE_WIRE_BUS 11
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress ds18b20Address;

// Initialize Adafruit VEML7700 class
Adafruit_VEML7700 veml = Adafruit_VEML7700();

// Called when the RTC interrupt is triggered 
void isrTrigger(){
  hypnos.wakeup();
}

void setup() {
  manager.beginSerial();                // Wait 20 seconds for the serial console to open
  hypnos.enable();                      // Enable the hypnos rails
  manager.initialize();                 // Initialize all in-use modules
  hypnos.registerInterrupt(isrTrigger); // Register the ISR and attach to the interrupt
  sensors.begin();                      // locate onewire devices on the bus
  Serial.printf("[OneWire] Found %d devides...\n", sensors.getDeviceCount());
  if (!sensors.getAddress(ds18b20Address, 0)) Serial.println("[DS18B20] Unable to find address for Device 0");
  Serial.printf("[DS18B20] Address: 0x%x...\n", ds18b20Address);
  sensors.setResolution(ds18b20Address, 12); // Set to the highest resolution
  Serial.printf("[DS18B20] Resolution: %d...\n", sensors.getResolution(ds18b20Address));
  if (!veml.begin()) { // Startup veml sensor communication and set defaults
    Serial.println("[VEML7700] Sensor not found...");
  }
  Serial.println("[VEML7700] Sensor found...");
}

void loop() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  float tempC = sensors.getTempC(ds18b20Address); // Extract the temperature in C
  manager.measure();       // Measure sensor values
  manager.package();       // Package data from measurments
  manager.addData("DS18B20", "Temperature", tempC); // Manually add the data to the JSON 
  manager.addData("VEML7700", "Raw_ALS", veml.readALS()); // Manually add raw ALS value
  manager.addData("VEML7700", "Raw_White", veml.readWhite()); //Manually add raw White value
  manager.addData("VEML7700", "LUX", veml.readLux(VEML_LUX_AUTO)); // Manually add auto LUX value
  manager.display_data();  // Print the current JSON packet                      
  hypnos.logToSD();        // Log the data to the SD card
  #ifdef USE_INTERNET              
  mqtt.publish();          // Publish the collected data to MQTT
  #endif
  #ifdef USE_RTC_INT
  hypnos.setInterruptDuration(TimeSpan(0, 0, 1, 0)); // Interrupt every 1 minute
  hypnos.reattachRTCInterrupt();
  hypnos.sleep();
  #else
  delay(DEBUG_DELAY * 1000);
  #endif
}