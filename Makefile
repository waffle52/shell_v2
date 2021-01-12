CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -pedantic
DEPS = *.h
OBJ = *.o
C_FILES = *.c
TARGET=hsh

default: compile

compile:
	$(CC) $(CFLAGS) $(C_FILES) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f $(TARGET)
