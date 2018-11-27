void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
 
  int modTime = (millis()/wait)%256;
  for(i=0; i< stripU.numPixels(); i++) {
    stripU.setPixelColor(i, Wheel(((i * 256 / stripU.numPixels()) + modTime) & 255));
    stripL.setPixelColor(i, Wheel(((i * 256 / stripU.numPixels()) + modTime) & 255));
  }
  for(i=0; i<10; i++) {
    CircuitPlayground.setPixelColor(i, Wheel(((i * 256 / 10) + modTime) & 255));
  }
  stripU.show();
  stripL.show();
}
