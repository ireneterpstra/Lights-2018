
void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;

  int posTime = (millis()/WaveDelay)%(numLeds*2);
  
  for(int i=0; i<numLeds; i++) {
    // sine wave, 3 offset waves make a rainbow!
    //float level = sin(i+Position) * 127 + 128;
    //setPixel(i,level,0,0);
    //float level = sin(i+Position) * 127 + 128;
    strip.setPixelColor(i,((sin(i+posTime) * 127 + 128)/255)*red,
               ((sin(i+posTime) * 127 + 128)/255)*green,
               ((sin(i+posTime) * 127 + 128)/255)*blue);
    strip2.setPixelColor(i,((sin(i+posTime) * 127 + 128)/255)*red,
               ((sin(i+posTime) * 127 + 128)/255)*green,
               ((sin(i+posTime) * 127 + 128)/255)*blue);
  }
  
  strip.show();
  strip2.show();

}
