#include "estruturas_equipa.h"

static no_equipa *equipas;

/* HANDLERS ELEMENTO DA HASH TABLE */
no_equipa push_equipa(no_equipa head, Equipa eq){
    no_equipa novo;

    novo = malloc(sizeof(struct No_Equipa));

    novo->eq = eq;
    novo->next = head;

    return novo;
}

Equipa procura_lista(no_equipa no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,nome_equipa(no->eq)))
            return no->eq;

        no = no->next;
    }

    return NULL;
}

void free_lista(no_equipa head){
    no_equipa temp;

    while(head != NULL){
        temp = head->next;
        free_equipa(head->eq);
        free(head);
        head = temp;
    }
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

void insere_equipa(Equipa eq){
    int ind;
    
    ind = hash(eq->nome,M_equipas);
    
    equipas[ind] = push_equipa(equipas[ind],eq);
}

Equipa procura_equipa(char* nome){
    int ind;

    ind = hash(nome,M_equipas);
    
    return procura_lista(equipas[ind],nome);
}

