CC=g++
TARGET= sha3
SRC = sha3.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
