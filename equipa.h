#ifndef EQUIPA_H_DEFINE
#define EQUIPA_H_DEFINE

/*INCLUDES*/
#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"

/*MACROS*/
#define nome_equipa(a) (a->nome)
#define jogos_ganhos(a) (a->ganhos)

/*
  Equipa: char*, int
  Ponteiro para uma equipa que consiste numa string nome
  e num inteiro que guarda os jogos ganhos pela equipa
*/
typedef struct equipa{
    char* nome;
    int ganhos;
} *Equipa;

/*PROTOTIPOS*/

Equipa cria_equipa(char* nome, int size_nome);
void adiciona_vitoria(Equipa eq);
void remove_vitoria(Equipa eq);
void free_equipa(Equipa eq);

#endif
