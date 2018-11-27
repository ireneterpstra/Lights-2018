void ColorFade(){
  for(int j = 0; j < 3; j++ ) { 
    // Fade IN
    for(int k = 0; k < 256; k++) { 
      switch(j) { 
        case 0: 
          for(int i = 0; i < numLeds; i++ ) {
            strip.setPixelColor(i, 178, 34, 34); 
          } 
          break;
        case 1: 
          for(int i = 0; i < numLeds; i++ ) {
            strip.setPixelColor(i, 138, 139, 140); 
          } 
          break;
        case 2: 
          for(int i = 0; i < numLeds; i++ ) {
            strip.setPixelColor(i, 194, 192, 191); 
          } 
          break;
      }
      strip.show();
      delay(3);
    }
    // Fade OUT
    for(int k = 255; k >= 0; k--) { 
      switch(j) { 
        case 0: 
          for(int i = 0; i < numLeds; i++ ) {
            strip.setPixelColor(i, 178, 34, 34); 
          } 
          break;
        case 1: 
          for(int i = 0; i < numLeds; i++) {
            strip.setPixelColor(i, 138, 139, 140); 
          } 
          break;
        case 2: 
          for(int i = 0; i < numLeds; i++ ) {
            strip.setPixelColor(i, 194, 192, 191); 
          } 
          break;
      }
      strip.show();
      delay(3);
    }
  }
}
