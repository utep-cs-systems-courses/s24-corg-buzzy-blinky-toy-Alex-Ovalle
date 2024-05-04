#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

int main(void){
  configureClocks();
  sw_init(); // Initializing Switches
  led_init(); // Initializing LED
  buzz_init(); // Initializing Buzzer

  green_on();
  enableWDTInterrupts();

  or_sr(0x18); // CPU off, GIE on   
}
