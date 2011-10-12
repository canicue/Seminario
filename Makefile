CC= gcc 
CFLAGS=-Wall -lncurses -lpanel -lform -lmenu 
SFLAGS=-Wall -lsqlite3
CC = gcc
CFLAGS = -g -Wall -O2
SRC = main.c funciones.c funciones.h
OBJ = main.o funciones.o
all: $(OBJ)
	$(CC) $CC(CFLAGS) -o main $(OBJ)
clean: $(RM) $(OBJ) main
funciones.o: funciones.c funciones.h
main.o: main.c funciones.h
modelo:
	$(CC) $(ls modelo/*.c)
