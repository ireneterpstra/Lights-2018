void stableVolume(){
  volume = CircuitPlayground.mic.soundPressureLevel(10);
  stableVol = stableVol*.75 + volume*.25;
  stableVol1 = stableVol1*.7 + volume*.3;
  stableVol2 = stableVol2*.50 + volume*.50;


  if (volume < avgVol / 2.0 || volume < 15) { // silent if vol is less that 1/2 avrg vol
    volume = 0; 
  }

  if (volume > maxVol) {
    maxVol = volume;
  }
  if (volume < minVol){
    minVol = volume;
  }
  maxVol = maxVol*.9995 + volume*.0005;
  minVol = minVol*.9995 + volume*.0005;

//  int range = (maxVol-minVol) / 10;
  pixels = map(stableVol2, minVol, maxVol, 0, 10);

  for(int i=0; i<pixels; i++) {
    CircuitPlayground.setPixelColor(i, 232, 0, 135);
  }  
  for(int i=pixels; i<10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 0, 0);
  } 
  
//  Serial.print(last);
//  Serial.print(" ");
  Serial.print(stableVol1);
  Serial.print(" ");
  Serial.print(minVol);
  Serial.print(" ");
  Serial.println(maxVol);
//  Serial.print(" ");
//  Serial.println(volume);

}


