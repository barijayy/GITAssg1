#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;

long myChannelNumber = 2993290;
const char myWriteAPIKey[] = "B6UTY89X0IXZF60W";

int ir = D6;
void setup() {
  pinMode(ir,INPUT);
  Serial.begin(9600);
  WiFi.begin("Tantraniketan_4G_EXT","tantraniketan@2024");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
 ThingSpeak.begin(client);
}

void loop() {
  ir = digitalRead(D6);
  if(ir==HIGH){
    Serial.println("IR IS HIGH");
  }
  else{
    Serial.println("IR IS low");
  }
  Serial.println("DISTANCE: " + (String) ir);
  ThingSpeak.writeField(myChannelNumber, 1, ir, myWriteAPIKey);
  delay(2000);
}
