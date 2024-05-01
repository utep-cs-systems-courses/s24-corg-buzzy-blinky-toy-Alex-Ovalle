#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "statemachines.h"


char stateDown;

void sw_init()
{
  P2REN |= switches;
  P2IE |= switches;
  P2OUT |= switches;
  P2DIR &= ~switches;
  sw_update_interrupt_sense();
  sw_interrupt_handler();
  led_update();

}


char sw_update_interrupt_sense()
{
  char p2Value = P2IN;
  P2IES |= (p2Value & switches);/* if switch up, sense down */
  P2IES &= (p2Value | ~switches);/* if switch down, sense up */
  return p2Value;
}


void sw_interrupt_handler()
{
  char p2Value = sw_update_interrupt_sense();
  char button1 = (p2Value & S1) ? 0 : S1;
  char button2 = (p2Value & S2) ? 0 : S2;
  char button3 = (p2Value & S3) ? 0 : S3;
  char button4 = (p2Value & S4) ? 0 : S4;

  if (button_1)
    {
      next_state(1);
      stateDown = 1;
    }
  else if (button_2)
    {
      next_state(2);
      stateDown = 1;
    }
  else if (button_3)
    {
      next_state(3);
      stateDown = 1;
    }

  else if (button_4)
    {
      next_state(4);
      stateDown = 1;
    }
}