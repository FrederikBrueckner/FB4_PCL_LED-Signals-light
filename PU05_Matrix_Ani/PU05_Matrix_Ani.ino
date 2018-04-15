#include <MD_MAX72xx.h> // Bibliothek MD_AX72XX einbinden
#include <SPI.h>        // Bibliothek SPI einbinden

/*
  LED Signals light Workshop
  FH Aachen, Physical Computing Lab
  Übung 5: Matrix Animation

  Lerninhalte:
  - Wiederholung zu PU_03 und PU_04
  - Variablen: Array

*/

#define MAX_DEVICES 4 // Anzahl MAX7219 in Serie
#define CLK_PIN   16  // oder SCK
#define DATA_PIN  15  // oder MOSI
#define CS_PIN    14  // oder SS
#define rows 32       // Anzahl Matrix Reihen
#define columns 8     // Anzahl Matrix Spalten

MD_MAX72XX mx = MD_MAX72XX(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Gerätekonfiguration, Software SPI Pins

// ========== Anzeige Variablen ===========
const uint8_t data[columns] =
{
  B01000010,
  B10000001,
  B10111101,
  B01011010,
  B01100110,
  B00111100,
  B01100110,
  B10100101
};

const uint8_t data2[columns] =
{
  B00111100,
  B01111110,
  B11111111,
  B11011011,
  B01111110,
  B00111100,
  B01111110,
  B11011011
};

void resetMatrix() { // Matrix Initialisieren
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 4);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  mx.clear();
} // Ende resetMatrix()

void cls() { // Clear screen Funktion
  for (uint8_t i = 0; i < rows; i++)
  {
    mx.setColumn(i, 0); // Alle Pixel ausschalten
  }
} // Ende cls()

void setup() { // Setup Funktion
  mx.begin();
  resetMatrix();
} // Ende setup()

void loop() { // Main loop
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);  // Anzeige Update aus
  cls();

  for (uint8_t i = 0; i < columns; i++)
  {
    mx.setColumn(i, data[i]);
    mx.setColumn(i + 16, data2[i]);
  }

  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);  // Anzeige Update ein
  delay(1000);  // Eine Sekunde warten
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);  // Anzeige Update aus
  cls();

  for (uint8_t i = 0; i < columns; i++)
  {
    mx.setColumn(i + 8, data[i]);
    mx.setColumn(i + 24, data2[i]);
  }

  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);  // Anzeige Update ein
  delay(1000);  // Eine Sekunde warten
} // Ende loop()
