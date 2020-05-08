#ifndef JOGO_H_INCLUDE
#define JOGO_H_INCLUDE

#include <stdlib.h>
#include <strings.h>
#include "equipa.h"
#include "auxiliares.h"

#define NULLjogo NULL
#define nome_jogo(a) (a->nome)

typedef struct jogo {
    char* nome;
    Equipa equipa1;
    Equipa equipa2;
    int score1;
    int score2;
} *Jogo;

Jogo cria_jogo(char* nome, int size_nome, Equipa equipa1, Equipa equipa2, int score1, int score2);
void free_jogo(Jogo jg);

#endif
