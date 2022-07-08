// pin central potenciometro -> A0
// se puede comentar el float de arriba, y el del loop, dejando sin comentar el int del loop, para usar el int
// aqui se usa con float y floatMap. se puede usar int y map, pero con map no da decimales

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);
  // Rescale to potentiometer's voltage (from 0V to 5V):
  float voltagefloat = floatMap(analogValue, 0, 1023, 0, 5);
  int voltagemap = map(analogValue, 0, 1023, 0, 5);

  Serial.print("Analog: ");
  Serial.print(analogValue);
  
  // Con floatmap
  Serial.print(", Voltage float: ");
  Serial.print(voltagefloat);
  
  // Con map
  Serial.print(", Voltage map: ");
  Serial.println(voltagemap);
  delay(500);
}
