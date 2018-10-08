void meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {  
  for(int i = 0; i < numLeds; i++ ) {
    strip.setPixelColor(i, 0, 0, 0); 
  }

  // fade brightness all LEDs one step
  int modTime = (millis()/SpeedDelay)%(numLeds+numLeds);
  
  for(int j=0; j<numLeds; j++) {
    if( (!meteorRandomDecay) || (random(10)>5) ) {
      fadeToBlack(j, meteorTrailDecay );        
    }
  }
  
  // draw meteor
  for(int j = 0; j < meteorSize; j++) {
    if( ( modTime-j <numLeds) && (modTime-j>=0) ) {
      strip.setPixelColor(modTime-j, red, green, blue);
    } 
  }
 
  strip.show();
  //delay(SpeedDelay);
}

void fadeToBlack(int ledNo, byte fadeValue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
    // NeoPixel
    uint32_t oldColor;
    uint8_t r, g, b;
    int value;
    
    oldColor = strip.getPixelColor(ledNo);
    r = (oldColor & 0x00ff0000UL) >> 16;
    g = (oldColor & 0x0000ff00UL) >> 8;
    b = (oldColor & 0x000000ffUL);

    r=(r<=10)? 0 : (int) r-(r*fadeValue/256);
    g=(g<=10)? 0 : (int) g-(g*fadeValue/256);
    b=(b<=10)? 0 : (int) b-(b*fadeValue/256);
    
    strip.setPixelColor(ledNo, r,g,b);
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[ledNo].fadeToBlackBy( fadeValue );
 #endif  
}
