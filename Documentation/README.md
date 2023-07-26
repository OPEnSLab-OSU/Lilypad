# Lilypad | [Wiki](https://github.com/OPEnSLab-OSU/Lilypad/wiki)
Project Lead: **Colin Hale-Brown**
Project Members: **Cameron Whitlow**, **Aiden Olsen**

## Abstract

Fresh water is becoming one of the most valuable resources in the world. The Lilypad aims to provide live data to assist in water loss prevention and water management. The Lilypad aims to be a low cost alternative to traditional methods of long term monitoring. To assist water management the Lilypad collects water temperature, air temperature, air humidity, and Solar Energy per square meter logging the data locally to a SD card and sending the data over 4G for live monitoring.


## Specifications Table

| Hardware | Lilypad |
| --- | --- |
| Subject Area | Environmental and agricultural Sciences |
| Hardware Type | Field Measurements and sensors |
| Closest Commercial Analog | [Floating Weather Station](https://www.fiedler.company/en/products/meteorological-stations-and-measuring-sensors/weather-stations/plovouc-meteorologick-stanic) |
| Open Source License | |
| Cost of Hardware | |
| Source File Repository | |
| OSHWA certification UID | |

1. ## Hardware in Context

Without deploying a whole weather station to a lake how are you supposed to know the rate of water loss? The Lilypad hopes to give water shed management groups and researchers alike the ability to monitor the rate of water loss. This is critical for allocating resources appropriately to prevent excess water loss due to evaporation. Deploying shade balls or other measures is costly and providing data on where they are most needed can help conserve the most valuable resource we have, fresh water.

Using our current sensor suite is not a traditional ways of measuring water loss. [LGSONIC](https://www.lgsonic.com/products/monitoring-buoy/) sells a floating water quality monitoring suite that can have additional sensors added to measure water loss. The other option is to build a weather station and measure local conditions to model water loss.

2. ## Hardware Description

The Lilypad is a floating platform for long term water sensing. Using three thick acrylic panels the Lilypad captures two buoys, a solar panel and electronics box. Leaving mounting points for sensors, counterweights, and deployment. Using laser cutting to capture, orient, and provide structure to the components of the buoy allows us to cut costs significantly. 

3. ## Design Files Summary

4. ## Bill of Materials Summary

| Component Type | Item Description | Quantity Per Unit | Dist. Website | Notes | Material Cost | Per Unit Cost |
| :--- | :--- | ---: | :--- | :--- | ---: | ---: |
| Electrical | Feather M0 | 1 | | Adafruit #: 2772 | $19.95 | $19.95 |
| Electrical | Hypnos v3.2 | 1 | OPEnS | In-house part | $35.00 | $35.00 |
| Electrical | Coin Cell Battery | 1 | | | | |
| Electrical | microSD Card | 1 | | | | |
| Electrical | SparkFun SARA-R4 | 1 | | | $90.95 | $90.95 |
| Electrical | SHT31 | 1 |  | Humidity and Air Temp. | $19.90 | $19.90 |
| Electrical | DS18B20 | 1 | | Water Temp. Adafruit #: 381 | $9.95 | $9.95 |
| Electrical | Right Angle VEML7700 Lux Sensor | 1 |  | Light Intensity, Adafruit #: 5378 | $4.95 | $4.95 |
| Electrical | 4 Wire Cable | 1 | | | $18.49 | $18.49 |
| Electrical | 6W 6V Solar Panel | 1 | | | $59 | $59 |
| Electrical | 10050mAh Battery | 1 | | Adafruit #: 5035 | $29.98 | $29.98 |
| Electrical  | Thermister | 1 | | Monitor Battery Temp. Adafruit #: 372 | $4.00 | $4.00 |
| | | | | | | |
| PCB | LilyPadv2 Motherboard | 1 | | | | $21.82 |
| PCB | D1 (Green LED) | 1 |  | indicator, 160-1446-1-ND | $0.26 | $0.26 |
| PCB | ## (Red LED) | 1 | | indicator, 160-1447-1-ND | $0.26 | $0.26 |
| PCB | D2 (SK34A) | 1 | | SK34AFL-TP | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | | 
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | | 
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |

5. ## Build Instructions

<details open>
<summary><h1>⚡Electronics Assembly</h1> - Click to view electronics assembly steps</summary>

### Hypnos:
1. Assemble short male headers to underside and short female headers on the top side
2. Insert coin cell battery for RTC
3. Add SD card for logging

    <img src="https://user-images.githubusercontent.com/71784728/231924572-1d53fd61-329a-4dc0-adea-2878e81b820a.jpg" width=400 />

### Feather M0 Proto:
1. Solder short male headers to the underside

    <img src="https://user-images.githubusercontent.com/71784728/231924647-a9b8d235-a19f-401d-be91-4d870b0f6329.jpg" width=400 />

### Sparkfun LTE:
1. Solder male headers to board
2. Switch positions: SHIELD & HARD
3. Insert SIM card

    <img src="https://user-images.githubusercontent.com/71784728/231924680-5d5c6135-1b47-4f1f-beab-4625c0b0d8a7.jpg" height=300 />
    <img src="https://user-images.githubusercontent.com/71784728/231924696-a224330d-009b-4b6d-b540-cad70c7d8cfb.jpg" height=300 />

### Lilypad PCB:
1. Assemble surface mount components and reflow

    <img src="https://github.com/OPEnSLab-OSU/Lilypad/blob/main/Documentation/images/LilypadPCB_design_labeled.png" height=300 />

   <img src="https://user-images.githubusercontent.com/71784728/231924802-dc374c2c-8af7-4d64-be26-2774339266b0.jpg" height=300 />

3. Solder short 12 and 16 pin female headers to the top side of the PCB for the Feather MO.
4. Solder screw terminals in corresponding spots
5. Solder on power switch, then bend headers at 90 degree angle so switch is flat on PCB.

    <img src="https://user-images.githubusercontent.com/71784728/231924833-23fb0f01-a90e-4a0f-b334-e59fd956ede5.jpg" height=300 />

6. Soler short male headers to top and bottom rows of through holes on the bottom side of the PCB for the LTE board.

### Battery:
1. Make a tiny slice in battery casing (make sure to not cut into a cell)
2. Insert the 10k thermistor and tape to secure 
3. Place heat shrink round battery JST and thermistor

    <img src="https://user-images.githubusercontent.com/71784728/231924881-bb2b6cc7-dacf-465b-b399-beb640ab4b39.jpg" height=300 />
    <img src="https://user-images.githubusercontent.com/71784728/231925106-22d8d4b6-6bed-4900-837c-c1f8d6c94bf7.gif" height=300 />

### VEML7700, SHT31, DS18B20:
1. Cut wire to appropriate length
2. Strip and tin wire ends

### Combining Hardware
1. Directly solder the Sparkfun LTE board to the underside of the Lilypad PCB.

    <img src="https://user-images.githubusercontent.com/71784728/231925212-a99ee019-a4f6-4e79-8571-29054c3b7532.jpg" height=300 />

2. Stack the assembled Feather M0 onto the Hypnos PDB and slot into the female headers

    <img src="https://user-images.githubusercontent.com/71784728/231925236-1833a501-512d-4c13-8a5a-588b5d9ddbce.jpg" height=300 />
    <img src="https://user-images.githubusercontent.com/71784728/231925255-5086dcda-50b4-48dd-8a63-77909d1195d3.jpg" height=300 />

3. Screw in sensors to their respective ports

    <img src="https://user-images.githubusercontent.com/71784728/231925276-ba3d41cf-fbc8-49a1-ae23-0f40fa6cdeee.jpg" height=300 />

4. Screw in thermistor and plug in battery

    <img src="https://user-images.githubusercontent.com/71784728/231925298-6cd96b4a-4359-4115-b91c-80018743d27a.jpg" height=300 />

</details>
<hr>
<details open>
<summary> <h1>🪛 Electronics Case Assembly</h1> - Click to view electronics case assembly steps </summary>

1. Start by marking and punching the locations of the holes for the Grommets.

2. Drill out each hole to 1/2" size. We use a 1/2" stepped drill bit as we it the best way to get consistent clean holes. 
</details>
<hr>
<details open>
<summary> <h1>🛠️ Structure Assembly</h1> - Click to view structure assembly steps </summary>

</details>

6. ## Operation Instructions

<details open>
<summary><h1>⬇ Arduino Software Install</h1> - Click to view software installation steps</summary>

1. Follow LoomV4 [installation steps](https://github.com/OPEnSLab-OSU/Loom-V4#install).
2. Use Loom4 version committed June 13, 2023 ([63b8fd5](63b8fd5571925c7c8485da7fb281c45754fe824b)) or later by downloading repository and replacing Loom library folder contents at (for Windows) C:\Users\_____\AppData\Local\Arduino15\packages\loom4\hardware\samd\4.3.0\libraries\Loom with repository folder.
3. Clone the LilyPad repo to arduino folder with:
```git clone https://github.com/OPEnSLab-OSU/Lilypad```
4. Move the Adafruit_VEML7700_library_Altered folder to your computer's Arduino libraries folder
5. Install the [OneWire](https://www.arduino.cc/reference/en/libraries/onewire/) (tested with verson 2.7.3) and [DallasTemperature](https://www.arduino.cc/reference/en/libraries/dallastemperature) (tested with version 3.9.0) libraries inside the Arduino IDE [Library Manager](https://www.arduino.cc/en/Guide/Libraries).
6. Modify the ArduinoMqttClient library according to [issue 53](https://github.com/arduino-libraries/ArduinoMqttClient/issues/53): replace != condition with < in [line 213](https://github.com/arduino-libraries/ArduinoMqttClient/blob/03d2faff0520f34a0734e2e7a5588f68bccd1fc5/src/MqttClient.cpp#L213) of ArduinoMqttClient/src/MqttClient.cpp.
</details>
<hr>
<details open>
<summary><h1>📶 LTE Shield Initialization</h1> - Click to view LTE steps - </summary>

1. In the Arduino IDE go to ```File > Examples > Loom > Lab Examples > WC_FastRegister```
2. Change necessary lines and upload code to init LTE board

</details>
<hr>
<details open>
<summary><h1>⬆️ Lilypad Sketch Upload</h1> - Click to view sketch upload instructions</summary>

1. Open ```src/LilyPad4G/LilyPad4G.ino```
2. Create a file called `arduino_secrets.h` in the `LilyPad4G folder
3. Add the following template and fill in the correct values
```cpp
/* arduino_secrets.h */

#define NETWORK_APN "hologram"
#define NETWORK_USER ""
#define NETWORK_PASS ""

#define SECRET_BROKER "put.your.secret.broker.here"
#define SECRET_PORT 1234
#define DATABASE "Database_Name"
#define BROKER_USER "Username"
#define BROKER_PASS "Password"
```
4. Update the COLLECTION_NAME on line 13 to match device e.g. LP1.
5. Verify and upload code

</details>

7. ## Validation and Characterization
