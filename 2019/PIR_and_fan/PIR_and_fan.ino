int pir = A0;
int fan = 5;

void setup() {
  pinMode(pir, INPUT);
  pinMode(fan, OUTPUT);

}

void loop() {
  int read = digitalRead(pir);

  if(read == 1){
    digitalWrite(fan, 1);
    delay(500);
    digitalWrite(fan, 0);
  }

}
