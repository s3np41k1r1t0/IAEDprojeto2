#ifndef ESTRUTURAS_EQUIPA_H_INCLUDE
#define ESTRUTURAS_EQUIPA_H_INCLUDE

#include <stdlib.h>
#include <string.h>
#include "equipa.h"

#define M_equipas 1029

typedef struct no_equipa{
    Equipa eq;
    struct no_equipa *proximo;
        
    struct no_equipa* inserido_prox;
    struct no_equipa* inserido_ant;
} *No_Equipa;

typedef struct lista_eq{
    No_Equipa primeiro;
    No_Equipa ultimo;
    int max;
} *Lista_Eq;

No_Equipa push_equipa(No_Equipa atual, Equipa eq);
Equipa procura_lista_equipas(No_Equipa no, char* nome);
void free_lista_equipas(No_Equipa atual);

void inicializa_equipas();
void destroi_equipas();
void insere_equipa(Equipa eq);
Equipa procura_equipa(char* nome);
void atualiza_maximo(Equipa eq);
void print_vencedores(unsigned int NL);
void ordena_por_nome(Equipa* copia, int);

#endif
