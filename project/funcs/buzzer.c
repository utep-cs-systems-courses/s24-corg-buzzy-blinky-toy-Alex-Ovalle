
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


void tloz(){

  int notes[] = {E4, G4, A4, 0, E5, 0, E5, 0, E5, G5, A5, 0, F5, 0, F5, 0,
    F5, E5, D5, 0, D5, 0, D5, C5, B4, 0, G4, 0, G4, 0, G4,
    E4, 0, E4, 0, E4, G4, A4, 0, F4, 0, F4, 0, F4, E4, D4, 0,
    D4, 0, D4, C4, B3, 0, G3, 0, G3, 0, G3, E3, 0, E3, 0, E3};

  for(int i = 0; i < 26; i++)
  {
    buzz_set_period(notes[i]);
    __delay_cycles(2500000);
    buzz_set_period(0);
    __delay_cycles(2500000);
  }
  buzz_set_period(0);
}

void tg_intro(){
  int notes[] = {
    A3, G3, A3, C4, A3, G3, A3, C4,
    A3, G3, A3, C4, A3, G3, A3, C4,
    A3, G3, A3, C4, A3, G3, A3, C4,
    A3, G3, A3, C4, A3, G3, A3, C4
  };

  for(int i = 0; i < 26; i++)
  {
    buzz_set_period(notes[i]);
    __delay_cycles(2500000);
    buzz_set_period(0);
    __delay_cycles(2500000);
  }
  buzz_set_period(0);
} 
