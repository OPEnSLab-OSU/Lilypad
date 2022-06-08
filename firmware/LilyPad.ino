#include <Loom.h>

// Include configuration
const char* json_config = 
#include "config.h"
;

// In Tools menu, set:
// Internet  > None
// Radios    > Disabled
// Sensors   > Enabled
// Actuators > Disabled
// Max       > Disabled


// Pins
#define SD_CS 10
#define SCK 24
#define MOSI 23
#define RTC_INT 12
#define RAIL_3V 5
#define RAIL_5V 6

// Sleep duration
#define DAYS 0
#define HOURS 0
#define MINUTES 0
#define SECONDS 5

#define POWER_UP_DELAY 1000


using namespace Loom;
Loom::Manager Feather{};

void wakeISR_RTC() {
  detachInterrupt(RTC_INT); // Disable the interrupt
}

void setup() 
{
  // Needs to be done for Hypno Board
  pinMode(RAIL_3V, OUTPUT);   // Enable control of 3.3V rail 
  pinMode(RAIL_5V, OUTPUT);   // Enable control of 5V rail 

  //See Above
  digitalWrite(RAIL_3V, LOW); // Enable 3.3V rail
  digitalWrite(RAIL_5V, HIGH);  // Enable 5V rail

  Feather.begin_LED();
  Feather.begin_serial(true);
  Feather.parse_config(json_config);
  Feather.print_config();
  
  // Register an interrupt on the RTC alarm pin
  getInterruptManager(Feather).register_ISR(RTC_INT, wakeISR_RTC, LOW, ISR_Type::IMMEDIATE);

  LPrintln("\n ** Setup Complete ** ");
}

void loop() 
{
  Feather.measure();
  Feather.package();
  Feather.display_data();
  getSD(Feather).log();

  // Set alarm for appropriate time in the future
  getInterruptManager(Feather).RTC_alarm_duration(TimeSpan(DAYS, HOURS, MINUTES, SECONDS));
  getInterruptManager(Feather).reconnect_interrupt(RTC_INT);

  digitalWrite(RAIL_3V, HIGH); // Disable 3.3V rail
  digitalWrite(RAIL_5V, LOW);  // Disable 5V rail

  // Disable SPI pins/SD chip select to save power
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(SD_CS, INPUT);

  Feather.power_down();
  getSleepManager(Feather).sleep(); // Sketch pauses here until RTC alarm

  digitalWrite(RAIL_3V, LOW); // Enable 3.3V rail
  digitalWrite(RAIL_5V, HIGH);  // Enable 5V rail

  // Re-enable SPI pins/SD chips select
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(SD_CS, OUTPUT);

  Feather.power_up();
  delay(POWER_UP_DELAY); // Must delay a bit for SD to stabilize upon wake
}
