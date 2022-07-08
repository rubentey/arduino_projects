// LED -> D9 (pregresivo ancho pulso)
// pin central potenciometro -> A0

int LED = 9;
int potenciometro = A0;
int salida;
int valueLED;


void setup() {
  pinMode(LED, OUTPUT);
}


void loop() {
  salida = analogRead(potenciometro);
  valueLED = map(salida, 0, 1023, 0, 255);
  analogWrite(LED, valueLED);
  delay(1);
}
