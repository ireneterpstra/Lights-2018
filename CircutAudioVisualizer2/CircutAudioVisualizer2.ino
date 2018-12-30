#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

double soundPressure; 
int soundColor;

uint16_t volGradient = 0; 

double volume = 0;
double last = 0;
double maxVol = 10;
double minVol = 50;
double avgVol = 0;
double avgBump = 0;

boolean bump = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 5, NEO_GRB + NEO_KHZ800);


void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
}


void loop() {
  delay(10);

  volume = CircuitPlayground.mic.soundPressureLevel(10);
  avgVol = (avgVol*.95 + volume*.05);

  if (volume < avgVol / 2.0 || volume < 15) { // silent if vol is less that 1/2 avrg vol
    volume = 0; 
  }
  
  if (volume > maxVol) {
    maxVol = volume;
  }
  if (volume < minVol){
    minVol = volume;
  }

  if (volGradient > 1000) {
    volGradient %= 1001;
    //Everytime a palette gets completed is a good time to readjust "maxVol," just in case
    //  the song gets quieter; we also don't want to lose brightness intensity permanently 
    //  because of one stray loud sound.
    maxVol = (maxVol + volume) / 2.0;
    minVol = (minVol + volume) / 2.0;
  }

  if (volume - last > avgVol - last && avgVol - last > 0){
    avgBump = (avgBump + (volume - last)) / 2.0;
  }

  bump = (volume - last) > avgBump;

  volGradient++;

  

  byte *c;

  soundColor = map(avgVol, minVol, maxVol, 0, 255);
  soundColor = constrain(soundColor, 0, 255);    // Clip to 0-350 range

  int range = (maxVol-minVol) / 10;
  int pixels = 10;

  if (volume < range){
    pixels = 1;
  } else if (volume < 2*range+minVol){
    pixels = 2;
  } else if (volume < 3*range+minVol){
    pixels = 3;
  } else if (volume < 4*range+minVol){
    pixels = 4;
  } else if (volume < 5*range+minVol){
    pixels = 5;
  } else if (volume < 6*range+minVol){
    pixels = 6;
  } else if (volume < 7*range+minVol){
    pixels = 7;
  } else if (volume < 8*range+minVol){
    pixels = 8;
  } else if (volume < 9*range+minVol){
    pixels = 9;
  } else if (volume < 10*range+minVol){
    pixels = 10;
  }


  c = Wheel( (soundColor) % 255);
  for(int i=0; i<pixels; i++) {
    CircuitPlayground.setPixelColor(i, *c, *(c+1), *(c+2));
  }  
  for(int i=pixels; i<10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 0, 0);
  } 
//  
//  if (volume > 0){
//    if (bump){
//      
//    }
//  } else {
//    for(int i=0; i<10; i++) {
//      CircuitPlayground.setPixelColor(i, 0, 0, 0);
//    } 

//    colorFade(0, 0, 0, 10);
//  }

  

  
//  Serial.print(last);
//  Serial.print(" ");
  Serial.print(volume);
  Serial.print(" ");
  Serial.print(maxVol);
  Serial.print(" ");
  Serial.print(minVol);
  Serial.print(" ");
  Serial.println(avgVol);
//  for(int i=0; i<10; i++) {
//    CircuitPlayground.setPixelColor(i, soundColor, soundColor*.5, soundColor*.2);
//  }

  last = volume;
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

void colorFade(uint8_t r, uint8_t g, uint8_t b, uint8_t rate) {
  for(uint16_t i = 0; i < 10; i++) {
      uint8_t startR, startG, startB;
//      uint32_t startColor = CircuitPlayground.getPixelColor(i); // get the current colour
//      

      startB = 200;
      startG = 100;
      startR = 150;  // separate into RGB components

      if ((startR != r) || (startG != g) || (startB != b)){  // while the curr color is not yet the target color
        if (startR < r){
          //startR++;   // increment or decrement the old color values
          startR += rate;                         // Set LED fade value
          startR = constrain(startR,0,255);
        } else if (startR > r){
          startR -= rate;                         // Set LED fade value
          startR = constrain(startR,0,255);
        }
        if (startG < g){
          //startR++;   // increment or decrement the old color values
          startG += rate;                         // Set LED fade value
          startG = constrain(startG,0,255);
        } else if (startG > g){
          startG -= rate;                         // Set LED fade value
          startG = constrain(startG,0,255);
        }
        if (startB < b){
          //startR++;   // increment or decrement the old color values
          startB += rate;                         // Set LED fade value
          startB = constrain(startB,0,255);
        } else if (startB > b){
          startB -= rate;                         // Set LED fade value
          startB = constrain(startB,0,255);
        }
        CircuitPlayground.setPixelColor(i, startR, startG, startB);  // set the color

        // delay(1);  // add a delay if its too fast
      }
  }
}
