
#include "Arduino.h"
#include "led.h"

void setupLED()
{
  pinMode(LED1_PIN, OUTPUT); // initialize LED digital pin as an output.
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  pinMode(USER_BTN, INPUT_PULLDOWN); // initialize userbutton
}

int userbuttonCount(){

    int clicks = 0;

     if(!digitalRead(USER_BTN) == 1){

        delay(1000);

        if(!digitalRead(USER_BTN) == 1){
            clicks++;
        }
  }
  return clicks; 
}

void LEDon(int LED){
    switch(LED){
        case 1:
            digitalWrite(LED1_PIN, HIGH);
            digitalWrite(LED2_PIN, LOW);
            digitalWrite(LED3_PIN, LOW);
            break;
        case 2:
            digitalWrite(LED1_PIN, LOW);
            digitalWrite(LED2_PIN, HIGH);
            digitalWrite(LED3_PIN, LOW);
            break;
        case 3:
            digitalWrite(LED1_PIN, LOW);
            digitalWrite(LED2_PIN, LOW);
            digitalWrite(LED3_PIN, HIGH);
            break;
        default:
            digitalWrite(LED1_PIN, LOW);
            digitalWrite(LED2_PIN, LOW);
            digitalWrite(LED3_PIN, LOW);
            break;
    }
}

// bottom function debounces button (as best as I can), then toggles LED
// 
void LEDloop(int input){

    int inputState = input;

    switch(inputState){
        case 1:
            LEDon(1);
            break;
        case 2:
            LEDon(2);
            break;
        case 3:
            LEDon(3);
            break;
        default:
            inputState = 0;
            break;
    }  
}

// // main file for testing:


// void setup()
// {
//   setupLED();
// }

// int inputState = 0;
// int count = 0;

// void loop(){  
//   int toggle = userbuttonCount();

//   if(toggle > 0 && count < 4){
//     inputState++;
//     count++;
//   }else if (toggle > 0 && count > 3){
//     inputState = 0;
//     count = 0;
//   }

//  switch(inputState){
//         case 1:
//             LEDon(1);
//             break;
//         case 2:
//             LEDon(2);
//             break;
//         case 3:
//             LEDon(3);
//             break;
//         default:
//             inputState = 0;
//             break;
//     }  
// }
