#makefile for event_manager.out
#to build, type 'make' into the command line
#to clean up file, type 'make clean' int the command line

CC = gcc
CFLAGS = -Wall -ansi -lm
BINARY = event_manager

$(BINARY).out : $(BINARY).o
	$(CC) $(CFLAGS) -o $(BINARY).out $(BINARY).o
	echo "Build Complete"

$(BINARY).o : $(BINARY).c
	$(CC) $(CFLAGS) -c -o $(BINARY).o $(BINARY).c -Wno-unused-variable
	echo "Compile Complete"

clean:
	rm $(BINARY).o
	rm $(BINARY).out
	echo "Cleaning Complete"