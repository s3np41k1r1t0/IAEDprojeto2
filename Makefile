CC=gcc
CFLAGS=-ansi -Wall -Wextra -pedantic

test: *.c
	$(CC) $(CFLAGS) -o projeto *.c 
