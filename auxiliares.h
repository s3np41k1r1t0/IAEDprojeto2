#ifndef AUXILIARES_H_INCLUDE
#define AUXILIARES_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 1024

int get_string(char* arg);
int hash(char* s, int m);
int compara_strings(const void *ptr1, const void *ptr2);

#endif
