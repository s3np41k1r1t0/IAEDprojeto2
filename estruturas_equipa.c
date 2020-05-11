#include "estruturas_equipa.h"

No_Equipa *equipas;
Lista_Eq lista_equipas;

/* I can avoid having a double linked list if i do linear probing */
No_Equipa push_equipa(No_Equipa atual, Equipa eq){
    No_Equipa novo;

    novo = malloc(sizeof(struct no_equipa));
    novo->eq = eq;
    novo->proximo = atual;

    if(lista_equipas->primeiro == NULL){
        lista_equipas->primeiro = novo;
        lista_equipas->ultimo = novo;
        novo->inserido_prox = NULL;
        novo->inserido_ant = NULL;
    }

    else{
        novo->inserido_ant = lista_equipas->ultimo;
        lista_equipas->ultimo->inserido_prox = novo;        
        novo->inserido_prox = NULL;
        lista_equipas->ultimo = novo;
    }

    return novo;
}

Equipa procura_lista_equipas(No_Equipa no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,nome_equipa(no->eq)))
            return no->eq;

        no = no->proximo;
    }

    return NULL;
}

void free_lista_equipas(No_Equipa atual){
    No_Equipa temp;

    while(atual != NULL){
        temp = atual->proximo;
        free_equipa(atual->eq);
        free(atual);
        atual = temp;
    }
}

/* HASH TABLE */
void inicializa_equipas(){
    equipas = calloc(M_equipas,sizeof(No_Equipa));
    lista_equipas = calloc(1,sizeof(struct lista_eq));
}

void destroi_equipas(){
    int i;

    for(i=0; i<M_equipas; i++)
        free_lista_equipas(equipas[i]);

    free(equipas);
    free(lista_equipas);
}

void insere_equipa(Equipa eq){
    int ind;
    
    ind = hash(eq->nome,M_equipas);
    
    equipas[ind] = push_equipa(equipas[ind],eq);
}

Equipa procura_equipa(char* nome){
    int ind;

    ind = hash(nome,M_equipas);
    
    return procura_lista_equipas(equipas[ind],nome);
}

void atualiza_maximo(Equipa eq){
    if(jogos_ganhos(eq) > lista_equipas->max)
        lista_equipas->max = jogos_ganhos(eq);
}

int compara_strings(const void *ptr1, const void *ptr2) { 
    const char **str1 = (const char **)ptr1;
    const char **str2 = (const char **)ptr2;
    return strcmp(*str1, *str2);
} 

void print_vencedores(unsigned int NL){
    No_Equipa temp;
    char **vencedores;
    int i, size = 0;

    if(lista_equipas->primeiro == NULL)
        return;
   
    temp = lista_equipas->primeiro;
    
    printf("%u Melhores %d\n",NL,lista_equipas->max);

    vencedores = malloc(sizeof(Nome_Equipa));

    while(temp != NULL){
        if(jogos_ganhos(temp->eq) == lista_equipas->max){
            vencedores[size++] = nome_equipa(temp->eq);
            vencedores = realloc(vencedores,(size+1)*sizeof(Nome_Equipa));
        } 
        
        temp = temp->inserido_prox;
    }

    qsort(vencedores,size,sizeof(char*),compara_strings);

    for(i=0; i<size; i++)
        printf("%u * %s\n",NL,vencedores[i]);

    free(vencedores);
}

