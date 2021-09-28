int freq = 20000 * 1000; 

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
 delayMicroseconds(lenMicroSecondsOfPulse);
 digitalWrite(4, LOW);
  

}
 
void loop()
{
// analogWrite(13, 55);
// delay(2000);
// analogWrite(13, 0);
// delay(2000);
// analogWrite(13, 255);
// delay(2000);
// analogWrite(13, 0);
// delay(2000);

digitalWrite(4, HIGH);
 delayMicroseconds(0.75 * 1000);
 digitalWrite(4, LOW);
 delay(2000);

 digitalWrite(4, HIGH);
 delayMicroseconds(2.7 * 1000);
 digitalWrite(4, LOW);
 delay(2000);
 

}
