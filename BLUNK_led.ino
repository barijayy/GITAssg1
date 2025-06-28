#define BLYNK_TEMPLATE_ID "TMPL3PP9aR7po"
#define BLYNK_TEMPLATE_NAME "ESP LED"
#define BLYNK_AUTH_TOKEN "k6IR3mklOJk636zKylMP-gp1-lbtuqfW"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "k6IR3mklOJk636zKylMP-gp1-lbtuqfW" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Tantraniketan_4G_EXT";//Enter your WIFI name
char pass[] = "tantraniketan@2024";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D5, param.asInt());
}
BLYNK_WRITE(V1) {
  digitalWrite(D7, param.asInt());
}
void setup() {
  //Set the LED pin as an output pin
  pinMode(D5, OUTPUT);
  pinMode(D7, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
