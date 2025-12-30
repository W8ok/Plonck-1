# Generic Makefile i stole from the internet :3
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -I.
TARGET = Plonck-1

# All source files
SRCS = main.c #\
			 #other.c

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

# Run the program (builds if needed)
run: $(TARGET)
	./$(TARGET)

# Phony targets (not actual files)
.PHONY: all clean run
