void setup()  // setup loop
{
  pinMode(2, OUTPUT); 
}
void loop()
{
  digitalWrite(2, HIGH); 
  delayMicroseconds(100);   
  digitalWrite(2, LOW); 
  delayMicroseconds(900);
}
