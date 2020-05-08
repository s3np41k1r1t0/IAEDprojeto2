#include "estruturas_jogo.h"

static No_Jogo *jogos;
static lista_jg lista_jogos;

No_Jogo push_jogo(No_Jogo atual, Jogo jg){
    No_Jogo novo;

    novo = malloc(sizeof(struct no_jogo));

    novo->jg = jg;
    novo->anterior = NULL;
    novo->proximo = atual;

    return novo;
}

Jogo procura_lista_jogos(No_Jogo no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,nome_jogo(no->jg)))
            return no->jg;

        no = no->proximo;
    }

    return NULL;
}

void free_lista_jogos(No_Jogo head){
    No_Jogo temp;

    while(head != NULL){
        temp = head->proximo;
        free_jogo(head->jg);
        free(head);
        head = temp;
    }
}

/* HASH TABLE */

void inicializa_jogos(){
    int i;

    jogos = malloc(M_jogos*sizeof(No_Jogo));

    for(i=0;i<M_jogos;i++)
        jogos[i] = NULL; 
}

void destroi_jogos(){
    int i;

    for(i=0; i<M_jogos; i++)
        free_lista_jogos(jogos[i]);

    free(jogos);
}

void insere_jogo(Jogo jg){
    int ind;

    ind = hash(jg->nome,M_jogos);

    jogos[ind] = push_jogo(jogos[ind],jg);
}

Jogo procura_jogo(char* nome){
    int ind;

    ind = hash(nome,M_jogos);
    
    return procura_lista_jogos(jogos[ind],nome);
}

/*
 * vou ignorar o remove por equanto
 */



