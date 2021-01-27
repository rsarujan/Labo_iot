
// Include Libraries
#include "Arduino.h"
#include "DHT.h"
#include "LiquidCrystal.h"
#include "LED.h"
#include "PiezoSpeaker.h"


// Pin Definitions
#define DHT_PIN_DATA	5
#define LCD_PIN_RS	16
#define LCD_PIN_E	15
#define LCD_PIN_DB4	0
#define LCD_PIN_DB5	2
#define LCD_PIN_DB6	12
#define LCD_PIN_DB7	13
#define LEDY_PIN_VIN	4
#define PIRMINI_PIN_DQ	9
#define PIEZOSPEAKER_3V3_PIN_SIG	14



// Global variables and defines
unsigned int piezoSpeaker_3v3HoorayLength          = 6;                                                      // amount of notes in melody
unsigned int piezoSpeaker_3v3HoorayMelody[]        = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5}; // list of notes. List length must match HoorayLength!
unsigned int piezoSpeaker_3v3HoorayNoteDurations[] = {8      , 8      , 8      , 4      , 8      , 4      }; // note durations; 4 = quarter note, 8 = eighth note, etc. List length must match HoorayLength!
// object initialization
DHT dht(DHT_PIN_DATA);
LiquidCrystal lcd(LCD_PIN_RS,LCD_PIN_E,LCD_PIN_DB4,LCD_PIN_DB5,LCD_PIN_DB6,LCD_PIN_DB7);
LED ledY(LEDY_PIN_VIN);
PiezoSpeaker piezoSpeaker_3v3(PIEZOSPEAKER_3V3_PIN_SIG);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    dht.begin();
    // set up the LCD's number of columns and rows
    lcd.begin(16, 2);
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // DHT22/11 Humidity and Temperature Sensor - Test Code
    // Reading humidity in %
    float dhtHumidity = dht.readHumidity();
    // Read temperature in Celsius, for Fahrenheit use .readTempF()
    float dhtTempC = dht.readTempC();
    Serial.print(F("Humidity: ")); Serial.print(dhtHumidity); Serial.print(F(" [%]\t"));
    Serial.print(F("Temp: ")); Serial.print(dhtTempC); Serial.println(F(" [C]"));

    }
    else if(menuOption == '2') {
    // LCD 16x2 - Test Code
    // Print a message to the LCD.
    lcd.setCursor(0, 0);
    lcd.print("Circuito Rocks !");
    // Turn off the display:
    lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    }
    else if(menuOption == '3') {
    // LED - Basic Yellow 5mm - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
    ledY.dim(i);                      // 1. Dim Led 
    delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledY.off();                        // 3. turns off
    }
    else if(menuOption == '4')
    {
    // Disclaimer: The Mini PIR - HC-SR505 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '5') {
    // Piezo Speaker - Test Code
    // The Speaker will play the Hooray tune
    piezoSpeaker_3v3.playMelody(piezoSpeaker_3v3HoorayLength, piezoSpeaker_3v3HoorayMelody, piezoSpeaker_3v3HoorayNoteDurations); 
    delay(500);   
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) DHT22/11 Humidity and Temperature Sensor"));
    Serial.println(F("(2) LCD 16x2"));
    Serial.println(F("(3) LED - Basic Yellow 5mm"));
    Serial.println(F("(4) Mini PIR - HC-SR505"));
    Serial.println(F("(5) Piezo Speaker"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing DHT22/11 Humidity and Temperature Sensor"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing LCD 16x2"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing LED - Basic Yellow 5mm"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing Mini PIR - HC-SR505 - note that this component doesn't have a test code"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing Piezo Speaker"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/