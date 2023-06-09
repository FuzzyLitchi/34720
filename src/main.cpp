/**
 * 
 *  Main for LED light control, using the userbutton to switch between which LEDs
 * should light up. The debouncing and button stuff is done in (led.c) and is for
 * preliminary testing. 
 * 
 */

#include "Arduino.h"
#include "led.h"
#include "input.h"


void setup()
{
  printf("yee");
  setupJack();
}

void loop(){ 
  inputDetect();
  printf("boom");
}