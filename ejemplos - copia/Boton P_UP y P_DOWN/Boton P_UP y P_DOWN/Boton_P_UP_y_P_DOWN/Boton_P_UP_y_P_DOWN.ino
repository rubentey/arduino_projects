// boton P_Down -> D7
// boton P_Up -> D9
// LED -> D12

const int P_Down = 7;
const int P_Up = 9;
const int LED = 12;

int P_Down_act=0;
int P_Up_act=0;
int prev=0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(P_Down, INPUT);
  pinMode(P_Up, INPUT);
}

void loop() {
  P_Down_act=digitalRead(P_Down);
  P_Up_act=digitalRead(P_Up);
  
  if (P_Down_act==HIGH && prev==0) {
    digitalWrite(LED, HIGH);
    prev = 1;
  }
  else if (P_Up_act==HIGH && prev==0) {
    digitalWrite(LED,LOW);
    prev = 0;
  } 
 else if(P_Down_act==LOW && P_Up_act==LOW) {
    prev = 0;
  }
}
