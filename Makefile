# Compiler options
CC := gcc
CFLAGS := -Wall -Wextra -pedantic -Ofast -MMD -pthread -march=native -funroll-loops -fomit-frame-pointer -flto
LDFLAGS := -flto

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

# Dependency files
DEP_FILES := $(OBJ_FILES:.o=.d)

# Targets
all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(PROJECT_NAME)

-include $(DEP_FILES)

.PHONY: all clean
