/*
 * LED Signals light Workshop
 * Übung 1: Blink
 * 
 * 
 * 
 */
 
int red_led = 2;  // Rote LED über Widerstand 220Ω an Pin 2 angeschlossen.

// Die Setup Routine läuft ein Mal nach dem Reset Zyklus:
void setup() {                
  // Digital Pin als Ausgang deklarieren.
  pinMode(red_led, OUTPUT);
}

// Die Loop Routine läuft in Dauerschleife:
void loop() {
  digitalWrite(red_led, HIGH);   // LED einschalten (HIGH, 5V auf Pin)
  delay(1000);               // Eine Sekunde warten
  digitalWrite(red_led, LOW);    // LED ausschalten (LOW, Pin ist spannungsfrei)
  delay(1000);               // Eine Sekunde warten
}
