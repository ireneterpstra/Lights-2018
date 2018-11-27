#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);

void setup() {

  
  strip.begin();
  strip.show();

//  stripL.begin();
//  stripL.setBrightness(40);
//  stripL.show();

  CircuitPlayground.begin();
}

void loop() {
  uint16_t i, j;

  
  int modTime = (millis()/40)%256;
  //Serial.println("Time" + String(modTime));

  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel((i*1+modTime) & 255));
  }
  for(i=0; i<10; i++) {
    CircuitPlayground.setPixelColor(i, Wheel((i*1+modTime) & 255));
  }
  strip.show();
//
//  if (modTime > 250){
//    Serial.println("High");
//    digitalWrite(9, HIGH);
//  } else {
//    Serial.println("Low");
//
//    digitalWrite(9, LOW);
//  }
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
