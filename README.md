# heater_feedback_controller
Overview:
This directory contains code and instructions for creating a unidirectional feedback loop too control heating units. Set a temperature in the program and the controller will trigger heating modules until the desired temperature is reached. The original application of this setup was to keep a ~40 L enclosed chamber at a constant 37C. The program does not account for cooling, and will trigger the heating modules if the temperature falls below the set threshold.

---------------------------------Caution--------------------------------------
                          RISK OF BURNS OR FIRE
      Hot ends will reach temperatures far beyond the desired temperature. 
Risk of severe burns or damage to equipment may occur on contact with hotends!
    Contributors are not responsible for any injury or damage caused by the 
                use of this software, hardware or firmware.
------------------------------------------------------------------------------

Required Hardware:
Following is a list of the models of hardware used in the original implementation of this program:
- Microcontroller: Arduino Uno R3
- Thermocouple module: MAX31856
- Thermocouple: type k
- Display: SSD1306
- Transistor: N-channel MOSFET (5V, 1.5A)
- Heaters: 24V, 40W Ceramic Hotends (3D printer replacement parts), used 4 probes to heat a ~40L Chamber. Using multiple probes is prefered for even heating and reducing overload on single heating modules.
- Power supply: 120V AC to 9V, 2A DC converter

Dependencies:
Programming performed using Arduino  IDE v2.2.1)
  Arduino Libraries (version used):
  - Wire.h (Installed with arduino IDE 2.2.1)
  - Adafruit_SSD1306.h (v2.5.7)
  - Adafruit_MAX31856.h (v1.2.5)
