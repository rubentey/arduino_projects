// LED -> D9  (progresivo ancho pulso)

int LED = 9;

void setup() {
  pinMode(LED,OUTPUT);
}

void loop() {
  for(int i=0; i<255; i++){
      analogWrite(LED, i);
      delay(5);
    }
  for(int i=255; i>0; i--){
      analogWrite(LED, i);
      delay(5);
    }
}
