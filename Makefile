# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
BUILD_DIR = build

# Files
SOURCES = main.c alloc.c
EXECUTABLE = $(BUILD_DIR)/program

# Default target
all: $(BUILD_DIR) $(EXECUTABLE)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build the executable
$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Run the program
run: all
	$(EXECUTABLE)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
