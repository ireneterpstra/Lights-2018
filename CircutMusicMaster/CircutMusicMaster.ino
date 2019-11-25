#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

int pixels = 200;

int state = 0;

boolean lastPressedR = false;
boolean lastPressedL = false;

double soundPressure; 
int soundColor;

uint16_t volGradient = 0; 

double volume = 0;
double last = 0;
double maxVol = 10;
double minVol = 50;
double avgVol = 0;
double avgBump = 0;

double stableVol = 0;
double stableVol1 = 0;
double stableVol2 = 0;

boolean bump = false;

int colorCount = 0;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 5, NEO_GRB + NEO_KHZ800);


void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
}


void loop() {
  delay(10);

  testState();
  switch(state){
    case 0: 
      //Serial.println("Case: Volume");
      volumeVisualizer();
      break;
    case 1: 
      //Serial.println("Case: Volume2");
      stableVolume();
      break;
    case 2: 
      //Serial.println("Case: Frequency");
      frequencyVisualizer();
      break;
    case 3: 
      //Serial.println("Case: Beats");
      beats();
      break;
    case 4: 
      //Serial.println("Case: Beats2");
      beats2();
      break;
  }

  
}



