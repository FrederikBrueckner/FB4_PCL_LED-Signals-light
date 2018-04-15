/*
  LED Signals light Workshop
  FH Aachen, Physical Computing Lab
  Übung 1: Blink

  Lerninhalte:
  - Einführung Arduino IDE
  - Programm Syntax
  - Variablen, Integer
  - pinMode()
  - digitalWrite()
  - delay()
  - Ansteuern einer 20mA LED

*/

int LED = 2;  // LED über Widerstand 220Ω an Pin 2 angeschlossen.

void setup() {  // Die Setup Routine läuft ein Mal nach dem Reset Zyklus:
  pinMode(LED, OUTPUT); // Digital Pin als Ausgang deklarieren.
} // Setup Ende

void loop() { // Die Loop Routine läuft in Dauerschleife:
  digitalWrite(LED, HIGH);    // LED einschalten (HIGH, 5V auf Pin)
  delay(1000);    // Eine Sekunde warten
  digitalWrite(LED, LOW);   // LED ausschalten (LOW, Pin ist spannungsfrei)
  delay(1000);    // Eine Sekunde warten
} // Loop Ende

