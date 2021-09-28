int digital_inputt= 2;
void setup(){
 Serial.begin(9600);
 pinMode(digital_inputt, INPUT);
}
void loop(){
  int val = digitalRead(digital_inputt);
 // send text to the Serial Monitor
 //Serial.println("Hello, world!");
 Serial.print(val);
 // pause for one-half second
 delay(500);
}
