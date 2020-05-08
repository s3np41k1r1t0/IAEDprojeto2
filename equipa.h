#ifndef EQUIPA_H_DEFINE
#define EQUIPA_H_DEFINE

#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"

#define M_equipas 31

typedef struct Equipa{
    char* nome;
    int ganhos;
} equipa;

typedef struct No_Equipa{
    equipa *eq;
    struct No_Equipa *next;
} *no_equipa;

typedef struct Melhor_Equipa{
    int max;
    no_equipa no;
} melhor_equipa;

int hash(char* s, int m);
void free_lista(no_equipa head);

equipa* cria_equipa(char* nome, int size_nome);
char* obtem_nome(equipa* eq);
void adiciona_vitoria(equipa* eq);
void remove_vitoria(equipa* eq);

no_equipa push(no_equipa head, equipa* eq);

void inicializa_equipas();
void destroi_equipas();
void insere_equipa(equipa* eq);
equipa* procura_equipa(char* nome);
equipa* procura_lista(no_equipa no, char* nome);

#endif
