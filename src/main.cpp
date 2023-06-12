/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

#define ENCODER_A D3
#define ENCODER_B D4

int prev_a;
int prev_b;
int volume;

void encoderInterrupt() {
  int a = digitalRead(ENCODER_A);
  int b = digitalRead(ENCODER_B);

  // Check that the values actually are different
  if (a != prev_a || b != prev_b) {
    // Check that the move isn't illegal (we ignore the move in this case)
    if (a != prev_a && b != prev_b) {
      // This is illegal so update the values and return
      prev_a = a;
      prev_b = b;
      return;
    }

    // Legal moves only
    if (prev_b ^ a) {
      // CCW
      volume--;
    } else {
      // CW
      volume++;
    }
  }

  prev_a = a;
  prev_b = b;
}

void setup() {
  // Initialize the encoder
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  prev_a = digitalRead(ENCODER_A);
  prev_b = digitalRead(ENCODER_B);

  // Really we should disable interrupts until both of them are set up.
  // But as far as I can tell it doesn't really matter.
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoderInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), encoderInterrupt, CHANGE);

  volume = 10;
}

void loop() {
  while (1) {
    // printf("Volume: %d\r\n", volume);
    delay(1);
  }
}