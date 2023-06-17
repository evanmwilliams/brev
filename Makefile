CC = g++
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c++17 -g -lncurses
TARGET = brev

$(TARGET): $(TARGET).cpp
	mkdir -p build && $(CC) -o build/$(TARGET) $(TARGET).cpp $(CFLAGS)

run: $(TARGET).cpp
	make && ./build/$(TARGET)

clean:  
	rm -rf build/*

.PHONY: clean