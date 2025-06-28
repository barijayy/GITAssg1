#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

// Define hardware type and number of devices (1 matrix = 1 device)
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1  // If you're using only 1 matrix

#define DATA_PIN    11  // DIN
#define CS_PIN      10  // CS/LOAD
#define CLK_PIN     13  // CLK

// Create Parola object
MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  display.begin();
  display.setIntensity(15);        // Brightness: 0 to 15
  display.displayClear();
  display.displayScroll("TANTRANIKETAN", PA_LEFT, PA_SCROLL_LEFT, 100);
}

void loop() {
  if (display.displayAnimate()) {
    display.displayReset();
  }
}
