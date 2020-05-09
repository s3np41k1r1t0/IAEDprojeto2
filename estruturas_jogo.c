#include "estruturas_jogo.h"

static No_Jogo *jogos;
static lista_jg lista_jogos;

No_Jogo push_jogo(No_Jogo atual, Jogo jg){
    No_Jogo novo;

    novo = malloc(sizeof(struct no_jogo));
    novo->jg = jg;

    if(atual != NULL){
        novo->anterior = NULL;
        novo->proximo = atual;
        atual->anterior = novo;
    }

    else{
        novo->proximo = NULL;
        novo->anterior = NULL;
    }

    if(lista_jogos->primeiro == NULL){
        lista_jogos->primeiro = novo;
        lista_jogos->ultimo = novo;
        novo->inserido_prox = NULL;
        novo->inserido_ant = NULL;
    }

    else{
        novo->inserido_ant = lista_jogos->ultimo;
        lista_jogos->ultimo->inserido_prox = novo;        
        novo->inserido_prox = NULL;
        lista_jogos->ultimo = novo;
    }

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

void print_todos_jogos(unsigned int NL){
    No_Jogo temp;

    if(lista_jogos->primeiro == NULL)
        return;
   
    temp = lista_jogos->primeiro;
    
    while(temp != NULL){
        /*melhorar abstracao*/
        printf("%u %s %s %s %d %d\n",NL,nome_jogo(temp->jg),nome_equipa(temp->jg->equipa1),nome_equipa(temp->jg->equipa2),temp->jg->score1,temp->jg->score2);
        
        temp = temp->inserido_prox;
    }
}

/* HASH TABLE */

void inicializa_jogos(){
    int i;

    jogos = malloc(M_jogos*sizeof(No_Jogo));

    for(i=0;i<M_jogos;i++)
        jogos[i] = NULL;

    lista_jogos = malloc(sizeof(struct Lista_Jogos));
    lista_jogos->primeiro = NULL;
    lista_jogos->ultimo = NULL;
}

void destroi_jogos(){
    int i;

    for(i=0; i<M_jogos; i++)
        free_lista_jogos(jogos[i]);

    free(jogos);
    free(lista_jogos);
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



