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
} *No_Jogo;

typedef struct lista_jogos{
    No_Jogo primeiro;
    No_Jogo ultimo;
} *Lista_Jogos;

typedef No_Jogo Jogos_HT[M_jogos];

void init_hashtable_jogos(Jogos_HT hashtable);
Lista_Jogos init_lista_jogos();

void insere_jogo(Jogos_HT hashtable, Lista_Jogos lista_jogos, Jogo jogo);
No_Jogo push_jogo_ht(No_Jogo atual, Jogo jogo);
void push_jogo_ll(Lista_Jogos lista_jogos, Jogo jogo);

Jogo procura_jogo(Jogos_HT hashtable, char* nome);
Jogo procura_ht_jogos(No_Jogo no, char* nome);

Jogo remove_jogo_ht(Jogos_HT hashtable, char* nome);
Jogo remove_jogo_ll(Lista_Jogos jogos, char* nome);

void print_todos_jogos(Lista_Jogos jogos, unsigned int NL);

void destroi_hashtable_jogos(Jogos_HT hashtable);
void destroi_lista_jogos(Lista_Jogos jogos);
void destroi_jogos(Lista_Jogos jogos);

void inicializa_jogos();


#endif
