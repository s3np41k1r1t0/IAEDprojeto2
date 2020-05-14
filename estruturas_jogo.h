#ifndef ESTRUTURAS_JOGO_H_INCLUDE
#define ESTRUTURAS_JOGO_H_INCLUDE

#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "estruturas_equipa.h"

#define M_jogos 1029

typedef struct no_jogo{
    Jogo jogo;
    
    struct no_jogo* prox;

    struct no_jogo* prox_inserido;
    struct no_jogo* ant_inserido;
} *No_Jogo;

typedef No_Jogo Jogos_HT[M_jogos];

typedef struct jogos{
    No_Jogo primeiro;
    No_Jogo ultimo;
    
    Jogos_HT ht;
} *Jogos;

Jogos init_jogos();

void insere_jogo(Jogos jogos, Jogo jogo);
No_Jogo push_jogo(No_Jogo atual, Jogo jogo);

Jogo procura_jogo(Jogos jogos, char* nome);
Jogo procura_ht_jogos(No_Jogo no, char* nome);

Jogo remove_jogos(Jogos jogos, char* nome);

void print_todos_jogos(Jogos jogos, unsigned int NL);

void destroi_jogos(Jogos jogos);

#endif
