/*
Relé VCC a 5V y GND a 0V.
Entrada relé 1 a pin digital D10
Entrada relé 2 a pin digital D11
*/

int rele = 10;
int rele2 = 11;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(rele2, OUTPUT);
}

void loop() {
  digitalWrite(rele, HIGH);
  digitalWrite(rele2, LOW);
  delay(1000);
  digitalWrite(rele, LOW);
  digitalWrite(rele2, HIGH);
  delay(1000);
}
