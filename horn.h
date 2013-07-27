#include "Arduino.h  // for 1.0 and later

// Horn / Beeper 
void Horn() {
  //tone(pin, frequency, duration)  
  tone(HornPort, 262, 1500);
  // Frequency 262 = C4
}

