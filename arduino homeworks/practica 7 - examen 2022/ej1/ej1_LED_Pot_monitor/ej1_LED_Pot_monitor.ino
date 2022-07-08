// pin central potenciometro -> A0
// pin LED -> D3

#include <SPI.h>
#include <Wire.h>

int LED = 3;
int valueLED;
int valuePercent;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando!");
  pinMode(LED, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  int percent = map(analogValue, 0, 1023, 0, 100);
  int valueLED = map(analogValue, 0, 1023, 0, 255);

  analogWrite(LED, valueLED);
  
  Serial.print(percent);
  Serial.println("%");
  delay(50);
}
