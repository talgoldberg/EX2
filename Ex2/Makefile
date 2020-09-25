CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_MYBANK=myBank.o
FLAGS= -Wall -g


myBanks: libmyBank.a
libmyBank.a: $(OBJECTS_MYBANK) myBank.h
	 $(AR) rcs libmyBank.a $(OBJECTS_MYBANK)

mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a



myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c 

main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all myBanks

clean:
	rm -f *.o *.a mains

all: myBanks mains

