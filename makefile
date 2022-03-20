CC=g++
CFLAGS=-I.
DEPS = piece.hpp board.hpp coord.hpp definitions.hpp fen.hpp game.hpp terminal_display.hpp
OBJ = main.o piece.o board.o coord.o definitions.o fen.o game.o terminal_display.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chess: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	