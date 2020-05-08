#ifndef ESTRUTURAS_EQUIPA_H_INCLUDE
#define ESTRUTURAS_EQUIPA_H_INCLUDE

#include <stdlib.h>
#include <string.h>
#include "equipa.h"

#define M_equipas 31

typedef struct No_Equipa{
    Equipa eq;
    struct No_Equipa *next;
} *no_equipa;

int hash(char* s, int m);

no_equipa push_equipa(no_equipa head, Equipa eq);
void free_lista(no_equipa head);
Equipa procura_equipa(char* nome);
Equipa procura_lista(no_equipa no, char* nome);

void inicializa_equipas();
void destroi_equipas();
void insere_equipa(Equipa eq);

#endif
