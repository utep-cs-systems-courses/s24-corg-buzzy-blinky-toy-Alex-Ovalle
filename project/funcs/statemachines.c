#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"


// ------------------------------------------------
void next_state(int state) {
  leds_off();

  switch(state) {
  case 1:
    flash(3);
    green_off();
    red_on();
    green_on();
    super_mario();
    red_off();
    break;

  default:
    green_on();
    break;
  }
  // Green LED showing it's ready for the next step.
  green_on();
}