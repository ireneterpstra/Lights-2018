/* Pulse Sensor Amped with NeoPixels

Pulse an arbitrary number of Adafruit NeoPixels based on a heartbeat sensor

The pulsesensor.com code needs to be in module interrupt.ino in the sketch directory
   http://pulsesensor.com/pages/pulse-sensor-amped-arduino-v1dot1
Code also uses the Adafruit NeoPixel library code discussed at
   https://learn.adafruit.com/adafruit-neopixel-uberguide

Version 1.0 by Mike Barela for Adafruit Industries, Fall 2015 
*/
#include <Adafruit_NeoPixel.h>    // Library containing 

// Behavior setting variables
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // Digital pin to blink led at each beat
int fadePin  = 5;                 // pin to do fancy neopixel effects at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin

// these variables are volatile because they are used during the interrupt service routine
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, the Inter-Beat Interval
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// Set up use of NeoPixels
const int NUMPIXELS = 24;           // Put the number of NeoPixels you are using here
const int BRIGHTNESS = 60;          // Set brightness of NeoPixels here

const int lightPin1 = 6;
const int lightPin2 = 5;
const int numLeds = 30;
const int numLeds2 = 20;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, lightPin1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(numLeds2, lightPin2, NEO_GRB + NEO_KHZ800);

void setup(){
  pinMode(blinkPin,OUTPUT);         // pin that will blink to your heartbeat!
  Serial.begin(115200);           // Serial output data for debugging or external use
  strip.begin();
  strip.setBrightness(40); // 1/3 brightness
  strip2.begin();
  strip2.setBrightness(40); // 1/3 brightness

  strip.show(); // Initialize all pixels to 'off'
  strip2.show(); // Initialize all pixels to 'off'
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
}

void loop(){
  sendDataSerial();       // send heart rate with a 'B' prefix
  uint16_t i;

  int modifiedBPM = BPM*5;

  
//  if (QS == true){                    // Quantified Self flag is true when arduino finds a heartbeat
//    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i*1+modifiedBPM) & 255));
//      strip2.setPixelColor(i, Wheel((i*1+modifiedBPM) & 255));
//    }
//     QS = false;                      // reset the Quantified Self flag for next time    
//  } else{
//    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, 0, 0, 0);
//      strip2.setPixelColor(i, 0, 0, 0);
//    }
//  }
//  strip.show();
//  strip2.show();

  if (QS == true){                    // Quantified Self flag is true when arduino finds a heartbeat
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((modifiedBPM) & 255));
      strip2.setPixelColor(i, Wheel((modifiedBPM) & 255));
    }
    QS = false;                      // reset the Quantified Self flag for next time    
  }
  colorFade(0, 0, 0, 10);             
  //delay(20);                          //  take a break
  
}

void ledFadeToBeat() {
    fadeRate -= 15;                         // Set LED fade value
    fadeRate = constrain(fadeRate,0,255);   // Keep LED fade value from going into negative numbers
    setStrip(fadeRate);                     // Write the value to the NeoPixels 
//    sendDataSerial('R',fadeRate);
}
 
void setStrip(int r) {     // Set the strip to one color intensity (red)
   int g = 0;              // Green is set to zero (for non-red colors, change this)
   int b = 0;              // Blue is set to zero (for non-red colors, change this)
   for (int x=0; x < numLeds; x++) {
      strip.setPixelColor(x, strip.Color(r, g, b));
      strip2.setPixelColor(x, strip.Color(r, g, b));
   }
   strip.show();
   strip2.show();
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

void sendDataSerial() {

  Serial.print(BPM);
  Serial.print(" ");
  Serial.print(IBI);
  Serial.print(" ");
  Serial.println(Signal);

//    Serial.print(symbol);                // symbol prefix tells Processing what type of data is coming
//    Serial.println(data);                // the data to send culminating in a carriage return
}

