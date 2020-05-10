#ifndef EQUIPA_H_DEFINE
#define EQUIPA_H_DEFINE

#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"

#define nome_equipa(a) (a->nome)
#define jogos_ganhos(a) (a->ganhos)

typedef struct equipa{
    char* nome;
    int ganhos;
    int eh_max;
} *Equipa;

Equipa cria_equipa(char* nome, int size_nome);
void adiciona_vitoria(Equipa eq);
void remove_vitoria(Equipa eq);
void free_equipa(Equipa eq);

#endif
