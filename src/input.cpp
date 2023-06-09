#include "Arduino.h"

void setupJack(){
    pinMode(PIN_A0,INPUT);
    pinMode(PIN_A1,INPUT);
}

void inputDetect(){

    float rightChannelSignal;
    float leftChannelSignal;

    rightChannelSignal = analogRead(PIN_A0);
    leftChannelSignal = analogRead(PIN_A1);

    leftChannelSignal = leftChannelSignal * 3300; // Change the value to be in the 0 to 3300 range
    rightChannelSignal = rightChannelSignal * 3300; // Change the value to be in the 0 to 3300 range
        
    printf("L Channel = %.0f mV\n", leftChannelSignal);
    printf("R Channel = %.0f mV\n", rightChannelSignal);

}




