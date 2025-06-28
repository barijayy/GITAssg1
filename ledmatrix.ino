#include <LedControl.h>

// DIN pin 11, CLK pin 13, CS pin 10, 1 device
LedControl lc = LedControl(11, 13, 10, 1);

void setup() {
  lc.shutdown(0, false);     // Wake up the MAX7219
  lc.setIntensity(0, 10);     // Set brightness (0–15)
  lc.clearDisplay(0);        // Clear display

  // Display a smiley face
  byte smiley[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
  };

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, smiley[i]);
  }
}

void loop() {
  // Nothing to do here
}
