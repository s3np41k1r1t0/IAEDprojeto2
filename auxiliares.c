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
    while(c != ':' && c != '\n' && i < MAX_STR - 1){
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

int hash(char* s, int m){
    int i, len, sum = 0;
    len = strlen(s);

    for(i=0; i<len; i++) 
        sum += (int)s[i];
    
    return sum % m;
}

int compara_strings(const void *ptr1, const void *ptr2) { 
    const char **str1 = (const char **)ptr1;
    const char **str2 = (const char **)ptr2;
    return strcmp(*str1, *str2);
} 
