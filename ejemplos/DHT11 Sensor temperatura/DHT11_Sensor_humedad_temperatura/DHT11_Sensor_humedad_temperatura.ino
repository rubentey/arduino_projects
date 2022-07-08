// sensor temperatura / humedad -> A0
// LED enciende temp baja -> D6

#include "DHT.h"
#define DHTTYPE DHT11
const int DHTpin = A0;
DHT dht(DHTpin, DHTTYPE);
const int led = 6;

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  if (t < 22){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}
