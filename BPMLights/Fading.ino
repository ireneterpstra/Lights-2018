//#include "application.h"
//#include "neopixel/neopixel.h"

//SYSTEM_MODE(AUTOMATIC);

// Define which pins are connected with a 1-10M resistor.
// The first pin will be connected to the touch sensor
// and must be D0, D1, D2, D3, D4 A0, A1, A3, A4, A5, A6, A7
// see: http://docs.spark.io/firmware/#interrupts-attachinterrupt

#define PIXEL_COUNT 60
#define PIXEL_PIN D2

// Parameter 1 = number of pixels in strip
//               note: for some stripes like those with the TM1829, you
//                     need to count the number of segments, i.e. the
//                     number of controllers in your stripe, not the number
//                     of individual LEDs!
// Parameter 2 = pin number (most are valid)
//               note: if not specified, D2 is selected for you.
// Parameter 3 = pixel type [ WS2812, WS2812B, WS2811, TM1803, TM1829 ]
//               note: if not specified, WS2812B is selected for you.
//               note: RGB order is automatically applied to WS2811,
//                     WS2812/WS2812B/TM1803 is GRB order.
//
// 800 KHz bitstream 800 KHz bitstream (most NeoPixel products ...
//                         ... WS2812 (6-pin part)/WS2812B (4-pin part) )
//
// 400 KHz bitstream (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//                   (Radio Shack Tri-Color LED Strip - TM1803 driver
//                    NOTE: RS Tri-Color LED's are grouped in sets of 3)

//Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);



void colorFade(uint8_t r, uint8_t g, uint8_t b, uint8_t rate) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
      uint8_t startR, startG, startB;
      uint32_t startColor = strip.getPixelColor(i); // get the current colour
      startB = startColor & 0xFF;
      startG = (startColor >> 8) & 0xFF;
      startR = (startColor >> 16) & 0xFF;  // separate into RGB components

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
        strip.setPixelColor(i, startR, startG, startB);  // set the color
        strip.show();
        strip2.setPixelColor(i, startR, startG, startB);  // set the color
        strip2.show();
        // delay(1);  // add a delay if its too fast
      }
  }
}
