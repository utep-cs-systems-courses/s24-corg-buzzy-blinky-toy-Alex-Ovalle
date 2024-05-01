
#include <msp430.h>
#include "led.h"
#include "switches.h"


unsigned char led_altered = 0;
unsigned char r_led_on = 0, g_led_on = 0;
static char redVal[] = {0, RED_LED}, greenVal[] = {0, GREEN_LED};

void led_init() {
  P1DIR |= LEDS;
  led_altered = 1;
  led_update();
}

void led_update() {
  if (led_altered) {
    char ledFlags = redVal[r_led_on] | greenVal[g_led_on];
    P1OUT &= (0xff^LEDS) | ledFlags; 
    P1OUT |= ledFlags;             
    led_altered = 0;
  }
}

void green_led_on() {
  P1OUT |= RED_LED;
  __delay_cycles(500000);
}

void red_led_on(){
  P1OUT |= GREEN_LED;
  __delay_cycles(500000);
}

void leds_off() {
  P1OUT &= ~GREEN_LED;
  __delay_cycles(500000);
  P1OUT &= ~RED_LED;
}

void led_flash(int n){
  for (int i = 0; i < n; i++){
    P1OUT |= GREEN_LED;
    __delay_cycles(1500000);
    P1OUT &= ~RED_LED;
    __delay_cycles(500000);
    P1OUT &= ~GREEN_LED;
    __delay_cycles(500000);
    P1OUT |= RED_LED;
    __delay_cycles(1500000);
  }
}
