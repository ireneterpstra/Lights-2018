#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

int pixels = 10;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 5, NEO_GRB + NEO_KHZ800);


void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
}


void loop() {
  delay(10);

  uint16_t spectrum[32]; // FFT spectrum output buffer
  double freqTot = 0;

  CircuitPlayground.mic.fft(spectrum);
  for(int i=0; i<32; i++) {
    freqTot += spectrum[i];
  }

  int iBin = 0;
  double accumulator = 0;
  double target;
  byte *c;
  for(int i=0; i<pixels; i++) {
    target = i*(freqTot/10);
    while(target > (accumulator + spectrum[iBin])){
      accumulator += spectrum[iBin];
      iBin++;
    } 
    setRainbowColor(iBin, i);
  }

  for(int i=0; i<32; i++){
    Serial.print(spectrum[i]);
    Serial.print(" ");
  }
  Serial.println(accumulator);
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


void setRainbowColor(int j, int i){
  if (j < 4){
    CircuitPlayground.setPixelColor(i, 249, 47, 7);
  } else if(j < 8){
    CircuitPlayground.setPixelColor(i, 255, 128, 17);
  } else if(j < 12){
    CircuitPlayground.setPixelColor(i, 255, 219, 17);
  } else if(j < 16){
    CircuitPlayground.setPixelColor(i, 100, 255, 17);
  } else if(j < 20){
    CircuitPlayground.setPixelColor(i, 17, 255, 203);
  } else if(j < 24){
    CircuitPlayground.setPixelColor(i, 17, 147, 255);
  } else if(j < 28){
    CircuitPlayground.setPixelColor(i, 112, 17, 255);
  } else if(j < 33){
    CircuitPlayground.setPixelColor(i, 219, 17, 255);
  }

  
}

