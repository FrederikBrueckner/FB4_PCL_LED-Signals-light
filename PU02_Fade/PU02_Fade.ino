/*
  LED Signals light Workshop
  FH Aachen, Physical Computing Lab
  Übung 2: Fade

  Lerninhalte:
  - PWM
  - conditionals: if()
  - analogWrite()
  - mathematische Operatoren
  - logische Operatoren
  - Ein und Ausblenden einer 20mA LED

*/

int LED = 9;        // LED über Widerstand 220Ω an PWM fähigen Pin 9 angeschlossen. [PWM = 3, 5, 6, 9, 10]
int brightness = 0; // Helligkeit der LED
int fadeAmount = 1; // Erhöhung pro Zyklus

void setup() {  // Die Setup Routine läuft ein Mal nach dem Reset Zyklus:
  pinMode(LED, OUTPUT);   // Digital Pin als Ausgang deklarieren.
}// Setup Ende

void loop() { // Die Loop Routine läuft in Dauerschleife:
  analogWrite(LED, brightness);   // LED Ausgang auf Wert "brightness" setzen.
  brightness = brightness + fadeAmount;   // Helligkeit um Wert fadeAmount erhöhen.

  if (brightness <= 0 || brightness >= 255)   // Falls der Wert die Limits überschreitet...
  {
    // Dimmerrichtung umkehren
    fadeAmount = -fadeAmount;
  }
  delay(5); // 10 ms warten
} // Loop Ende

