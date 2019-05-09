#makefile for event_manager.out
#to build, type 'make' into the command line
#to clean up file, type 'make clean' int the command line

CC = gcc
CFLAGS = -Wall -ansi -lm

event_manager.out : event_manager.o
	$(CC) $(CFLAGS) -o event_manager.out event_manager.o

event_manager.o : event_manager.c
	$(CC) $(CFLAGS) -c -o oevent_manager.o event_manager.c -Wno-unused-variable

clean:
	rm event_manager.