SRC_DIR := src
BIN_DIR := bin
CC := gcc
CFLAGS := -Wall -Wextra
SOURCES := $(wildcard $(SRC_DIR)/*.c)
EXECUTABLES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

all: $(EXECUTABLES)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)

install:
	cp -r $(BIN_DIR)/* /usr/local/bin/

