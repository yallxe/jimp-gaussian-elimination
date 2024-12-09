# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable
TARGET = bin/gauss

# Source files
SRCS = src/main.c src/mat_io.c src/gauss.c src/backsubst.c

# Object files (derived from SRCS)
OBJS = $(SRCS:src/%.c=bin/%.o)

# Default target
all: build_dir $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to create object files
bin/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
build_dir:
	mkdir -p bin

# Clean build artifacts
clean:
	rm -f bin/*.o $(TARGET)