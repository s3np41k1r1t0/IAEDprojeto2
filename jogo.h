#ifndef JOGO_H_INCLUDE
#define JOGO_H_INCLUDE

#include <stdlib.h>
#include <strings.h>
#include "equipa.h"
#include "estruturas_equipa.h"
#include "auxiliares.h"

#define NULLjogo NULL
#define nome_jogo(a) (a->nome)
#define obtem_equipa1(a) (a->equipa1)
#define obtem_equipa2(a) (a->equipa2)

typedef struct jogo {
    char* nome;
    Equipa equipa1;
    Equipa equipa2;
    int score1;
    int score2;
} *Jogo;

Jogo cria_jogo(char* nome, int size_nome, Equipa equipa1, Equipa equipa2, int score1, int score2, Lista_Equipas ll_equipas);
void free_jogo(Jogo jg);
void remove_jogo(Jogo jg, Lista_Equipas ll_equipas);
void altera_score(Jogo jg, int score1, int score2, Lista_Equipas ll_equipas);

#endif
