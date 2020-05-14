#ifndef ESTRUTURAS_EQUIPA_H_INCLUDE
#define ESTRUTURAS_EQUIPA_H_INCLUDE

#include <stdlib.h>
#include <string.h>
#include "equipa.h"

#define M_equipas 1029


typedef struct no_equipa{
    Equipa equipa;
    
    struct no_equipa* prox;

    struct no_equipa* prox_inserido;
} *No_Equipa;

typedef No_Equipa Equipas_HT[M_equipas];

typedef struct equipas{
    No_Equipa primeiro;
    No_Equipa ultimo;

    Equipas_HT ht;
} *Equipas;

Equipas init_equipas();

void insere_equipa(Equipas equipas, Equipa equipa);
No_Equipa push_equipa(No_Equipa atual, Equipa equipa);

Equipa procura_equipa(Equipas equipas, char* nome);
Equipa procura_ht_equipas(No_Equipa no, char* nome);

Equipa remove_equipas(Equipas equipas, char* nome);

void destroi_equipas(Equipas equipas);

void print_vencedores(Equipas equipas, unsigned int NL);

#endif
