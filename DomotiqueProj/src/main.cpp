// Include Libraries
#include "Arduino.h"

#include "LiquidCrystal.h"

#include "RunningAverage.h"

#include "RFID.h"


// Pin Definitions
#define LCD_PIN_RS 16
#define LCD_PIN_E 15
#define LCD_PIN_DB4 5
#define LCD_PIN_DB5 4
#define LCD_PIN_DB6 0
#define LCD_PIN_DB7 2
#define LDR_PIN_SIG A0
#define RFID_PIN_RST 9
#define RFID_PIN_SDA 10

// Global variables and defines
RunningAverage MoyGliss(20); // objet "Moyenne Glissante" avec nombre d'échantillons pour le calcul
int compteur = 0; // un compteur d'échantillons
float moyenne = 0; // la moyenne glissante des échantillons

// object initialization
LiquidCrystal lcd(LCD_PIN_RS, LCD_PIN_E, LCD_PIN_DB4, LCD_PIN_DB5, LCD_PIN_DB6, LCD_PIN_DB7);
RFID rfid(RFID_PIN_SDA, RFID_PIN_RST);;

// define vars for testing menu
const int timeout = 10000; //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() {

  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  MoyGliss.clear();
  while (!Serial); // wait for serial port to connect. Needed for native USB
  Serial.println("start");

  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  //initialize RFID module
  rfid.init();

  // set up the LCD's number of columns and rows
  // lcd.begin(16, 2);
  // delay(500);
  // lcd.setCursor(0, 0);
  // lcd.print("start ...");
  // lcd.noDisplay();
  // lcd.display();
  //menuOption = menu();

}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() {
  // lcd.setCursor(0, 0);
  // lcd.print("start ...");
  // lcd.noDisplay();
  // lcd.display();
  // Lecture du capteur
  int echantillon = analogRead(LDR_PIN_SIG);

  // Ajout de l'échantillon à l'objet "Moyenne Glissante"
  MoyGliss.addValue(echantillon);

  // Récupération de la moyenne glissante
  moyenne = MoyGliss.getAverage();

  // Affichage des résultats
  // Serial.print("ECHANTILLON = ");
  // Serial.print(echantillon);
  // Serial.print(",");
  // Serial.print("MOYENNE = ");
  // Serial.println(moyenne);
  // Incrémentation du compteur
  compteur++;
  // Effacement de l'historique pour éviter les débordements
  if (compteur == 300) {
    compteur = 0;
    MoyGliss.clear();
  }

  if ((moyenne < 900)) {
    lcd.setCursor(0, 0);
    lcd.print("Present !");
    // lcd.noDisplay();
    // lcd.display();



    //Read RFID tag if present
    String rfidtag = rfid.readTag();
    //print the tag to serial monitor if one was discovered
    rfid.printTag(rfidtag);
    Serial.println(rfidtag);
    
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Absent !");
    // lcd.noDisplay();
    // lcd.display();

  }

  /*if (millis() - time0 > timeout) {
    menuOption = menu();
  }*/

}