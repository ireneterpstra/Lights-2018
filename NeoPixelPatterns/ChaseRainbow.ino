void theaterChaseRainbow(int colorDealy, int speedDelay) {
  byte *c;

  int colorTime = (millis()/colorDealy)%256;
  int offTime = (millis()/speedDelay)%3;
  
  for (int i=0; i < numLeds; i=i+3) {
    c = WheelF( (i+colorTime) % 255);
    strip.setPixelColor(i+offTime, *c, *(c+1), *(c+2));    //turn every third pixel on
  }
  strip.show();
  
  for (int i=0; i < numLeds; i=i+3) {
    strip.setPixelColor(i+offTime, 0,0,0);

  }

}

byte * WheelF(byte WheelPos) {
  static byte c[3];
  
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}
