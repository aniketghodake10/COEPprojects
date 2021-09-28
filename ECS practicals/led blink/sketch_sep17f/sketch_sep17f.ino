int pinn= 13;
void setup() {
  pinMode(pinn, OUTPUT);
}
void loop() {
  digitalWrite(pinn,HIGH); // White
  delay(10000);
  digitalWrite(pinn,LOW); // White
  delay(10000);
}
