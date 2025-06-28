
int trigPin1 = D6;   
int echoPin1 = D5;
long duration1, cm;
//int red=D3;
//int green= D4;
void setup()
{
 
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  //pinMode(red, OUTPUT);
 // pinMode(green, OUTPUT);
}
 
void loop()
{
  // Pulseting UltraSonic 1 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);

   cm = (duration1/2) *0.0343;     // Divide by 29.1 or multiply by 0.0343
  
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
  
  delay(250);
  
  if(cm>50 && cm< 150)
  {
   //digitalWrite(red, HIGH);
   //digitalWrite(green, LOW);
  }
  else if(cm> 151)
  {
    //digitalWrite(red, LOW);
   //digitalWrite(green, HIGH);
  }
  else
  {
     //digitalWrite(red, LOW);
   //digitalWrite(green, LOW);
  
  }
}
