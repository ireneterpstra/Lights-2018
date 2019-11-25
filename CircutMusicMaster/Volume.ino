void volumeVisualizer(){
  volume = CircuitPlayground.mic.soundPressureLevel(10);
  avgVol = (avgVol*.95 + volume*.05);

  if (volume < avgVol / 2.0 || volume < 15) { // silent if vol is less that 1/2 avrg vol
    volume = 0; 
  }
  
  if (volume > maxVol) {
    maxVol = volume;
  }
  if (volume < minVol){
    minVol = volume;
  }

//  if (volGradient > 1000) {
//    volGradient %= 1001;
//    //Everytime a palette gets completed is a good time to readjust "maxVol," just in case
//    //  the song gets quieter; we also don't want to lose brightness intensity permanently 
//    //  because of one stray loud sound.
//    maxVol = (maxVol + volume) / 2.0;
//    minVol = (minVol + volume) / 2.0;
//  }

  maxVol = maxVol*.9995 + volume*.0005;
  minVol = minVol*.9995 + volume*.0005;

  if (volume - last > avgVol - last && avgVol - last > 0){
    avgBump = (avgBump + (volume - last)) / 2.0;
  }

  bump = (volume - last) > avgBump;

  volGradient++;

  

  byte *c;

  soundColor = map(avgVol, minVol, maxVol, 0, 255);
  soundColor = constrain(soundColor, 0, 255);    // Clip to 0-350 range

  int range = (maxVol-minVol) / 10;
  int pixels = 10;

  if (volume < range){
    pixels = 1;
  } else if (volume < 2*range+minVol){
    pixels = 2;
  } else if (volume < 3*range+minVol){
    pixels = 3;
  } else if (volume < 4*range+minVol){
    pixels = 4;
  } else if (volume < 5*range+minVol){
    pixels = 5;
  } else if (volume < 6*range+minVol){
    pixels = 6;
  } else if (volume < 7*range+minVol){
    pixels = 7;
  } else if (volume < 8*range+minVol){
    pixels = 8;
  } else if (volume < 9*range+minVol){
    pixels = 9;
  } else if (volume < 10*range+minVol){
    pixels = 10;
  }


  c = Wheel( (soundColor) % 255);
  for(int i=0; i<pixels; i++) {
    CircuitPlayground.setPixelColor(i, *c, *(c+1), *(c+2));
  }  
  for(int i=pixels; i<10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 0, 0);
  } 
//  
//  if (volume > 0){
//    if (bump){
//      
//    }
//  } else {
//    for(int i=0; i<10; i++) {
//      CircuitPlayground.setPixelColor(i, 0, 0, 0);
//    } 

//    colorFade(0, 0, 0, 10);
//  }

  

  
//  Serial.print(last);
//  Serial.print(" ");
  Serial.print(volume);
  Serial.print(" ");
  Serial.print(maxVol);
  Serial.print(" ");
  Serial.print(minVol);
  Serial.print(" ");
  Serial.println(avgVol);
//  for(int i=0; i<10; i++) {
//    CircuitPlayground.setPixelColor(i, soundColor, soundColor*.5, soundColor*.2);
//  }

  last = volume;
}




