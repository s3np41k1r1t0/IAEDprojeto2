#include "estruturas_equipa.h"

No_Equipa *equipas;
Lista_Eq lista_equipas;

/* HANDLERS ELEMENTO DA HASH TABLE */
No_Equipa push_equipa(No_Equipa atual, Equipa eq){
    No_Equipa novo;

    novo = malloc(sizeof(struct no_equipa));
    novo->eq = eq;

    if(atual != NULL)
        novo->proximo = atual;

    else
        novo->proximo = NULL;

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

void print_vencedores(unsigned int NL){
    No_Equipa temp;
    Equipa *vencedores;
    int i, size = 0;

    if(lista_equipas->primeiro == NULL)
        return;
   
    temp = lista_equipas->primeiro;
    
    printf("%u Melhores %d\n",NL,lista_equipas->max);

    vencedores = malloc(sizeof(Equipa));

    while(temp != NULL){
        if(jogos_ganhos(temp->eq) == lista_equipas->max){
            vencedores[size++] = temp->eq;
            vencedores = realloc(vencedores,(size+1)*sizeof(Equipa));
        } 
        
        temp = temp->inserido_prox;
    }

    ordena_por_nome(vencedores,size);

    for(i=0; i<size; i++)
        printf("%u * %s\n",NL,nome_equipa(vencedores[i]));

    free(vencedores);
}

void troca(Equipa* a, Equipa* b){
    Equipa t = *a;
    *a = *b;
    *b = t;
}

void ordena_por_nome(Equipa* eq, int size){
    int i,j,min;

    for(i=0; i<size; i++){
        min = i;

        for (j=i+1; j < size; j++){
            if(strcmp(eq[j]->nome,eq[min]->nome) < 0){
                min = j;
            }
        }

        troca(&eq[i],&eq[min]);
    }
}

