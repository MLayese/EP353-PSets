CC = gcc

FLAGS  = -pipe

CFLAGS  = -Wall
CFLAGS += -O2

LIBRARIES =

SRC = $(shell find ./src -name '*.c')
OBJ = $(subst .c,.o,$(SRC))
BIN = ./bin

PREFIX    = /usr/local
MANPREFIX = $(PREFIX)/share/man

TARGET = testrun

MAKEFLAGS += --jobs=4

all : $(OBJ)
	@echo LD $@
	@$(CC) $(FLAGS) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBRARIES)

.c.o :
	@echo CC $<
	@$(CC) $(FLAGS) $(CFLAGS) $(LIBRARIES) $(DEFINITIONS) -c $< -o $@

install : all

uninstall :

clean :
	find . -type f -name '*.o' -delete
	rm -rf $(BIN)/*