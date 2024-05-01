# config
COMMON_OBJECTS  = 
CPU 	= msp430g2553
CFLAGS  = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC = msp430-elf-gcc
AS = msp430-elf-as


#make all
all: main.elf


#additional rules
main.elf: ${COMMON_OBJECTS} main.o led.o switches.o statemachines.o buzzer.o wdInterrupthandler.o p2_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


#make load
load: main.elf
	msp430loader.sh main.elf


#make clean
clean:
	rm -f *.o *.elf *~