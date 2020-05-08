#include "auxiliares.h"

/*
  get_string: char* -> int
  Le uma string da stdin ate encontrar o carater ':' ou '\n' ou exceder o
  limite de carateres lidos STR_MAX; Retorna o numero de carateres lidos
*/
int get_string(char* arg){
    char c;
    int i = 0;

    c = getchar();
    while(c != ':' && c != '\n' && i < STR_MAX - 1){
        arg[i++] = c;
        c = getchar();
    }

    /*Limpa a stdin ate encontrar ':', '\n' ou EOF*/
    while(c != ':' && c != '\n')
        c = getchar();

    /*Termina a string com null byte*/
    arg[i++] = '\0';

    return i;
}

