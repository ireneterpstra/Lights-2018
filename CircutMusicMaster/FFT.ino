void frequencyVisualizer(){
  pixels = 10;
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

void setRainbowColor(int j, int i){
  if (j < 3){
    CircuitPlayground.setPixelColor(i, 249, 47, 7); //red
  } else if(j < 6){
    CircuitPlayground.setPixelColor(i, 237, 90, 0); // orange
  } else if(j < 9){
    CircuitPlayground.setPixelColor(i, 237, 181, 0); //yellow
  } else if(j < 12){
    CircuitPlayground.setPixelColor(i, 155, 232, 2); //light green
  } else if(j < 15){
    CircuitPlayground.setPixelColor(i, 1, 232, 120); //green blue
  } else if(j < 18){
    CircuitPlayground.setPixelColor(i, 0, 232, 224); //light blue
  } else if(j < 21){
    CircuitPlayground.setPixelColor(i, 0, 92, 232); //dark blue
  } else if(j < 24){
    CircuitPlayground.setPixelColor(i, 77, 0, 232); //purpleish
  } else if(j < 27){
    CircuitPlayground.setPixelColor(i, 143, 0, 232); //purple
  } else if(j < 30){
    CircuitPlayground.setPixelColor(i, 216, 0, 232); //pink
  } else if(j < 33){
    CircuitPlayground.setPixelColor(i, 232, 0, 135); //pinkish
  }

}

