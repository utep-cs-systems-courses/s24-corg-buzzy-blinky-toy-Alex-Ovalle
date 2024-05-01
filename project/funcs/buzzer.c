
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
  int melody[] = {
    E5, E5, P, E5, P, C5, E5, P, G5, P, G4, P,
    C5, P, G4, P, E4, P, A4, P, B4, P, Bb4, A4,
    G4, E5, G5, A5, F5, G5, P, E5, C5, D5, B4,
    P, C5, P, G4, P, E4, P, A4, P, B4, P, Bb4,
    A4, G4, E5, G5, A5, F5, G5, P, E5, C5, D5,
    B4, P, C5, P, G4, P, E4, P, E5, E5, P, E5,
    P, C5, E5, P, G5, P, G4, P, C5, P, G4, P,
    E4, P, A4, P, B4, P, Bb4, A4, G4, E5, G5,
    A5, F5, G5, P, E5, C5, D5, B4, P, C5, P,
    G4, P, E4, P, A4, P, B4, P, Bb4, A4, G4,
    E5, G5, A5, F5, G5, P, E5, C5, D5, B4, P,
    C5, P, G4, P, E4, P
  };
  
  int noteDurations[] = {
    8, 8, 4, 8, 4, 8, 8, 4, 8, 4, 8, 4,
    8, 4, 8, 4, 8, 4, 8, 4, 8, 4, 4, 4,
    4, 8, 8, 8, 4, 4, 8, 8, 8, 4, 8, 4,
    8, 4, 8, 4, 8, 4, 8, 4, 8, 4, 4, 4,
    4, 8, 8, 8, 4, 4, 8, 8, 8, 4, 8, 4,
    8, 4, 8, 4, 8, 4, 8, 8, 4, 8, 4, 8,
    4, 8, 4, 8, 4, 8, 4, 4, 4, 4, 8, 8,
    8, 4, 4, 8, 8, 8, 4, 8, 4, 8, 4, 8,
    4, 8, 4, 8, 4, 8, 4, 4, 4, 4, 8, 8,
    8, 4, 4, 8, 8, 8, 4, 8, 4, 8, 4, 8,
    4, 8, 4, 8, 4, 8, 4, 4, 4
  };
  
  int pauseDuration = 100;
  
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int duration = 1000 / noteDurations[i];
    if (melody[i] == P) {
      delay_ms(pauseDuration);
    } else {
      buzz_set_period(melody[i]);
      delay_ms(duration);
      buzz_set_period(0);
    }
    delay_ms(pauseDuration / 2);
  }
}   