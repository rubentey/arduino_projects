// botón enciende/apaga -> D7
// relé -> D10

int rele = 10;
const int btnOn = 7;
int val;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(btnOn, INPUT);
}

void loop() {
  val=digitalRead(btnOn);
  if (val==HIGH){
    digitalWrite(rele,HIGH);
  }
  else { digitalWrite(rele,LOW);
  }
}
