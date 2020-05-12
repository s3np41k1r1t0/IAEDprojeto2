#include "estruturas_equipa.h"

void init_hashtable_equipas(Equipas_HT hashtable){
    int i;
    
    for(i=0; i<M_equipas; i++)
        hashtable[i] = NULL;
}

Lista_Equipas init_lista_equipas(){
    return calloc(1,sizeof(struct lista_equipas));
}

void insere_equipa(Equipas_HT hashtable, Lista_Equipas lista_equipas, Equipa equipa){
    int ind;

    ind = hash(equipa->nome,M_equipas);

    hashtable[ind] = push_equipa_ht(hashtable[ind],equipa);

    push_equipa_ll(lista_equipas, equipa);
}

No_Equipa push_equipa_ht(No_Equipa atual, Equipa equipa){
    No_Equipa novo;

    novo = malloc(sizeof(struct no_equipa));
    novo->equipa = equipa;
    novo->prox = atual;

    return novo;
}

void push_equipa_ll(Lista_Equipas lista_equipas, Equipa equipa){
    No_Equipa novo;

    novo = malloc(sizeof(struct no_equipa));
    novo->equipa = equipa;
    novo->prox = NULL;

    if(lista_equipas->primeiro == NULL)
        lista_equipas->primeiro = novo;

    else
        lista_equipas->ultimo->prox = novo;
    
    lista_equipas->ultimo = novo;
}

Equipa procura_equipa(Equipas_HT hashtable, char* nome){
    int ind;

    ind = hash(nome,M_equipas);
    
    return procura_ht_equipas(hashtable[ind],nome);
}

Equipa procura_ht_equipas(No_Equipa no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,nome_equipa(no->equipa)))
            return no->equipa;

        no = no->prox;
    }

    return NULL;
}

Equipa remove_equipa_ht(Equipas_HT hashtable, char* nome){
    int ind;
    Equipa equipa;
    No_Equipa no, ant = NULL;
    
    ind = hash(nome,M_equipas);
    no = hashtable[ind];

    while(no != NULL){
        if(!strcmp(nome,nome_equipa(no->equipa)))
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

    equipa = no->equipa;
    free(no);
    return equipa;
}

Equipa remove_equipa_ll(Lista_Equipas equipas, char* nome){
    Equipa equipa;
    No_Equipa no, ant = NULL;
    no = equipas->primeiro;

    while(no != NULL){
        if(!strcmp(nome,nome_equipa(no->equipa)))
            break;

        ant = no;
        no = no->prox;
    }

    if(no == NULL)
        return NULL;

    if(ant == NULL)
        equipas->primeiro = no->prox;

    else{
        ant->prox = no->prox;    
        equipas->ultimo = ant;
    }

    equipa = no->equipa;
    free(no);
    return equipa;
}

void destroi_hashtable_equipas(Equipas_HT hashtable){
    int i;

    for(i=0; i<M_equipas; i++)
        free(hashtable[i]);
}

void destroi_lista_equipas(Lista_Equipas equipas){
    free(equipas);
}

void destroi_equipas(Lista_Equipas equipas){
    No_Equipa no, temp;
    no = equipas->primeiro;

    while(no != NULL){
        temp = no->prox;
        free_equipa(no->equipa);  
        free(no);      
        no = temp;
    }
}

void print_vencedores(Lista_Equipas lista_equipas, unsigned int NL){
    No_Equipa temp;
    char **vencedores;
    int i, size = 0;

    if(lista_equipas->primeiro == NULL)
        return;
   
    temp = lista_equipas->primeiro;
    
    printf("%u Melhores %d\n",NL,lista_equipas->max);

    vencedores = malloc(sizeof(char *));

    while(temp != NULL){
        if(jogos_ganhos(temp->equipa) == lista_equipas->max){
            vencedores[size++] = nome_equipa(temp->equipa);
            vencedores = realloc(vencedores,(size+1)*sizeof(char *));
        } 
        
        temp = temp->prox;
    }

    qsort(vencedores,size,sizeof(char*),compara_strings);

    for(i=0; i<size; i++)
        printf("%u * %s\n",NL,vencedores[i]);

    free(vencedores);
}

void atualiza_maximo(Equipa eq, Lista_Equipas lista_equipas){
    if(jogos_ganhos(eq) > lista_equipas->max)
        lista_equipas->max = jogos_ganhos(eq);
}
