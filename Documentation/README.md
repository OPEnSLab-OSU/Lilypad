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

1. ## Hardware in Context

Without deploying a whole weather station to a lake how are you supposed to know the rate of water loss? The Lilypad hopes to give water shed management groups and researchers alike the ability to monitor the rate of water loss. This is critical for allocating resources appropriately to prevent excess water loss due to evaporation. Deploying shade balls or other measures is costly and providing data on where they are most needed can help conserve the most valuable resource we have, fresh water.

Using our current sensor suite is not a traditional ways of measuring water loss. [LGSONIC](https://www.lgsonic.com/products/monitoring-buoy/) sells a floating water quality monitoring suite that can have additional sensors added to measure water loss. The other option is to build a weather station and measure local conditions to model water loss.

2. ## Hardware Description

The Lilypad is a floating platform for long term water sensing. Using three thick acrylic panels the Lilypad captures two buoys, a solar panel and electronics box. Leaving mounting points for sensors, counterweights, and deployment. Using laser cutting to capture, orient, and provide structure to the components of the buoy allows us to cut costs significantly. 

3. ## Design Files Summary

4. ## Bill of Materials Summary

| Component Type | Item Description | Quantity Per Unit | Dist. Website | Notes | Material Cost | Per Unit Cost |
| :--- | :--- | ---: | :--- | :--- | ---: | ---: |
|	Electrical	|	Feather M0	|	1	|	[Adafruit](https://www.adafruit.com/product/2772)	|	2772	|	19.95	|	19.95	|
|	Electrical	|	Hypnos v3.2	|	1	|	[OPEnS GitHub](https://github.com/OPEnSLab-OSU/OPEnS-Hypnos/tree/master/Hypnos%20V3.2)	|	In-house Part	|	35	|	35	|
|	Electrical	|	Coin cell battery	|		|	[Mouser](https://www.mouser.com/ProductDetail/Panasonic-Battery/CR1220?qs=1eQvB6Dk1vgkC%252Bd1qU6JFA%3D%3D)	|		|	1.13	|	1.13	|
|	Electrical	|	microSD card	|		|	[Amazon](https://www.amazon.com/SanDisk-microSDHC-Standard-Packaging-SDSQUNC-032G-GN6MA/dp/B010Q57T02/ref=sr_1_5?crid=7X1LCHLGXSMK&keywords=SanDisk+32GB+Ultra+microSDHC&qid=1690476358&s=electronics&sprefix=sandisk+32gb+ultra+microsdhc%2Celectronics%2C192&sr=1-5)	|		|	8.49	|	8.49	|
|	Electrical	|	SparkFun SARA-R4	|	1	|	[SparkFun](https://www.sparkfun.com/products/14997)	|		|	90.95	|	90.95	|
|	Electrical	|	SHT31	|	1	|	[DF Robot](https://www.dfrobot.com/product-2160.html)	|		|	19.9	|	19.9	|
|	Electrical	|	DS18B20	|	1	|	[Adafruit](https://www.adafruit.com/product/381)	|	381	|	9.95	|	9.95	|
|	Electrical	|	Right Angle VEML7700 Lux Sensor	|	1	|	[Adafruit](https://www.adafruit.com/product/5378)	|	5378	|	4.95	|	4.95	|
|	Electrical	|	4 wire cable	|	1	|	[Amazon](https://www.amazon.com/Conductor-Electrical-Stranded-Extension-Automotive/dp/B0BVYXPMM4/ref=sr_1_6?crid=RZDPPX77JVVJ&keywords=4%2BConductor%2BElectrical%2BWire%2B22awg&qid=1682638333&s=industrial&sprefix=4%2Bconductor%2Belectrical%2Bwire%2B22awg%2Cindustrial%2C143&sr=1-6&th=1)	|		|	18.49	|	18.49	|
|	Electrical	|	6W 6V Solar Panel	|	1	|	[VoltaicSystems](https://voltaicsystems.com/6-watt-panel/)	|	1525	|	59	|	59	|
|	Electrical	|	10050mAh Battery	|	1	|	[Adafruit](https://www.adafruit.com/product/5035)	|	5035	|	29.98	|	29.98	|
|	Electrical	|	Thermister	|	1	|	[Adafruit](https://www.adafruit.com/product/372)	|	372	|	4	|	4	|
|	Electrical	|	Heat shrink	|	1	|	[Amazon](https://www.amazon.com/gp/product/B084GDLSCK/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)	|		|	13.99	|	13.99	|
|		|		|		|		|		|		|		|
|	PCB	|	LilyPadv2 Motherboard	|	1	|	[OPEnS Github](https://github.com/OPEnSLab-OSU/Lilypad/blob/main/PCB/LP_MotherBoard_v1/lilypad_V2.brd)	|		|		|	21.82	|
|	PCB	|	Green LED	|	1	|	[Mouser](https://www.mouser.com/ProductDetail/Lite-On/LTST-C191KGKT?qs=xSPZu9B1aMCRQ5ACasEYAg%3D%3D)	|	indicator, 160-1446-1-ND	|	0.26	|	0.26	|
|	PCB	|	Red LED	|	1	|	[Mouser](https://www.mouser.com/ProductDetail/Lite-On/LTST-C191KRKT?qs=BAIUz4Y8PJBLfOhzue0q%252BA%3D%3D)	|	indicator, 160-1447-1-ND	|	0.26	|	0.26	|
|	PCB	|	D2 (SK34A)	|	1	|	[Mouser](https://www.mouser.com/ProductDetail/Micro-Commercial-Components-MCC/SK34AFL-TP?qs=%2F9jDaHz9Z2hx3laGbsEE%252BA%3D%3D)	|	SK34AFL-TP 	|	0.48	|	0.48	|
|	PCB	|	C5, C6: CAP CER 10UF 16V X5R 0805	|	2	|	[Mouser](https://www.mouser.com/ProductDetail/Taiyo-Yuden/TMK212BBJ106KG8T?qs=sGAEpiMZZMsh%252B1woXyUXj30ZYomYlxpXTwdB%2FyRwYV8%3D)	|	1276-1096-1-ND	|	0.32	|	0.64	|
|	PCB	|	X4: BQ24074 IC BATT CHG LI-ION 1CELL 16QFN	|	1	|	[Mouser](https://www.mouser.com/ProductDetail/Texas-Instruments/BQ24074RGTT?qs=ZV%2Fxhq4oszp0gb4MsbpFYw%3D%3D)	|	lipo charging	|	4.38	|	4.38	|
|	PCB	|	R2, R7, R8, R11: RES 10K OHM 5% 1/8W 0805	|	4	|	[Mouser](https://www.mouser.com/ProductDetail/TE-Connectivity-Holsworthy/1623097-1?qs=sGAEpiMZZMtlubZbdhIBIGSmJ%2FJbdf4CFnz30yzDuYI%3D)	|	311-10KARCT-ND	|	0.21	|	0.84	|
|	PCB	|	R1, R9: RES 1K OHM 1% 1/4W 0805	|	2	|	[Mouser](https://www.mouser.com/ProductDetail/TE-Connectivity-Holsworthy/1-2176092-8?qs=sGAEpiMZZMtlubZbdhIBIP78WyDTHQZBYHcwkrM3rIc%3D)	|	1-2176092-8; RNCP0805FTD1K00CT-ND	|	0.63	|	1.26	|
|	PCB	|	R12: RES 4.7K OHM 1% 1/8W 0805	|	1	|	[Mouser](https://www.mouser.com/ProductDetail/Bourns/CR0805-FX-4701ELF?qs=sGAEpiMZZMtlubZbdhIBIDEmHCAUH0R0BIFSm%252BPNBkg%3D)	|	DS18B20 Pullup, 13-RC0805FR-134K7LCT-ND	|	0.1	|	0.1	|
|	PCB	|	JST 2-Pin	|	1	|	[Adafruit](https://www.adafruit.com/product/1769)	|	battery connector	|	0.75	|	0.75	|
|	PCB	|	Switch	|	1	|	[Adafruit](https://www.adafruit.com/product/805)	|		|	0.95	|	0.95	|
|	PCB	|	Headers Swiss Pack (Male)	|	1	|	[Adafruit](https://www.adafruit.com/product/3647)	|		|	5.95	|	5.95	|
|	PCB	|	Headers Swiss Pack (Female)	|	1	|	[Adafruit](https://www.adafruit.com/product/3646)	|		|	5.95	|	5.95	|
|	PCB	|	2 pin screw terminal	|	2	|	[Mouser](https://www.mouser.com/ProductDetail/651-1725656)	|	1725656	|	1.94	|	3.88	|
|	PCB	|	3 pin screw terminal	|	1	|	[Mouser](https://www.mouser.com/ProductDetail/651-1725669)	|	1725669	|	2.89	|	2.89	|
|	PCB	|	4 pin screw terminal	|	2	|	[Mouser](https://www.mouser.com/ProductDetail/651-1725672)	|	1725672	|	3.85	|	7.7	|
|		|		|		|		|		|		|		|
|	Mechanical	|	Pelican 1030 Micro	|	1	|	[Pelican](https://www.pelican.com/us/en/product/cases/micro/1030)	|		|	22.5	|	22.5	|
|	Mechanical	|	EPDM Foam Cord	|	1	|	[McMasterCarr](https://www.mcmaster.com/4339T6/)	|	ID(1/4") OD(3/4")	|	17.1	|	17.1	|
|	Mechanical	|	Acrylic - 1/4" food safe	|	1	|	[McMaster](https://www.mcmaster.com/8560K593/)	|	8560K593, 8 mm	|	30.37	|	30.37	|
|	Mechanical	|	Acrylic - 1/8"	|	1	|	[McMaster](https://www.mcmaster.com/8505K741-8505K117/)	|	8505K741-8505K117, 3 mm	|	7.71	|	7.71	|
|	Mechanical	|	M2.5 x 8 mm bolts	|	2	|	[McMaster](https://www.mcmaster.com/92290A058/)	|	92290A058	|	3.76	|	0.3008	|
|	Mechanical	|	M2.5 nuts	|	2	|	[McMaster](https://www.mcmaster.com/94150A310/)	|	94150A310	|	5.74	|	0.2296	|
|	Mechanical	|	M4 x 10 bolts	|	4	|	[McMaster](https://www.mcmaster.com/92290A144/)	|	92290A144	|	16.34	|	1.3072	|
|	Mechanical	|	M4 nuts	|	4	|	[McMaster](https://www.mcmaster.com/94150A335/)	|	94150A335	|	4.68	|	0.3744	|
|	Mechanical	|	PG7 cable glands	|	4	|	[Mouser](https://www.mouser.com/ProductDetail/546-1427NCGPG7B)	|	1427NCGPG7B	|	1.52	|	6.08	|
|	Mechanical	|	Clear RTV Silicone Adhesive Sealant	|	1	|	[Amazon](https://www.amazon.com/gp/product/B0002UEPVI/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)	|		|	5.98	|	5.98	|
|	Mechanical	|	Silicone grease	|	1	|	[Grainger](https://www.grainger.com/product/SUPER-LUBE-Multipurpose-Grease-White-45NA53)	|	Item 45NA53	|	0.8	|	0.8	|
|	Mechanical	|	Stepped drill bit for PG7	|	1	|	[McMaster](https://www.mcmaster.com/8841A21/)	|	8841A21	|	21.85	|	-	|
|	Mechanical	|	HDPE bottles	|	2	|	[VWR](https://us.vwr.com/store/product/4589610/vwr-laboratory-bottles-high-density-polyethylene)	|	ChemStores ABB500, VWR 414004-158	|	7.255	|	14.51	|

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
