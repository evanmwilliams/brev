CC = g++
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c++17 -g -lncurses
TARGET=main

$(TARGET): $(TARGET).cpp TextBuffer.cpp PieceTable.cpp
	mkdir -p build && $(CC) -o build/$(TARGET) $(TARGET).cpp TextBuffer.cpp PieceTable.cpp $(CFLAGS)

run: $(TARGET).cpp
	make && ./build/$(TARGET)

clean:  
	rm -rf build/*

.PHONY: clean