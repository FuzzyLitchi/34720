
#include "Arduino.h"
#include "led.h"
#include "input.h"
#include <arduino-timer.h>


// create a timer that holds 16 tasks, with millisecond resolution,
// and a custom handler type of 'const char *

Timer<16, millis, const char *>timer_ms;

auto timer = timer_create_default(); // create a timer with default settings
int seconds = 0;
uint32_t milli = 0;

int primaryInput[50];
int secondaryInput[50];


bool counterSec(void *){
  seconds++;
  if(seconds > 59){
    seconds = 0;
  }
  return true;
}

bool counterMilli(void *){
  milli += 500;
  if(milli > 999){
    seconds++;
  }
  return true;
}

bool readAux(void *){
  int i;
   for (i = 0; i < 50; i++) {
      primaryInput[i] = analogRead(A0);
      // secondaryInput[i] = analogRead(A1);
    }
  return true;
}

bool simSignalDet(){
  int i;
  if(analogRead(A1)){
    return true;
  }
  return false;
}


int findStandardDeviation(int *array, int count) {
    int sum = 0, sDeviation = 0.0, mean;
    int i;
 
    for(i = 0; i < count; i++) {
        sum += array[i];
    }
    // Calculating mean 
    mean = sum/count;
 
    for(i = 0; i < count; ++i) {
        sDeviation += pow(array[i] - mean, 2);
    }
 
    return sqrt(sDeviation/count);
}


void setup()
{
  printf("yee");
  setupJack();
  setupLED();

  pinMode(USER_BTN, INPUT_PULLDOWN); // initialize userbutton

  timer.every(500, readAux);
  timer.every(1000, counterSec);
}


void loop(){

  timer.tick(); // tick the timer

// for simulating second source 

  int std1, std2;

  std1 = findStandardDeviation(primaryInput, 50);
  //std2 = findStandardDeviation(secondaryInput, 50);
  
  bool aux = false;
  if(std1 > 2){
    aux = true;
  }

  bool sim = simSignalDet(); // simulated signal detection

  if(sim){
    LEDon(1);
  }else if(aux && !(sim)){
    LEDon(2);
  }else if(!(aux) && !(sim)){
    LEDon(3);
  }


  if(std1 > 2){
    LEDon(1);
  }else if( std1 < 2 && std2 > 0){
    LEDon(2);
  }else{
    LEDon(3);
  }

    // printf("STD: %d\n", std);
  

  }


  // int clicks = userbuttonCount();

  // if(clicks == 0){
  // inputDetect();
  // delay(100);
  // }
