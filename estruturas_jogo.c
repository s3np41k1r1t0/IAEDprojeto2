#include "estruturas_jogo.h"

No_Jogo *jogos;
lista_jg lista_jogos;

No_Jogo push_jogo(No_Jogo atual, Jogo jg){
    No_Jogo novo;

    novo = malloc(sizeof(struct no_jogo));
    novo->jg = jg;

    if(atual != NULL)
        novo->proximo = atual;
    

    else
        novo->proximo = NULL;

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

No_Jogo procura_no_jogos(char* nome){
    int ind;
    No_Jogo no;

    ind = hash(nome,M_jogos);
    no = jogos[ind];

    while(no != NULL){
        if(!strcmp(nome,nome_jogo(no->jg)))
            return no;

        no = no->proximo;
    }

    return NULL;
}

void free_lista_jogos(No_Jogo no){
    No_Jogo temp;

    while(no != NULL){
        temp = no->proximo;
        free_jogo(no->jg);
        free(no);
        no = temp;
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
    jogos = calloc(M_jogos,sizeof(No_Jogo));
    lista_jogos = calloc(1,sizeof(struct Lista_Jogos));
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

Jogo remove_no_jogo(No_Jogo rem){
    int ind;
    Jogo ret;
    
    ind = hash(nome_jogo(rem->jg),M_jogos);

    if(rem == jogos[ind])
        jogos[ind] = NULL;

    if(rem == lista_jogos->primeiro)
        lista_jogos->primeiro = rem->inserido_prox;

    if(rem == lista_jogos->ultimo)
        lista_jogos->ultimo = rem->inserido_ant;

    if(rem->inserido_prox != NULL)
        rem->inserido_prox->inserido_ant = rem->inserido_ant;

    if(rem->inserido_ant != NULL)
        rem->inserido_ant->inserido_prox = rem->inserido_prox;

    if(rem->proximo != NULL)
        jogos[ind] = rem->proximo;
    
    ret = rem->jg;

    free(rem);
    
    return ret;
}


