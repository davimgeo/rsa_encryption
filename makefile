# Tool macros
CC ?= gcc
CFLAGS := -Wall -Wextra
DBGFLAGS := -g
COBJFLAGS := $(CFLAGS) -c

# Path macros
BIN_PATH := bin
OBJ_PATH := build
SRC_PATH := src
TEST_PATH := tests

# Compile macros
TARGET_NAME := run
TARGET := $(BIN_PATH)/$(TARGET_NAME)

# Source files
SRC := $(wildcard $(SRC_PATH)/*.c) $(wildcard $(SRC_PATH)/ssh/*.c) $(TEST_PATH)/temp_main.c
OBJ := $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

# Clean files list
CLEAN_LIST := $(TARGET) $(OBJ)

# Default rule
default: makedir all

# Build target
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(COBJFLAGS) -o $@ $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/ssh/%.c
	$(CC) $(COBJFLAGS) -o $@ $<

$(OBJ_PATH)/%.o: $(TEST_PATH)/%.c
	$(CC) $(COBJFLAGS) -o $@ $<

# Phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

