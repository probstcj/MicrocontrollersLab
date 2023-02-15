# Automatic pet feeder

Inspiration: https://www.thingiverse.com/thing:4815584

## 1) Figure out parts
### 4x20 LCD
**Get from:** [Link](https://www.amazon.com/GeeekPi-Interface-Adapter-Backlight-Raspberry/dp/B07QLRD3TM/ref=sr_1_6?crid=2N3E0VL0ZZ0ZM&keywords=4x20+LCD&qid=1676004032&sprefix=4x20+lcd%2Caps%2C206&sr=8-6)
#### Dimensions: 
**Showable LCD (needs to be part of print):**
- L = 97.3 mm
- W = 40.0 mm
- H = 9.5  mm
**Entire Dimensions (including board):**
- L = 98.2 mm
- W = 60.0 mm
- H = 21.0 mm
### Speaker
**Get from:** Steal from lab
### LEDs
**Get from:** Already have
#### Dimensions
**Showable part:**
- Diameter = 4.85 mm
- Height = 7.6 mm
### RTC (Real time clock) I2C interface
**Get from:** [Link](https://www.amazon.com/Module-PCF8563-PCF8563T-Accuracy-1-0-5-5V/dp/B07XRYFV28/ref=sr_1_9?crid=3W2YOTM03L0TT&keywords=rtc+i2c+with+battery&qid=1676004187&sprefix=rtc+i2c+with+battery%2Caps%2C103&sr=8-9)
### Mechanical Encoder (for how much food)
**Get from:** Already have
#### Dimensions
**Turnable part (Will extrude from chasis):**
- Diameter = 6.3 mm
- Diameter with Divet = 5.5 mm
- Height = 12.6 mm
**Threaded part:**
- Diameter = 8.9 mm
- Diameter with Divet = 8 mm
- Height = 6.7 mm
- Thread seperation = 0.75 mm
**Base:**
- L = W = 22.3 mm
- H = 6.95 mm
**Extra info:**
- Pins need clearance at least 4 mm away from width
### UART (either through computer terminal or web app) - setting time
### Motors - Note: figure out which motors to use
**Get from:** [Link](https://www.amazon.com/dp/B00PNEQ79Q?ref_=cm_sw_r_cp_ud_dp_06AX3SA15K4X8A0WRHTR)
#### Dimensions
**Shaft: (Will extrude into auger):**
- Diameter = 5 mm
- Diameter with Divet = 4.5 mm
- Height = 18 mm
- Height of Divet = 16.5 mm
**Box:**
- L = W = 42.2 mm
- H without disk = 20.7 mm
- H with disk = 22.7 mm
- Disk diameter = 21.9 mm
- Screw hole distance = 33.5 mm
**Extra information:**
- Wires protrude from one side, need in design
### Power supply
**Get from:** ARC Lab
Might need to be stripped
### Barrel jack connectors
**Get from:** [Link](https://www.amazon.com/Connector-Barrel-Adapter-Security-Camera/dp/B09S3S6RYC/ref=sr_1_8?crid=2PZ1L6P4J1RU2&keywords=barrel+jack+connector&qid=1676005045&s=electronics&sprefix=barrel+jack+connector%2Celectronics%2C98&sr=1-8)
WRONG PART
### Step-down converter
**Get from:** [Link](https://www.amazon.com/UCTRONICS-Converter-Transformer-Voltage-Regulator/dp/B07XXWQ49N/ref=sr_1_3?crid=LQWHRQYBF6X&keywords=buck+converter+12V+to+5V&qid=1676005201&s=electronics&sprefix=buck+converter+12v+to+5v%2Celectronics%2C91&sr=1-3)
#### Dimensions
**Entire board:**
- L = 63.45 mm
- W = 27.2 mm
- H = 15 mm (roughly)
**Included barrel jack port (if we want to use it):**
- L = 9 mm
- W = 11 mm
- H = 13.4 mm
## 2) Get mechanical parts done, 3d modeling, 3d printing
### Wheel
### Door (might not need motor)
### Hinge
### Enclosure for wiring
### Below wiring enclosure, have enclosure for weights or mounting
### Enclosure for motors and other stuff
### Enclosure for LCD and encoder
### Top for food insertion - threaded
### Container for food insertion - threaded
### Rubber feet for bottom
## 3) Figure out circuitry
### 12V to 5V conversion
### Get LCD to print what we need it to, along with encoder
### Get motors working for door (might not be needed)
### Get motors working for wheel
### Get I2C for RTC working
### Get UART working properly, store values
### Get LED's and Speaker working
## 4) Put everything together
## 5) Get web app working??
