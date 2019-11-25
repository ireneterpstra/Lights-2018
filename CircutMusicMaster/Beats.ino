void beats(){
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
//    
//  }

  maxVol = maxVol*.999 + volume*.001;
  minVol = minVol*.999 + volume*.001;

  if (volume - last > avgVol - last && avgVol - last > 0){
    avgBump = (avgBump + (volume - last)) / 2.0;
  }

  bump = (volume - last) > avgBump;

  volGradient++;

  

  byte *c;

  soundColor = map(avgVol, minVol, maxVol, 0, 255);
  soundColor = constrain(soundColor, 0, 255);    // Clip to 0-350 range
  
  int range = (maxVol-minVol) / 10;
  
  if (volume > 0){
    if (bump){
//      c = Wheel( (soundColor) % 255);
      for(int i=0; i<10; i++) {
        beatRainbowColor(i, range);
      }  
//      for(int i=pixels; i<10; i++) {
//        CircuitPlayground.setPixelColor(i, 0, 0, 0);
//      } 
    } else {
//      for(int i=0; i<10; i++) {
//        CircuitPlayground.setPixelColor(i, 0, 0, 0);
//      }
//      colorFade(0, 0, 0, 10);
    }
  } 

  

  
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


void beatRainbowColor(int i, int range){
  if (avgVol < range){
    CircuitPlayground.setPixelColor(i, 249, 47, 7); //red
  } else if (volume < 2*range+minVol){
    CircuitPlayground.setPixelColor(i, 237, 90, 0); // orange
  } else if (volume < 3*range+minVol){
    CircuitPlayground.setPixelColor(i, 237, 181, 0); //yellow
  } else if (volume < 4*range+minVol){
    CircuitPlayground.setPixelColor(i, 155, 232, 2); //light green
  } else if (volume < 5*range+minVol){
    CircuitPlayground.setPixelColor(i, 1, 232, 120); //green blue
  } else if (volume < 6*range+minVol){
    CircuitPlayground.setPixelColor(i, 0, 232, 224); //light blue
  } else if (volume < 7*range+minVol){
    CircuitPlayground.setPixelColor(i, 0, 92, 232); //dark blue
  } else if (volume < 8*range+minVol){
    CircuitPlayground.setPixelColor(i, 77, 0, 232); //purpleish
  } else if (volume < 9*range+minVol){
    CircuitPlayground.setPixelColor(i, 143, 0, 232); //purple
  } else if (volume < 10*range+minVol){
    CircuitPlayground.setPixelColor(i, 232, 0, 135); //pinkish
  }
}



