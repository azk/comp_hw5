BISON=bison -d
LEX=flex
CC=g++
EXEC_NAME=ex5.exe
CFLAGS=-Wno-write-strings

all: coins

coins: bison lex
		$(CC) $(CFLAGS) *.cpp *.c -o $(EXEC_NAME)
		
bison:
		$(BISON) coins.ypp
		
lex: bison
		$(LEX) coins.lex
