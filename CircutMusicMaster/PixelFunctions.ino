
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

