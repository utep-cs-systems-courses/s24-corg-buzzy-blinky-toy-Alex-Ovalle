all: libTimer.a

CPU		= msp430g2553
CFLAGS	= -mmcu=${CPU} 

# switch  compiler for internal make rules
CC		= msp430-elf-gcc
AS		= msp430-elf-as
AR		= msp430-elf-ar

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

# make install
install: libTimer.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

#make clean
clean:
	rm -f timerLib.a *.o