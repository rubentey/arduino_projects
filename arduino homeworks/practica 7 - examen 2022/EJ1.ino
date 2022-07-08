int potenciometro;
int almacen;
int almacen1;
const int led = 3;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  potenciometro = analogRead(A0);
  almacen = map(potenciometro, 0, 1023, 0, 255);
  analogWrite(led, almacen);

  almacen1 = map(potenciometro, 0, 1023, 0, 100);
  Serial.println(almacen1);
}
