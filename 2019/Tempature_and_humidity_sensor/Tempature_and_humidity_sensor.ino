// Including the libraries
#include "DHT.h"
#include <TM1637Display.h>

// Defining the CLK and DIO ports
#define CLK 4
#define DIO 5

// Making the instance of the display and the sensor
TM1637Display disp(CLK, DIO);
DHT dht(A0, DHT11);

//   -      A
// |   |  F   B
//   -      G
// |   |  E   C
//   -      D
const uint8_t temp = SEG_A | SEG_F | SEG_E | SEG_D;         // C
const uint8_t humi = SEG_F | SEG_B | SEG_G | SEG_E | SEG_C; // H
const uint8_t circle = SEG_A | SEG_F | SEG_G | SEG_B;

uint8_t output[4];

void setup() {
  Serial.begin(9600);

  // Setting up the sensor
  dht.begin();
  
  // Setting the brightness (8-15)
  disp.setBrightness(11);
}

void loop() {

  reset(temp);

  int t = dht.readTemperature();
  output[0] = disp.encodeDigit(t / 10);
  output[1] = disp.encodeDigit(t % 10);
//  Serial.println(t);
  
  disp.setSegments(output);
  delay(2000);

  reset(humi);
  
  int h = dht.readHumidity();
  output[0] = disp.encodeDigit(h / 10);
  output[1] = disp.encodeDigit(h % 10);

  disp.setSegments(output);
  delay(2000);

//  Serial.println(h);
}

void reset(uint8_t type){
  output[0] = output[1] = 0;
  output[2] = circle;
  output[3] = type;
}
