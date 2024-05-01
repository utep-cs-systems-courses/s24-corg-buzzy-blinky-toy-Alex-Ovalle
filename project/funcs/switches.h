#ifndef switches_included
#define switches_included

#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3


#define switches (S1 | S2 | S3 | S4) /* 4 switches on the board */


void sw_init();
static char sw_update_interrupt_sense();
void sw_interrupt_handler();


extern char stateDown, stateChanged; 
extern char button_sequence_state;
extern int secondCount;
#endif