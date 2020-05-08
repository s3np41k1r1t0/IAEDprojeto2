#include "equipa.h"

static no_equipa *equipas;

int hash(char* s, int m){
    return ((int)*s + (int)*(s+strlen(s)-1)) % m;
}

void free_lista(no_equipa head){
    no_equipa temp;

    while(head != NULL){
        temp = head->next;
        free(head->eq->nome);
        free(head->eq);
        free(head);
        head = temp;
    }
}

/* HANDLER EQUIPAS */
equipa* cria_equipa(char* nome, int size_nome){
    equipa* nova;
        
    nova = malloc(sizeof(equipa));
    nova->nome = malloc(size_nome*sizeof(char));
    nova->ganhos = 0;

    strncpy(nova->nome,nome,size_nome);

    return nova;
}

char* obtem_nome(equipa* eq){
    return eq->nome;
}

void adiciona_vitoria(equipa* eq){
    eq->ganhos += 1;
}

void remove_vitoria(equipa* eq){
    if(eq->ganhos>0)
        eq->ganhos -= 1;
}

/* HANDLERS ELEMENTO DA HASH TABLE */
no_equipa push(no_equipa head, equipa* eq){
    no_equipa novo;

    novo = malloc(sizeof(struct No_Equipa));

    novo->eq = eq;
    novo->next = head;

    return novo;
}

/* HASH TABLE */
void inicializa_equipas(){
    int i;

    equipas = malloc(M_equipas*sizeof(no_equipa));

    for(i=0;i<M_equipas;i++)
        equipas[i] = NULL;         
}

void destroi_equipas(){
    int i;

    for(i=0; i<M_equipas; i++)
        free_lista(equipas[i]);

    free(equipas);
}

void insere_equipa(equipa* eq){
    int ind;
    
    ind = hash(eq->nome,M_equipas);
    
    equipas[ind] = push(equipas[ind],eq);
}

equipa* procura_equipa(char* nome){
    int ind;

    ind = hash(nome,M_equipas);
    
    return procura_lista(equipas[ind],nome);
}

equipa* procura_lista(no_equipa no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,no->eq->nome))
            return no->eq;

        no = no->next;
    }

    return NULL;
}

