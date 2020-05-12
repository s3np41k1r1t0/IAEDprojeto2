#ifndef ESTRUTURAS_EQUIPA_H_INCLUDE
#define ESTRUTURAS_EQUIPA_H_INCLUDE

#include <stdlib.h>
#include <string.h>
#include "equipa.h"

#define M_equipas 1029

typedef struct no_equipa{
    Equipa equipa;
    struct no_equipa *prox;
} *No_Equipa;

typedef struct lista_equipas{
    No_Equipa primeiro;
    No_Equipa ultimo;
    int max;
} *Lista_Equipas;

typedef No_Equipa Equipas_HT[M_equipas];

void init_hashtable_equipas(Equipas_HT hashtable);
Lista_Equipas init_lista_equipas();

void insere_equipa(Equipas_HT hashtable, Lista_Equipas lista_equipas, Equipa equipa);
No_Equipa push_equipa_ht(No_Equipa atual, Equipa equipa);
void push_equipa_ll(Lista_Equipas lista_Equipas, Equipa equipa);

Equipa procura_equipa(Equipas_HT hashtable, char* nome);
Equipa procura_ht_equipas(No_Equipa no, char* nome);

Equipa remove_equipa_ht(Equipas_HT hashtable, char* nome);
Equipa remove_equipa_ll(Lista_Equipas equipas, char* nome);

void print_vencedores(Lista_Equipas Equipas, unsigned int NL);

void destroi_hashtable_equipas(Equipas_HT hashtable);
void destroi_lista_equipas(Lista_Equipas equipas);
void destroi_equipas(Lista_Equipas equipas);

void atualiza_maximo(Equipa equipa, Lista_Equipas lista_equipas);

#endif
