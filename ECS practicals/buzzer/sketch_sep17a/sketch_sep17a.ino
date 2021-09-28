const int buzzer = 9; //buzzer to arduino pin 9

void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop(){
  tone(buzzer, 20); // Send 1KHz sound signal...
  delay(3000);        // ...for 3 sec
  noTone(buzzer);     // Stop sound...
  delay(10000);        // ...for 10 sec
}
