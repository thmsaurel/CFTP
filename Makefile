#******************************************************************************
#name            : Makefile
#date            : 25 novembre 2014 
#created by      : loic
#last modified   : 25 novembre 2014 14:45:01
#purpose:
#******************************************************************************/

CC					:=gcc
CFLAGS				:=-ansi -pedantic -Wall -Werror -std=c99 -g
RM					:=rm -f
OBJ_FILE			:=$(wildcard *.o)
EXEC_FILE			:=main
SRC_C				:=$(wildcard *.c)

all: compile

run: clean compile execute

clean: 
	$(RM) $(OBJ_FILE) $(EXEC_FILE)

compile: 
	$(CC) -o $(EXEC_FILE) $(SRC_C) $(CFLAGS)

execute:
	./$(EXEC_FILE)
