#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>

#define PIN 9
#define PIN2 6

int state = 0;

int numLedsU = 30;
int numLedsL = 20;

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

boolean lastPressedR = false;
boolean lastPressedL = false;

Adafruit_NeoPixel stripU = Adafruit_NeoPixel(numLedsU, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripL = Adafruit_NeoPixel(numLedsL, PIN2, NEO_GRB + NEO_KHZ800);



void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  stripU.begin();
  stripU.setBrightness(40);
  stripU.show();

  stripL.begin();
  stripL.setBrightness(40);
  stripL.show();

  CircuitPlayground.begin();
}

int wait;
int modTime;
uint16_t i, j;

void loop() {
  testState();
  switch(state){
    case 0: 
      Serial.println("Case: Rainbow");
      rainbow(75);
      break;
    case 1: 
      Serial.println("Case: Rainbow Cycle");
      rainbowCycle(15);
      break;
    case 2: 
      Serial.println("Case: Rainbow Chase");
      rainbowChase(50, 100);
      break;
    case 3: 
      Serial.println("Case: Green");
      green(50);
      break;
    case 4: 
      Serial.println("Case: Green");
      green(50);
      break;
    case 5: 
      Serial.println("Case: Green");
      green(50);
      break;
    case 6: 
      Serial.println("Case: Green");
      green(50);
      break;
    case 7: 
      Serial.println("Case: Green");
      green(50);  
      break;
  }


  /************* TEST 10 NEOPIXELS */
//  CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * pixeln));
//  if (pixeln == 11) {
//    pixeln = 0;
//    CircuitPlayground.clearPixels();
//  }

//  /************* TEST LIGHT SENSOR */
//  Serial.print("  Light sensor: ");
//  Serial.print(CircuitPlayground.lightSensor());
//
//  /************* TEST SOUND SENSOR */
//  Serial.print("  Sound sensor: ");
//  Serial.println(CircuitPlayground.mic.soundPressureLevel(10));
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return stripU.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return stripU.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return stripU.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
