void rainbow(uint8_t wait) {
  uint16_t i, j;
  
  int modTime = (millis()/wait)%256;
  //Serial.println("Time" + String(modTime));

  for(i=0; i<stripU.numPixels(); i++) {
    stripU.setPixelColor(i, Wheel((i*1+modTime) & 255));
    stripL.setPixelColor(i, Wheel((i*1+modTime) & 255));
  }
  for(i=0; i<10; i++) {
    CircuitPlayground.setPixelColor(i, Wheel((i*1+modTime) & 255));
  }
  stripU.show();
  stripL.show();
}
