#include <TM1637Display.h>  
#include <IRremote.h>
#define CLK 4
#define DIO 5

TM1637Display tm(CLK, DIO);
IRrecv ir(A0);
decode_results result;

long codes[13] = {
  0xfd609f, 0xfd08f7, 0xfd8877, 0xfd48b7, 0xfd28d7, 0xfda857, 0xfd6897, 0xfd18e7, 0xfd9867, 0xfd58a7
};

void setup(){
  Serial.begin(9600);
  
  tm.setBrightness(11);
  ir.enableIRIn();
}

void loop(){
  if(ir.decode(&result)){
    int i = -1;
    
    while(!(i>9 || result.value == codes[++i]));
    
    ir.resume();
    
    if(i < 10){
      Serial.print(i);
      Serial.print("\n");
    } else {
      Serial.print("Nothing\n");
    }
  }
}
