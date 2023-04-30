# Compiler options
CC := gcc
CFLAGS := -Wall -Wextra -pedantic -Ofast -MMD -march=native -funroll-loops -fomit-frame-pointer -flto
LDFLAGS := -flto -s

# Project name
HEADER_FILE := src/config_lib/info.h
PROJECT_NAME := $(shell grep '#define PROJECT_NAME' $(HEADER_FILE) | cut -d '"' -f 2)

# Directories
SRC_DIR := src
BUILD_DIR := build

# Source files
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Targets
all: $(PROJECT_NAME)
	@echo "$(PROJECT_NAME) compiled!"

$(PROJECT_NAME): $(OBJ_FILES)
	@echo "Linking object files..."
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling source code into object files..."
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD_DIR) $(PROJECT_NAME)

.PHONY: all clean
