#include <Servo.h>

int encode = A0;
int servos = 5;

Servo servo;

int angle = 90;

void setup() {
  pinMode(encode, INPUT);

  servo.attach(servos);
  attachInterrupt(0, start, FALLING);

}

void loop() {}

void start(){
  int real = digitalRead(encode);

  if(real == 1){
    angle -= 30;
  } else {
    angle += 30;
  }

  if(angle >= 180){
    angle = 180;
  } else if(angle <= 0){
    angle = 0;
  }

  servo.write(angle);
}
