#include <MD_MAX72xx.h> // Bibliothek MD_AX72XX einbinden
#include <SPI.h>        // Bibliothek SPI einbinden
#include <NewPing.h>    // Bibliothek NewPing einbinden


/*
  LED Signals light Workshop
  FH Aachen, Physical Computing Lab
  Demo: Matrix mit Ultraschall Entfernungsmesser

*/

#define MAX_DEVICES 4 // Anzahl MAX7219 in Serie
#define CLK_PIN   16  // oder SCK
#define DATA_PIN  15  // oder MOSI
#define CS_PIN    14  // oder SS
#define rows 32       // Anzahl Matrix Reihen
#define columns 8     // Anzahl Matrix Spalten
#define MAX_DISTANCE 100

MD_MAX72XX mx = MD_MAX72XX(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Gerätekonfiguration, Software SPI Pins
NewPing sonar(3, 2, MAX_DISTANCE);  // Ultraschallsensor, Echo Pin 3, Trigger Pin 2

unsigned int sensDist; // Ping Entfernung speichern

// ========== Anzeige Variablen ===========
const uint8_t data[columns] =
{
  B10000001,
  B01100110,
  B00111100,
  B00111100,
  B11011011,
  B01111110,
  B00111100,
  B00011000
};

void resetMatrix(){ // Matrix Initialisieren
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 4);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  mx.clear();
} // Ende resetMatrix()

void cls(){ // Clear screen Funktion
  for (uint8_t i = 0; i < rows; i++)
  {
    mx.setColumn(i, 0);
  }
} // Ende cls()

void setup(){ // Setup Funktion
  mx.begin();
  resetMatrix();
} // Ende setup()

void loop(){  // Main loop

  for (uint8_t k = 0; k < rows; k++)
  {
    mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);  // Anzeige Update aus
    cls();
    
    for (uint8_t i = 0; i < columns; i++)
    {
      mx.setColumn(i + k, data[i]); // 'data[]' in Register schreiben
    }
    
    mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);  // Anzeige Update ein
    sensDist=sonar.ping_cm();
    Serial.println(sensDist);
    delay(map(sensDist, 0, 150, 0, 500));
  }
  
} // Ende loop()
