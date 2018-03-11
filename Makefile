
CC = gcc
CFLAGS = -Iinclude 

TOP_PATH = $(shell pwd)
SRC_PATH = $(TOP_PATH)/src
BIN_PATH = $(TOP_PATH)

all: $(BIN_PATH)/test 

$(BIN_PATH)/test: $(SRC_PATH)/test_main.o $(SRC_PATH)/conf.o 
	$(CC) $(CFLAGS) -o $(BIN_PATH)/test $(SRC_PATH)/test_main.o $(SRC_PATH)/conf.o 

$(LIB_PATH)/voice.o: src/test_main.c
	$(CC) $(CFLAGS) -o src/test_main.o -c src/test_main.c

$(LIB_PATH)/conf.o: src/conf.c
	$(CC) $(CFLAGS) -o src/conf.o -c src/conf.c


clean:
	rm -rf test 
	rm -rf $(SRC_PATH)/conf.o $(SRC_PATH)/test_main.o
