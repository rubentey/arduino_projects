void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando!");
}

void loop() {
  Serial.print("Texto en loop\t");
  Serial.println("loop");
  delay(500);
}
