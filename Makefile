# Makefile for Student Grade Manager program

CC = gcc
CFLAGS = -Wall -g
TARGET = student

all: $(TARGET)

$(TARGET): student.c
	$(CC) $(CFLAGS) -o $(TARGET) student.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
