
#include <msp430.h>
#include "statemachines.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blinks = 0;
  if (++blinks == 125) 
    blinks = 0;
}
