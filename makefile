#makefile for event_manager.out
#to build, type 'make' into the command line
#to clean up file, type 'make clean' int the command line

CC = gcc
CFLAGS = -Wall -lm -Wno-unused-variable

EXECUTABLE = EventManager

#Add any new header files that get created into this variable
HEADERS = definitions.h structs.h funciton_prototypes.h
#Add any new .c code files that get created into this variable, but with a .o file extention instead of .c
OBJECTS = main.o event_menu.o data_validation.o user_input.o accounts.c

default: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)