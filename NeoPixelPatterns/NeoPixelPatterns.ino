#include <Adafruit_NeoPixel.h>

#define PIN 6
const int buttonPin = 12; 

const int numLeds = 30;
const int delayTime = 100;

int count;
boolean up;

double loopCount = 0;

boolean lastPressed = false;

int buttonCount = 0;

#define NUMBER_OF_FLAMES 5 // depends on number of neopixel triplets. 5 for 16 NeoPixel ring. 4 for 12 NeoPixel ring
#define FLAME_WIDTH 3      // How wide are the flames (in LEDs)
#define FLICKER_CHANCE 3 

int buttonState = 0;         // variable for reading the pushbutton status
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);
    

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(40); // 1/3 brightness

  strip.show(); // Initialize all pixels to 'off'

}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && !lastPressed) {
    lastPressed = true;
    buttonCount ++;
    //Serial.println("Plus Button : " + String(buttonCount));
  } else if (buttonState == LOW){
    lastPressed = false;
  }

  if (buttonCount == 0){
    rainbow(75);
    
    //delay(5);
  } else if (buttonCount == 1){
    theaterChaseRainbow(50, 100);
  } else if (buttonCount == 2){
    rainbowCycle(15);
    //FadeInOut(0xff, 0x77, 0x00);
  } else if (buttonCount == 3){
    RunningLights(255, 255, 255, 100);
  } else if (buttonCount == 4){
    RunningLights(178, 34, 34, 100);
  } else if (buttonCount == 5){
    RunningLights(176, 64, 237, 100);
  } else if (buttonCount == 6){
    RunningLights(234, 117, 75, 100);
  } else if (buttonCount == 7){
    RunningLights(75, 234, 135, 150);
  } else if (buttonCount == 8){
    RunningLights(237, 213, 0, 150);
  } else if (buttonCount == 9){
    meteorRain(161, 0, 237, 10, 64, true, 30);
  } else if (buttonCount == 10){
    meteorRain(102, 204, 255, 10, 80, true, 30);
  } else if (buttonCount == 11){
    meteorRain(51, 255, 51, 10, 100, true, 30);
  } else if (buttonCount == 12){
    meteorRain(255, 92, 51, 10, 150, true, 30);
  } else if (buttonCount == 13){
    Sparkle(255, 255, 26, 10, 10);
  } else if (buttonCount == 14){
    Sparkle(255, 153, 255, 10, 10);
  } else if (buttonCount == 15){
    Sparkle(0, 255, 153, 10, 10);
  } else if (buttonCount == 16){
    SparkleRainbow(10, 10);
  } else{
    buttonCount = 0;
  }
  //Serial.println("button count = " + String(buttonCount));
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
