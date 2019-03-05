int soil = A0;
int relay = 5;

void setup() {
  pinMode(soil, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  int val = analogRead(soil);

  if(val > 200){
    digitalWrite(relay, 1);
  } else {
    digitalWrite(relay, 0);
  }

}
