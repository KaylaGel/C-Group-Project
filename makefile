#makefile for event_manager.out
#to build, type 'make' into the command line
#to clean up file, type 'make clean' int the command line

CC = gcc
CFLAGS = -Wall -lm -Wno-unused-variable

EXECUTABLE = EventManager

HEADERS = definitions.h structs.h funciton_prototypes.h
OBJECTS = main.o event_menu.o data_validation.o user_input.o

default: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)