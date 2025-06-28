#include<ESP8266WiFi.h>
WiFiClient client;
WiFiServer Server(80);

void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     WiFi.begin("Tantraniketan_4G_EXT","tantraniketan@2024");
     while(WiFi.status()!= WL_CONNECTED)
     {
      Serial.println("..");
      Serial.println("NodeMCU is connected");
      Serial.println(WiFi.localIP());
 
     }
}

void loop() {
  // put your main code here, to run repeatedly:
        client=Server.available();
        if(client==1)
        {
          String request = client.readStringUntil('\n');
          Serial.println(request);
          request.trim();
        }
}
