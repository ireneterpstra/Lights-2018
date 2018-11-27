void testState(){
  if (CircuitPlayground.rightButton() && !lastPressedR){
    lastPressedR = true;
    Serial.print(" Right button pressed! ");
    if (state < 2){
      state ++;
    } else{
    state = 0;
    } 
    Serial.println("State =  " + String(state));

  } else if (!CircuitPlayground.rightButton()){
    lastPressedR = false;
  }
  if (CircuitPlayground.leftButton()  && !lastPressedL){
    lastPressedL = true;
    Serial.print(" Left button pressed! ");
    if (state > 0){
      state --;
    } else{
      state = 2;
    } 
    Serial.println("State =  " + String(state));
  } else if (!CircuitPlayground.leftButton()){
    lastPressedL = false;
  }
}

