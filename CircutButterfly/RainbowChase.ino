void rainbowChase(int colorDealy, int speedDelay) {
  byte *c;

  int colorTime = (millis()/colorDealy)%256;
  int offTime = (millis()/speedDelay)%3;
  
  for (int i=0; i < numLedsU; i=i+3) {
    c = WheelF( (i+colorTime) % 255);
    stripU.setPixelColor(i+offTime, *c, *(c+1), *(c+2));    //turn every third pixel on
    stripL.setPixelColor(i+offTime, *c, *(c+1), *(c+2));    //turn every third pixel on
  }
  stripU.show();
  stripL.show();
  
  for (int i=0; i < numLedsU; i=i+3) {
    stripU.setPixelColor(i+offTime, 0,0,0);
    stripL.setPixelColor(i+offTime, 0,0,0);
  }

  for (int i=0; i < 10; i=i+3) {
      CircuitPlayground.setPixelColor(i+offTime, *c, *(c+1), *(c+2));    //turn every third pixel on
  }
  for (int i=0; i < 10; i=i+3) {
      CircuitPlayground.setPixelColor(i+offTime, 0,0,0);
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
