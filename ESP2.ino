#include <ESP8266WiFi.h>
#include <Servo.h>
WiFiClient client;
WiFiServer server(80);
Servo s1;
int redled = D5;
int greenled = D6;
int motor = D4;
int yellowled = D7;

void setup() 
{
  Serial.begin(9600);
  WiFi.begin("Tantraniketan_4G_EXT", "tantraniketan@2024");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
 
  pinMode(yellowled, OUTPUT);
  s1.attach(D4);
}

void loop() 
{
 
  client = server.available();  
  if (client == 1)
  {
        String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /redledon HTTP/1.1")
    {
      digitalWrite(redled, HIGH);
    }
    if(request == "GET /redledoff HTTP/1.1")
    {
      digitalWrite(redled, LOW);
    }
    if(request == "GET /greenledon HTTP/1.1")
    {
      digitalWrite(greenled, HIGH);
    }
    if(request == "GET /greenledoff HTTP/1.1")
    {
      digitalWrite(greenled, LOW);
    }
    if(request == "GET /motoron HTTP/1.1")
    {
      s1.write(30);
    }
    if(request == "GET /motoroff HTTP/1.1")
    {
      s1.write(180);
    }
    if(request == "GET /yellowledon HTTP/1.1")
    {
      digitalWrite(yellowled, HIGH);
    }
    if(request == "GET /yellowledoff HTTP/1.1")
    {
      digitalWrite(yellowled, LOW);
    }
    if(request == "GET /allledon HTTP/1.1")
    {
      digitalWrite(yellowled, HIGH);
      digitalWrite(redled, HIGH);
      digitalWrite(greenled, HIGH);
    }
    if(request == "GET /allledoff HTTP/1.1")
    {
      digitalWrite(yellowled, LOW);
      digitalWrite(redled, LOW);
      digitalWrite(greenled, LOW);
    }
  }
  }
