void Sparkle(byte red, byte green, byte blue, int SpeedDelay, int frequency) {
  int modTime = (millis()/SpeedDelay)%frequency;
  int Pixel = random(numLeds);

  if (modTime == 1){
    strip.setPixelColor(Pixel, red, green, blue);
    strip2.setPixelColor(Pixel, red, green, blue);
    strip.show();
    strip2.show();
  } else {
    strip.setPixelColor(Pixel,0,0,0);
    strip2.setPixelColor(Pixel,0,0,0);
    strip.show();
    strip2.show();
    Serial.print("Turn off: " + String(Pixel));
  }
}

void SparkleRainbow(int SpeedDelay, int frequency) {
  int modTime = (millis()/SpeedDelay)%frequency;
  int modCTime = (millis()/SpeedDelay)%256;
  int Pixel = random(numLeds);

  if (modTime == 1){
    strip.setPixelColor(Pixel, Wheel(((Pixel * 256 / strip.numPixels()) + modCTime) & 255));
    strip2.setPixelColor(Pixel, Wheel(((Pixel * 256 / strip.numPixels()) + modCTime) & 255));
    strip.show();
    strip2.show();
  } else {
    strip.setPixelColor(Pixel,0,0,0);
    strip2.setPixelColor(Pixel,0,0,0);
    strip.show();
    strip2.show();
    Serial.print("Turn off: " + String(Pixel));
  }
}
