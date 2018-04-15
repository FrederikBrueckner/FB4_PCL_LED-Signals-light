/*
  LED Signals light Workshop
  FH Aachen, Physical Computing Lab
  Übung 2: Fade

  Lerninhalte:
  - Wiederholung zu PU01 und PU02
  - chiffrierte Nachricht
  - conditionals: for()

*/

int LED = 9;        // LED über Widerstand 220Ω an PWM fähigen Pin 9 angeschlossen. [PWM = 3, 5, 6, 9, 10]
int brightness = 0; // Helligkeit der LED
int fadeAmount = 1; // Erhöhung pro Zyklus
int lang = 1000;    // 1 Sekunde
int kurz = 250;     // 1/4 Sekunde

void setup() {  // Die Setup Routine läuft ein Mal nach dem Reset Zyklus:
  pinMode(LED, OUTPUT);   // Digital Pin als Ausgang deklarieren.
} // Setup Ende

void loop() { // Die Loop Routine läuft in Dauerschleife:
  digitalWrite(LED, HIGH);  // LED einschalten
  delay(kurz);              // kurz warten
  digitalWrite(LED, LOW);   // LED ausschalten
  delay(lang);              // lang warten
  digitalWrite(LED, HIGH);  // LED einschalten
  delay(kurz);              // kurz warten
  digitalWrite(LED, LOW);   // LED ausschalten
  delay(lang);              // lang warten

  for (brightness = 0; brightness <= 255;)  // Helligkeit mit 0 initialisieren, loop bis Helligkeit 255
  {
    analogWrite(LED, brightness); // LED Ausgang auf Wert "brightness" setzen.
    brightness = brightness + fadeAmount; // Helligkeit jeweils um Wert fadeAmount erhöhen.
    delay(5); // 5 ms warten
  }

  digitalWrite(LED, LOW);   // LED ausschalten
  delay(lang);              // lang warten
} // Loop Ende

