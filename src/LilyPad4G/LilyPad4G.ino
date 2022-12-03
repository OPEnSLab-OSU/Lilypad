/**
 * LilyPad4G.ino
 * This project uses the VEML7700, DS18B20, and SHT31 sensor to log environment data and logs it to both the SD card and also MQTT/MongoDB
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

Manager manager("Lilypad4G", 1); //Establish the Loom manager first
Loom_Hypnos hypnos(manager, HYPNOS_VERSION::V3_3, TIME_ZONE::PST, true); // Create a new Hypnos object
Loom_Analog analog(manager); // Analog for reading battery voltage

// Create sensor classes
Loom_SHT31 sht(manager);

// Create lte and mqtt classes
Loom_LTE lte(manager, NETWORK_APN, NETWORK_USER, NETWORK_PASS);
Loom_MQTT mqtt(manager, lte.getClient(), SECRET_BROKER, SECRET_PORT, DATABASE, BROKER_USER, BROKER_PASS);

// Called when the RTC interrupt is triggered 
void isrTrigger(){
  hypnos.wakeup();
}

void setup() {
  manager.beginSerial();                // Wait 20 seconds for the serial console to open
  hypnos.enable();                      // Enable the hypnos rails
  manager.initialize();                 // Initialize all in-use modules
  hypnos.registerInterrupt(isrTrigger); // Register the ISR and attach to the interrupt
}

void loop() {
  manager.measure();       // Measure sensor values
  manager.package();       // Package data from measurments
  manager.display_data();  // Print the current JSON packet                      
  hypnos.logToSD();        // Log the data to the SD card              
  mqtt.publish();          // Publish the collected data to MQTT

  hypnos.setInterruptDuration(TimeSpan(0, 0, 1, 0)); // Interrupt every 1 minute
  hypnos.reattachRTCInterrupt();
  hypnos.sleep();
  
}
