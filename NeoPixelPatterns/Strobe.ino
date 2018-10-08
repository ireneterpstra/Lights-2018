void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    for (int i=0; i < numLeds; i++) {
        strip.setPixelColor(i, r, g, b);    //turn every third pixel on
    }
    strip.show();
    delay(10);
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    for (int i=0; i < numLeds; i=i+4) {
        strip.setPixelColor(i, r, g, b);    //turn every third pixel on
    }
    strip.show();
    delay(10);
  }

}
