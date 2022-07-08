/*empieza encendido el motor, pero funciona igual*/
// boton encendido -> D7
// boton apagado -> D8
// relé -> D10

const int btnOn=7;
const int btnOff=8;
int rele = 10;

int btnOn_act=0;
int btnOff_act=0;
int prev=0;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(btnOn_act, INPUT);
  pinMode(btnOff_act, INPUT);
}

void loop() {
  btnOn_act=digitalRead(btnOn);
  btnOff_act=digitalRead(btnOff);
  
  if (btnOn_act==HIGH && prev==0) {
    digitalWrite(rele, HIGH);
    prev = 1;
  }
  else if (btnOff_act==HIGH && prev==0) {
    digitalWrite(rele,LOW);
    prev = 0;
  } 
 else if(btnOn_act==LOW && btnOff_act==LOW) {
    prev = 0;
  }
}
