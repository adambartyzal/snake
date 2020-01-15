CC = gcc
CFLAGS += -pedantic -Wall -std=c99 -g -O0
DEPS = types.h
OBJ = main.o field.o snake.o
TARGET = snake
ZIP=zip

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) *.o
	$(RM) $(TARGET)

.PHONY: clean
