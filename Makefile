CC=gcc
CFLAGS=-ansi -Wall -Wextra -pedantic -fsanitize=address

test: test.c auxiliares.c
	$(CC) -o test test.c auxiliares.c
