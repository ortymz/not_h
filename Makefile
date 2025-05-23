CC := cc
INCLUDE := include
TESTS := tests
BUILD := build

FLAGS := `cat ./compile_flags.txt`

MATRIX_test := $(TESTS)/MATRIX!_test.c
MATRIX_H := $(INCLUDE)/MATRIX!.h
LOG_test := $(TESTS)/LOG!_test.c
LOG_H := $(INCLUDE)/LOG!.h

.PHONY: all

all: $(BUILD)/LOG!_test $(BUILD)/MATRIX!_test

$(BUILD)/LOG!_test: $(LOG_test) $(INCLUDE)/LOG!.h $(BUILD)/
	$(CC) $(LOG_test) -o $(BUILD)/LOG!_test $(FLAGS)

$(BUILD)/MATRIX!_test: $(MATRIX_test) $(INCLUDE)/MATRIX!.h $(BUILD)/
	$(CC) $(MATRIX_test) -o $(BUILD)/MATRIX!_test $(FLAGS)

$(BUILD)/:
	mkdir $(BUILD)

clean:
	rm -rf build
