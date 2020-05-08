#ifndef ESTRUTURAS_JOGO_H_INCLUDE
#define ESTRUTURAS_JOGO_H_INCLUDE

#include <stdlib.h>
#include <string.h>
#include "jogo.h"

#define M_jogos 31

typedef struct no_jogo{
    Jogo jg;
    struct no_jogo* proximo;
    struct no_jogo* anterior;
} *No_Jogo;

typedef struct Lista_Jogos{
    No_Jogo primeiro;
    No_Jogo ultimo;
} lista_jg;

void inicializa_jogos();
void insere_jogo(Jogo jg);
No_Jogo push_jogo(No_Jogo lista, Jogo jg);

#endif
