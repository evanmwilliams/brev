CC = g++
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c++17 -g
TARGET = brev

$(TARGET): $(TARGET).cpp
	$(CC) -o $(TARGET) $(TARGET).cpp $(CFLAGS)

run: $(TARGET).cpp
	make && ./$(TARGET)

clean:  
	rm -rf $(TARGET) $(TARGET).dSYM

.PHONY: clean