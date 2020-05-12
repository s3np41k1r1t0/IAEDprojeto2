#include "estruturas_jogo.h"

/*No_Jogo *jogos;
Lista_jogo lista_jogos;*/

/* HASH TABLE */

void init_hashtable_jogos(Jogos_HT hashtable){
    int i;
    
    for(i=0; i<M_jogos; i++)
        hashtable[i] = NULL;
}

Lista_Jogos init_lista_jogos(){
    return calloc(1,sizeof(struct lista_jogos));
}

void insere_jogo(Jogos_HT hashtable, Lista_Jogos lista_jogos, Jogo jogo){
    int ind;

    ind = hash(jogo->nome,M_jogos);

    hashtable[ind] = push_jogo_ht(hashtable[ind],jogo);

    push_jogo_ll(lista_jogos, jogo);
}

No_Jogo push_jogo_ht(No_Jogo atual, Jogo jogo){
    No_Jogo novo;

    novo = malloc(sizeof(struct no_jogo));
    novo->jogo = jogo;
    novo->prox = atual;

    return novo;
}

void push_jogo_ll(Lista_Jogos lista_jogos, Jogo jogo){
    No_Jogo novo;

    novo = malloc(sizeof(struct no_jogo));
    novo->jogo = jogo;
    novo->prox = NULL;

    if(lista_jogos->primeiro == NULL)
        lista_jogos->primeiro = novo;

    else
        lista_jogos->ultimo->prox = novo;
    
    lista_jogos->ultimo = novo;
}

Jogo procura_jogo(Jogos_HT hashtable, char* nome){
    int ind;

    ind = hash(nome,M_jogos);
    
    return procura_ht_jogos(hashtable[ind],nome);
}

Jogo procura_ht_jogos(No_Jogo no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,nome_jogo(no->jogo)))
            return no->jogo;

        no = no->prox;
    }

    return NULL;
}

Jogo remove_jogo_ht(Jogos_HT hashtable, char* nome){
    int ind;
    Jogo jogo;
    No_Jogo no, ant = NULL;
    
    ind = hash(nome,M_jogos);
    no = hashtable[ind];

    while(no != NULL){
        if(!strcmp(nome,nome_jogo(no->jogo)))
            break;

        ant = no;
        no = no->prox;
    }

    if(no == NULL)
        return NULL;

    if(ant == NULL)
        hashtable[ind] = no->prox;

    else
        ant->prox = no->prox;    
    
    jogo = no->jogo;
    free(no);
    return jogo;
}

Jogo remove_jogo_ll(Lista_Jogos jogos, char* nome){
    Jogo jogo;
    No_Jogo no, ant = NULL;
    no = jogos->primeiro;

    while(no != NULL){
        if(!strcmp(nome,nome_jogo(no->jogo)))
            break;

        ant = no;
        no = no->prox;
    }

    if(no == NULL)
        return NULL;

    if(ant == NULL)
        jogos->primeiro = no->prox;

    else{
        ant->prox = no->prox;    
        jogos->ultimo = ant;
    }

    jogo = no->jogo;
    free(no);
    return jogo;
}

void print_todos_jogos(Lista_Jogos jogos, unsigned int NL){
    No_Jogo temp = jogos->primeiro;
    
    while(temp != NULL){
        /*melhorar abstracao*/
        printf("%u %s %s %s %d %d\n",NL,nome_jogo(temp->jogo),nome_equipa(temp->jogo->equipa1),nome_equipa(temp->jogo->equipa2),temp->jogo->score1,temp->jogo->score2);
        
        temp = temp->prox;
    }
}

void destroi_hashtable_jogos(Jogos_HT hashtable){
    int i;

    for(i=0; i<M_jogos; i++)
        free(hashtable[i]);
}

void destroi_lista_jogos(Lista_Jogos jogos){
    free(jogos);
}

void destroi_jogos(Lista_Jogos jogos){
    No_Jogo no, temp;
    no = jogos->primeiro;

    while(no != NULL){
        temp = no->prox;
        free_jogo(no->jogo);      
        free(no);
        no = temp;
    }
}