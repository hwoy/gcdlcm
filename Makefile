CC=gcc
CFLAGS=-O2 -std=c89 -pedantic -Wall
BIN=gl.exe

.PHONY: all clean

all: $(BIN)

clean:
	rm -rf *.o $(BIN) *.exe

function.o: function.c function.h
gcdlcm.o: gcdlcm.c gcdlcm.h
main.o: main.c function.h gcdlcm.h

$(BIN): function.o gcdlcm.o main.o
	$(CC) -o $(BIN) function.o gcdlcm.o main.o

