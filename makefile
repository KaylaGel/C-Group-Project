#makefile for event_manager.out
#to build, type 'make' into the command line
#to clean up file, type 'make clean' int the command line

CC = gcc
CFLAGS = -Wall -ansi -lm
BINARY = event_manager

event_manager.out : event_manager.o
	$(CC) $(CFLAGS) -o $(BINARY).out $(BINARY).o
	echo "Build Complete"

event_manager.o : event_manager.c
	$(CC) $(CFLAGS) -c -o $(BINARY).o $(BINARY).c -Wno-unused-variable
	echo "Compile Complete"

clean:
	rm event_manager.o
	echo "Cleaning Complete"