#include <IRremote.h>

IRsend irsend;

const int on_off  = 0;
const int vol_up  = 1;
const int vol_down  = 2;
const int input_sig  = 3;
const int bright_scr  = 4;
const int IR_LED  = 5;

int timer;
int modeCounter = 0;

void wakeUp() {
  timer = 0;
}

void setup() {
  pinMode(on_off, INPUT);
  pinMode(vol_up, INPUT);
  pinMode(vol_down, INPUT);
  pinMode(input_sig, INPUT);
  pinMode(bright_scr, INPUT);
  pinMode(IR_LED, OUTPUT);
}

void loop() {
  attachInterrupt(0, wakeUp, HIGH);
  while (timer < 10000) {
    if (digitalRead(on_off) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x1000C, 20);
    }

    if (digitalRead(vol_up) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x10010, 20);
    }

    if (digitalRead(vol_down) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x10011, 20);
    }

    if (digitalRead(input_sig) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x10038, 20);
    }

    if (digitalRead(bright_scr) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x100F3, 20);
    }
    
    delay(1);
    timer = timer + 1;

  }
}
