#makefile for event_manager.out

CC = gcc
CFLAGS = -Wall -ansi -lm

event_manager.out : event_manager.o
    $(CC) $(CFLAGS) -o event_manager.out event_manager.o

event_manager.o : event_manager.c
    $(CC) $(CFLAGS) -c -o event_manager.o event_manager.c

