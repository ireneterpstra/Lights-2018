void green(uint8_t wait){
  uint16_t i, j;
  int modTime = (millis()/wait)%100;
  //Serial.println("Time" + String(modTime));
  if (modTime < 50){
    for(i=0; i<stripU.numPixels(); i++) {
      stripU.setPixelColor(i, modTime*.2, 200, modTime);
      stripL.setPixelColor(i, modTime*.2, 200, modTime);
    }
    for(i=0; i<10; i++) {
      CircuitPlayground.setPixelColor(i, modTime*.2, 200, modTime);
    } 
  } else {
    for(i=0; i<stripU.numPixels(); i++) {
      stripU.setPixelColor(i, (100-modTime)*.2, 200, 100-modTime);
      stripL.setPixelColor(i, (100-modTime)*.2, 200, 100-modTime);
    }
    for(i=0; i<10; i++) {
      CircuitPlayground.setPixelColor(i, (100-modTime)*.2, 200, 100-modTime);
    } 
  }
  
  stripU.show();
  stripL.show();
  
}

