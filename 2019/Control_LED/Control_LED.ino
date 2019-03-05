
// Getting the pin numbers
int led = 5;
int button = A0;

void setup() {

  // Setting the pin modes
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {

  int read = digitalRead(button);

  if(read == 0){
    digitalWrite(led, 1);
  } else {
    digitalWrite(led, 0);
  }

}
