# Makefile for Plonck-1 Emulator
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -I.
TARGET = Plonck-1

# All your source files
SRCS = logic_gates.c \
      	cpu.c \
        memory.c \
        main.c

# Convert .c files to .o files
OBJS = $(SRCS:.c=.o)

# Default target: build everything
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile any .c file to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Run the emulator (builds if needed)
run: $(TARGET)
	./$(TARGET)

# Phony targets (not actual files)
.PHONY: all clean run
