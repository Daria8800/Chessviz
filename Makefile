g = g++
CFLAGS = -Wall -Werror -MP -MMD

.PHONY: clean run all

all: ./bin/chess.exe

-include build/src/*.d

./bin/chess.exe: ./build/main.o ./build/drawBoard.o ./build/move.o
	$(g) $(CFLAGS) -o ./bin/chess.exe ./build/main.o ./build/move.o ./build/drawBoard.o -lm

./build/main.o: ./src/main.cpp ./src/head.h
	$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/drawBoard.o: ./src/drawBoard.cpp ./src/head.h
	$(g) $(CFLAGS) -o ./build/drawBoard.o -c ./src/drawBoard.cpp -lm

./build/move.o: ./src/move.cpp ./src/head.h
	$(g) $(CFLAGS) -o ./build/move.o -c ./src/move.cpp -lm

clean:
	rm -rf build/*.o build/*.d

run:
	./bin/chess.exe
