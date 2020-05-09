#ifndef ESTRUTURAS_JOGO_H_INCLUDE
#define ESTRUTURAS_JOGO_H_INCLUDE

#include <stdlib.h>
#include <string.h>
#include "jogo.h"

#define M_jogos 31

typedef struct no_jogo{
    Jogo jg;
    
    struct no_jogo* proximo;
    
    struct no_jogo* inserido_prox;
    struct no_jogo* inserido_ant;
} *No_Jogo;

typedef struct Lista_Jogos{
    No_Jogo primeiro;
    No_Jogo ultimo;
} *lista_jg;

No_Jogo push_jogo(No_Jogo lista, Jogo jg);
Jogo procura_lista_jogos(No_Jogo no, char* nome);
No_Jogo procura_no_jogos(char* nome);
void free_lista_jogos(No_Jogo no);
void print_todos_jogos(unsigned int NL); 

void inicializa_jogos();
void destroi_jogos();
void insere_jogo(Jogo jg);
Jogo procura_jogo(char* nome);
Jogo remove_no_jogo(No_Jogo rem);
#endif
