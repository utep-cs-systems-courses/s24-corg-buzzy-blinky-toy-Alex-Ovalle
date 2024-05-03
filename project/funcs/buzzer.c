
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "notes.h"
#include "statemachines.h"


void buzz_init(){
    timerAUpmode();
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		// enable output to speaker 2.6
}

void buzz_set_period(short cycles){
  CCR0 = cycles; 
  CCR1 = cycles >> 1;	
}


void super_mario(){

  int notes[] = {E5,E5,E5,C5,E5,G5,bk,G5,bk,C5,G5,E5,A5,B5,Bb5,A5,G5,E5,G5,A5,F5,G5,E5,C5,D5,B5};

  for(int i = 0; i < 26; i++)
  {
    buzz_set_period(notes[i]);
    __delay_cycles(2500000);
    buzz_set_period(0);
    __delay_cycles(2500000);
  }
  buzz_set_period(0);
}
