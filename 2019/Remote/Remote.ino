#include <IRremote.h>
#include <TM1637Display.h>

#define DIO 4
#define CLK 5

TM1637Display disp(CLK, DIO);
IRrecv ir(A0);
decode_results result;

void setup() {
  disp.setBrightness(11);
  ir.enableIRIn();

}

void loop() {
  if(ir.decode(&result)){
    

    Serial.println(result.value);
    ir.resume();
  }

}
