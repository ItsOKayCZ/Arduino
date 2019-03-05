int vibrate = A0;
int buzz = 5;

void setup() {

  pinMode(vibrate, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);

}

void loop() {
  int read = digitalRead(vibrate);
  Serial.print(read);

  if(read == 1){
    analogWrite(buzz, 200);
    delay(1000);
    analogWrite(buzz, 0);
  }

}
