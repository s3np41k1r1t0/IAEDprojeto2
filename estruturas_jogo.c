#include "estruturas_jogo.h"

Jogos init_jogos(){
    return calloc(1,sizeof(struct jogos));
}

void insere_jogo(Jogos jogos, Jogo jogo){
    int ind;

    ind = hash(jogo->nome,M_jogos);

    jogos->ht[ind] = push_jogo(jogos->ht[ind],jogo);

    if(jogos->primeiro == NULL){
        jogos->primeiro = jogos->ht[ind];
        jogos->ht[ind]->ant_inserido = NULL;
    }

    else{
        jogos->ht[ind]->ant_inserido = jogos->ultimo;
        jogos->ultimo->prox_inserido = jogos->ht[ind];
    }

    jogos->ht[ind]->prox_inserido = NULL;
    jogos->ultimo = jogos->ht[ind];
}

No_Jogo push_jogo(No_Jogo atual, Jogo jogo){
    No_Jogo novo;

    novo = malloc(sizeof(struct no_jogo));
    novo->jogo = jogo;
    novo->prox = atual;

    return novo;
}

Jogo procura_jogo(Jogos jogos, char* nome){
    int ind;

    ind = hash(nome,M_jogos);
    
    return procura_ht_jogos(jogos->ht[ind],nome);
}

Jogo procura_ht_jogos(No_Jogo no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,nome_jogo(no->jogo)))
            return no->jogo;

        no = no->prox;
    }

    return NULL;
}

Jogo remove_jogos(Jogos jogos, char* nome){
    int ind;
    Jogo jogo;
    No_Jogo no, ant;
    
    ind = hash(nome,M_jogos);
    no = jogos->ht[ind];

    while(no != NULL){
        if(!strcmp(nome,nome_jogo(no->jogo)))
            break;

        ant = no;
        no = no->prox;
    }

    if(no == NULL)
        return NULL;

    /*Resolves hash table*/
    if(no == jogos->ht[ind])   
        jogos->ht[ind] = no->prox;

    else
        ant->prox = no->prox;
    
    /*Resolves ll*/
    if(no->ant_inserido != NULL && no->prox_inserido != NULL){
        no->ant_inserido->prox_inserido = no->prox_inserido;
        no->prox_inserido->ant_inserido = no->ant_inserido;
    }
    
    else{ 
        if(no == jogos->primeiro){
            jogos->primeiro = no->prox_inserido;
            
            if(no->prox_inserido != NULL)
                no->prox_inserido->ant_inserido = NULL;
        }

        if(no == jogos->ultimo){
            jogos->ultimo = no->ant_inserido;
            
            if(no->ant_inserido != NULL)
                no->ant_inserido->prox_inserido = NULL;
        }
    }
    
    jogo = no->jogo;
    free(no);
    return jogo;
}

void print_todos_jogos(Jogos jogos, unsigned int NL){
    No_Jogo temp = jogos->primeiro;
    
    while(temp != NULL){
        /*melhorar abstracao*/
        printf("%u %s %s %s %d %d\n",NL,nome_jogo(temp->jogo),nome_equipa(temp->jogo->equipa1),
               nome_equipa(temp->jogo->equipa2),temp->jogo->score1,temp->jogo->score2);
        
        temp = temp->prox_inserido;
    }
}

void destroi_jogos(Jogos jogos){
    No_Jogo temp;

    while(jogos->primeiro != NULL){
        temp = jogos->primeiro->prox_inserido;
        free_jogo(jogos->primeiro->jogo);      
        free(jogos->primeiro);
        jogos->primeiro = temp;
    }

    free(jogos);
}
