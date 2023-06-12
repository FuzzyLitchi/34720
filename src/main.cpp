
#include "Arduino.h"
#include "led.h"
#include "input.h"
#include <arduino-timer.h>


// create a timer that holds 16 tasks, with millisecond resolution,
// and a custom handler type of 'const char *

// Timer<16, millis, const char *>timer_ms;

auto timer = timer_create_default(); // create a timer with default settings
int count = 0;
uint32_t milli = 0;

int primaryInput[50];
int secondaryInput[50];
int std1, std2;

struct aux
{
  int STD1;
  int STD2;
  int STD3;
  int STD4;
  bool playing;
  /* data */
}aux1, aux2;



int findStandardDeviation(int *array, int count) {
    int sum = 0.0, sDeviation = 0.0, mean;
    int i;
 
    for(i = 0; i < count; i++) {
        sum += array[i];
    }
    // Calculating mean 
    mean = sum/count;
 
    for(i = 0; i < count; ++i) {
        sDeviation += (array[i] - mean)*(array[i] - mean);
    }

    return sDeviation/count; // returns STD^2 
}

bool readAux(void *){
  int i;
   for (i = 0; i < 50; i++) {
      primaryInput[i] = analogRead(A0);
      secondaryInput[i] = analogRead(A2);
    }
    std1 = findStandardDeviation(primaryInput, 50);
    std2 = findStandardDeviation(secondaryInput, 50);

    switch(count){
      case 0:
        aux1.STD1 = std1;
        aux2.STD2 = std2;
        break;
      case 1:
        aux1.STD1 = std1;
        aux2.STD2 = std2;
        break;
      case 2:
        aux1.STD1 = std1;
        aux2.STD2 = std2;
        break;
      case 3:
        aux1.STD1 = std1;
        aux2.STD2 = std2;
        break;
      default:
        printf("std save fail");
        break;
    }
    count++;
    if(count > 3){
      count = 0;
    }

  return true;
}

bool probNoInput(void *){
  int temp1 = 0;
  int temp2 = 0;

  bool pausetest1 = false;
  bool confirm1 = false;

  bool pausetest2 = false;
  bool confirm2 = false;

  aux1.playing = false;
  aux2.playing = false;

  if(aux1.STD1 < 7 && aux1.STD2 < 7 && aux1.STD3 < 7 && aux1.STD4 < 7){
    pausetest1 = true;
  }else{
    pausetest1 = false;
    aux1.playing = true;
  }

  if(aux2.STD1 < 7 && aux2.STD2 < 7 && aux2.STD3 < 7 && aux2.STD4 < 7){
    pausetest2 = true;
  }else{
    pausetest2 = false;
    aux2.playing = true;
  }

  return true;

}

void setup()
{
 // printf("yee");
  setupJack();
  setupLED();

  pinMode(USER_BTN, INPUT_PULLDOWN); // initialize userbutton

  timer.every(250, readAux);
  timer.every(1000, probNoInput);
}

void loop(){

  timer.tick(); // tick the timer
  
  int sit = 0;

  printf("std aux 2: %d \r\n", std2);

  // prioritizing input from aux 1

  // if(std1 > 2){
  //   aux1 = true;
  //   aux2 = false;
  //   sit = 1;
  //   printf("playing from primary source\r\n");
  // }else if(std2 > 2 && std1 < 3){
  //   aux1 = false;
  //   aux2 = true;
  //   sit = 2;
  //   printf("playing from secondary source \r\n");
  // }else if(std2 < 3 && std1 < 3){
  //   aux1 = false;
  //   aux2 = false;
  //   sit = 3;
  //   printf("playing from none\r\n");
  // }
  //lighting LED depending on which input is "playing"
  // LEDon(sit);
  // delay(500);
  // printf("STD: %d\n", std);
  }

