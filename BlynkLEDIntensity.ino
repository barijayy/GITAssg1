#define BLYNK_TEMPLATE_ID "TMPL3PP9aR7po"
#define BLYNK_TEMPLATE_NAME "ESP LED"
#define BLYNK_AUTH_TOKEN "k6IR3mklOJk636zKylMP-gp1-lbtuqfW"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LedControl.h>

// Matrix: DIN=D6, CLK=D3, CS=D4
LedControl lc = LedControl(D6, D3, D4, 1);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Tantraniketan_4G_EXT";
char pass[] = "tantraniketan@2024";

// Smiley face pattern
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

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  pinMode(D5, OUTPUT);
  pinMode(D7, OUTPUT);

  lc.shutdown(0, false);   // Wake up matrix
  lc.setIntensity(0, 8);   // Default brightness
  lc.clearDisplay(0);      // Clear matrix
}

// LED control on D5
BLYNK_WRITE(V0) {
  digitalWrite(D5, param.asInt());
}

// LED control on D7
BLYNK_WRITE(V1) {
  digitalWrite(D7, param.asInt());
}

// Matrix ON/OFF control
BLYNK_WRITE(V2) {
  int state = param.asInt();
  if (state == 1) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, smiley[i]);
    }
  } else {
    lc.clearDisplay(0);
  }
}

// Matrix brightness control (0–15)
BLYNK_WRITE(V3) {
  int brightness = param.asInt(); // Get slider value
  lc.setIntensity(0, brightness); // Set matrix brightness
  Serial.print("Brightness set to: ");
  Serial.println(brightness);
}

void loop() {
  Blynk.run();
}
