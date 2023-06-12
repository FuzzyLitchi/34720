#include "Arduino.h"
#include "input.h"

void setupJack(){
    pinMode(PIN_A0,INPUT);
    pinMode(PIN_A1,INPUT);
}

void inputDetect(){

    int rightChannelSignal;
    int leftChannelSignal;

    rightChannelSignal = analogRead(PIN_A0);
    leftChannelSignal = analogRead(PIN_A1);
        
   // printf("L Channel = %d mV\n", leftChannelSignal);
   // printf("%d\n", rightChannelSignal);
}

// float standardDev(float data[]){
//     float sum = 0.0, mean, standardDeviation = 0.0;
//     int i;

//   for(i = 0; i < 10; ++i) {
//     sum += data[i];
//   }

//   mean = sum / 10;

//   for(i = 0; i < 10; ++i) {
//     standardDeviation += pow(data[i] - mean, 2);
//   }

//   return sqrt(standardDeviation / 10);
// }








