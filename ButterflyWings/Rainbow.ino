void rainbow(uint8_t wait) {
  uint16_t i, j;
  
  int modTime = (millis()/wait)%256;
  //Serial.println("Time" + String(modTime));

  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel((i*1+modTime) & 255));
    strip2.setPixelColor(i, Wheel((i*1+modTime) & 255));
  }
  strip.show();
  strip2.show();
}
