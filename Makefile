g = g++
CFLAGS = -Wall -MP -MMD -std=c++14

.PHONY: clean run all

all: ./bin/chess

-include build/src/.d

./bin/chess: ./build/main.o ./build/drawBoard.o ./build/move.o
    $(g) $(CFLAGS) -o ./bin/chess ./build/main.o ./build/move.o ./build/drawBoard.o

./build/main.o: ./src/main.cpp ./src/head.h
    $(g) $(CFLAGS) -o build/main.o -c src/main.cpp

./build/drawBoard.o: ./src/drawBoard.cpp ./src/head.h
    $(g) $(CFLAGS) -o ./build/drawBoard.o -c ./src/drawBoard.cpp

./build/move.o: ./src/move.cpp ./src/head.h
    $(g) $(CFLAGS) -o ./build/move.o -c ./src/move.cpp

test: bin/chessviz-test

bin/chessviz-test: build/test/main.o build/move.o
    $(g) -o bin/chessviz-test build/test/main.o build/move.o

build/test/main.o: test/main.cpp
    $(g) $(CFLAGS) -o build/test/main.o -c test/main.cpp

clean:
    rm -rf build/.o build/.d build/test/.o build/test/*.d

run:
    ./bin/chess

testRun:
    ./bin/chessviz-test
