// pin central potenciometro -> A0
// servomotor -> D10

#include <Servo.h>
Servo myServo;

int valuePot = 0;
int valueServo = 0;

void setup() {
  myServo.attach(10);
}

void loop() {
  int analogValue = analogRead(A0);
  
  int valuePot = map(analogValue, 0, 1023, 0, 3);

    if (valuePot < 1) {
      myServo.write(90);
    }else if (valuePot < 2){
        for (valueServo = 0; valueServo <= 180; valueServo += 1) {
            myServo.write(valueServo);
            delay(15);
            }
        for (valueServo = 180; valueServo >= 0; valueServo -= 1) {
            myServo.write(valueServo);
            delay(15);
            }
    }else{
      myServo.write(45); 
    }
}
