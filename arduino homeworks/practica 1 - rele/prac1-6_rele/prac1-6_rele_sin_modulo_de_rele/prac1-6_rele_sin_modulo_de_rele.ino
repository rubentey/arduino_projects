// relé -> D10

int rele = 10;

void setup() {
  pinMode(rele, OUTPUT);
}

void loop() {
  digitalWrite(rele, HIGH);
  delay(1000);
  digitalWrite(rele, LOW);
  delay(1000);
}
