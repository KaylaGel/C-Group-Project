#makefile for event_manager.out
#to build, type 'make' into the command line
#to clean up file, type 'make clean' int the command line

CC = gcc
CFLAGS = -Wall -ansi -lm
BINARY = main
EXECUTABLE = EventManager

default: $(EXECUTABLE)

$(EXECUTABLE) : $(BINARY).o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(BINARY).o
	echo "Build Complete"

$(BINARY).o : $(BINARY).c
	$(CC) $(CFLAGS) -c -o $(BINARY).o $(BINARY).c -Wno-unused-variable
	echo "Compile Complete"

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
	echo "Cleaning Complete"