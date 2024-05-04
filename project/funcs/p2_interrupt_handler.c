
#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port2(){
    if(P2IFG & switches){
        P2IFG &= ~switches;
        sw_interrupt_handler();
    }
}
