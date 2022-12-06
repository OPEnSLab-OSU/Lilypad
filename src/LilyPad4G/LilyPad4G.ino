/**
 * LilyPad4G.ino
 * This project uses the VEML7700, DS18B20, and SHT31 sensor to log environment data and logs it to both the SD card and also MQTT/MongoDB
 * TODO: rename sensors, test LTE, MGTT, VEML7700
 */
#include "arduino_secrets.h"
// Loom includes
#include <Loom_Manager.h>
#include <Hardware/Loom_Hypnos/Loom_Hypnos.h>
// Sensor Inlcudes
#include <Sensors/Loom_Analog/Loom_Analog.h>
#include <Sensors/I2C/Loom_SHT31/Loom_SHT31.h>
// Internet/DB Includes
#include <Internet/Logging/Loom_MQTT/Loom_MQTT.h>
#include <Internet/Connectivity/Loom_LTE/Loom_LTE.h>

#include <OneWire.h>
#include <DallasTemperature.h>

Manager manager("Lilypad4G", 1); //Establish the Loom manager first
Loom_Hypnos hypnos(manager, HYPNOS_VERSION::V3_2, TIME_ZONE::PST, true); // Create a new Hypnos object
Loom_Analog analog(manager);

// Create sensor classes
Loom_SHT31 sht(manager);

// Create lte and mqtt classes
//Loom_LTE lte(manager, NETWORK_APN, NETWORK_USER, NETWORK_PASS);
//Loom_MQTT mqtt(manager, lte.getClient(), SECRET_BROKER, SECRET_PORT, DATABASE, BROKER_USER, BROKER_PASS);


#define ONE_WIRE_BUS 11
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// arrays to hold device address
DeviceAddress ds18b20Address;

// Called when the RTC interrupt is triggered 
void isrTrigger(){
  hypnos.wakeup();
}

void setup() {
  manager.beginSerial();                // Wait 20 seconds for the serial console to open
  hypnos.enable();                      // Enable the hypnos rails
  manager.initialize();                 // Initialize all in-use modules
  hypnos.registerInterrupt(isrTrigger); // Register the ISR and attach to the interrupt
  Serial.println("Dallas Temperature IC Control Library Demo");

  // locate devices on the bus
  sensors.begin();
  Serial.print("[OneWire] Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");
  if (!sensors.getAddress(ds18b20Address, 0)) Serial.println("[DS18B20] Unable to find address for Device 0");
  // show the addresses we found on the bus
  Serial.print("[DS18B20] Address: ");
  printAddress(ds18b20Address);
  Serial.println();
  // set the resolution to 9 bit (Each Dallas/Maxim device is capable of several different resolutions)
  sensors.setResolution(ds18b20Address, 9);
  Serial.print("[DS18B20] Resolution: ");
  Serial.print(sensors.getResolution(ds18b20Address), DEC);
  Serial.println();
}

void loop() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  manager.measure();       // Measure sensor values
  manager.package();       // Package data from measurments
  float tempC = sensors.getTempC(ds18b20Address);
  manager.addData("DS18B20", "Temperature", tempC);
  manager.display_data();  // Print the current JSON packet                      
  hypnos.logToSD();        // Log the data to the SD card              
  //mqtt.publish();          // Publish the collected data to MQTT
  hypnos.setInterruptDuration(TimeSpan(0, 0, 1, 0)); // Interrupt every 1 minute
  //hypnos.reattachRTCInterrupt();
  //hypnos.sleep();
  delay(5000);  
}

// function to print a device address
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}