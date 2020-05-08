#ifndef JOGO_H_INCLUDE
#define JOGO_H_INCLUDE

#include <stdlib.h>
#include <strings.h>
#include "equipa.h"
#include "auxiliares.h"

typedef struct Jogo {
    char* nome;
    equipa* equipa1;
    equipa* equipa2;
    int score1;
    int score2;
} jogo;

typedef struct No_Jogo{
    jogo* jg;
    struct Node* proximo;
    struct Node* anterior;
} *no_jogo;

typedef struct Lista_Jogos{
    no_jogo primeiro;
    no_jogo ultimo;
}

jogo* cria_jogo(char* nome, int size_nome, equipa* equipa1, equipa* equipa2, int score1, int score2);

#endif
