int diode = A0;
int fan = 5;

void setup() {
  pinMode(diode, INPUT);
  pinMode(fan, OUTPUT);
}

void loop() {
  int speed = analogRead(diode) * 2;
  analogWrite(fan, speed);

}
