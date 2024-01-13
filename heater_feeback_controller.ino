/* 
MIT License

Copyright (c) 2024, Oregon Health & Science Univeristy

Contributor(s): Jason Ware

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software/firmware and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please consider citing!

 */
 
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MAX31856.h>

#define OLED_RESET 4
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//thermocouple pins
#define TC_SCK 13 // using pin 13 on an arduino uno my cause the onboard LED to flash.
#define TC_SDO 12
#define TC_SDI 11
#define TC_CS 10

int target_temp = 37; // Adjust target temperature here

bool heatON = false;

Adafruit_MAX31856 max = Adafruit_MAX31856(TC_CS, TC_SDI, TC_SDO, TC_SCK);
   			 			

void setup() {
     			 			
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(6,0);
  digitalWrite(5,0);

  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);

  max.begin();
  max.setThermocoupleType(MAX31856_TCTYPE_K); //change thermocouple type if using something other than type K

  //Serial.begin(9600); //uncomment for troubleshooting
}

void loop() {
     			 			
  float temp = max.readThermocoupleTemperature();

  displayThermoTemp(temp, target_temp);

  checkTemp(temp, target_temp);

  //Serial.println(heatON); //uncomment for troubleshooting

  delay(500);
}

void displayTargetTemp(int target_temp) {
     			 			
  display.clearDisplay();
  display.setCursor(0, 5);
  display.print("Target: ");
  display.print(target_temp);
  display.print(" C");
  display.display();
}

void displayThermoTemp(float temp, float target_temp) {
     			 			
  display.clearDisplay();

  display.setCursor(0, 20);
  display.print("Measured: ");
  display.print(temp, 1);
  display.print(" C");

  display.setCursor(0, 5);
  display.print("Target: ");
  display.print(target_temp);
  display.print(" C");
  display.display();
}

void checkTemp(float temp, float target_temp){
     			 			
  if (temp < target_temp){
    digitalWrite(6,HIGH);
    heatON = true;

  }  

  if (temp > target_temp){
    digitalWrite(6,0);
    //digitalWrite(6,0); //if hot ends do not trigger, enable this second digitalWrite line
    heatON = false;

  }  
}  

