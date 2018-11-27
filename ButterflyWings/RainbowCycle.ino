void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
 
  int modTime = (millis()/wait)%256;
  for(i=0; i< strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + modTime) & 255));
    strip2.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + modTime) & 255));
  }
  strip.show();
  strip2.show();
}
