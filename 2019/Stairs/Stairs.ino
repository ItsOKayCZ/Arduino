#include <TM1637Display.h>

#define CLK 5
#define DIO 4

TM1637Display disp(CLK, DIO);

int button = A0;

//   -      A
// |   |  F   B
//   -      G
// |   |  E   C
//   -      D

void setup() {
  Serial.begin(9600);
   
  pinMode(button, INPUT);
  
  disp.setBrightness(11);

}

int pos = 0;
int start = 0;
void loop() {

  int read = digitalRead(button);

  if(read == 0 || start == 1){
    start = 1;

    Serial.print("Pos: ");
    Serial.print(pos);
    Serial.print("\n\n");

    uint8_t stairs[4];

    uint8_t temp[] = {
      SEG_D,
      SEG_E | SEG_C | SEG_G,
      SEG_E | SEG_C | SEG_F | SEG_B | SEG_A,
      SEG_E | SEG_C | SEG_G
    };

    int len = sizeof(temp) / sizeof(uint8_t);
    for(int i = 0; i < len; i++){
      
      int index = i + pos;

      if(index >= len){
        index = index - len;
      }
      
      stairs[index] = temp[i];
    }
      
    disp.setSegments(stairs);

    pos++;
    delay(100);

    if(pos > 3){
      pos = 0;
    }
  }

}
