#include "estruturas_equipa.h"

Equipas init_equipas(){
    return calloc(1,sizeof(struct equipas));
}

void insere_equipa(Equipas equipas, Equipa equipa){
    int ind;

    ind = hash(equipa->nome,M_equipas);

    equipas->ht[ind] = push_equipa(equipas->ht[ind],equipa);

    if(equipas->primeiro == NULL)
        equipas->primeiro = equipas->ht[ind];

    else
        equipas->ultimo->prox_inserido = equipas->ht[ind];

    equipas->ht[ind]->prox_inserido = NULL;
    equipas->ultimo = equipas->ht[ind];
}

No_Equipa push_equipa(No_Equipa atual, Equipa equipa){
    No_Equipa novo;

    novo = malloc(sizeof(struct no_equipa));
    novo->equipa = equipa;
    novo->prox = atual;

    return novo;
}

Equipa procura_equipa(Equipas equipas, char* nome){
    int ind;

    ind = hash(nome,M_equipas);
    
    return procura_ht_equipas(equipas->ht[ind],nome);
}

Equipa procura_ht_equipas(No_Equipa no, char* nome){
    while(no != NULL){
        if(!strcmp(nome,nome_equipa(no->equipa)))
            return no->equipa;

        no = no->prox;
    }

    return NULL;
}

void destroi_equipas(Equipas equipas){
    No_Equipa temp;

    while(equipas->primeiro != NULL){
        temp = equipas->primeiro->prox_inserido;
        free_equipa(equipas->primeiro->equipa);      
        free(equipas->primeiro);
        equipas->primeiro = temp;
    }

    free(equipas);
}
void print_vencedores(Equipas equipas, unsigned int NL){
    No_Equipa temp;
    char **vencedores;
    int i, max, size_max, size = 0;

    if(equipas->primeiro == NULL)
        return;
   
    temp = equipas->primeiro;


    vencedores = malloc(sizeof(char *));

    max = 0;
    size_max = 0;
    while(temp != NULL){
        if(jogos_ganhos(temp->equipa) > max){
            max = jogos_ganhos(temp->equipa);
            size = 0;
            vencedores[size++] = nome_equipa(temp->equipa);
        }
                
        else if(jogos_ganhos(temp->equipa) == max){
            vencedores[size++] = nome_equipa(temp->equipa);
        } 
        
        if(size > size_max){
            vencedores = realloc(vencedores,(size+1)*sizeof(char *));
            size_max++;
        }

        temp = temp->prox_inserido;
    }

    printf("%u Melhores %d\n",NL,max);
    qsort(vencedores,size,sizeof(char*),compara_strings);

    for(i=0; i<size; i++)
        printf("%u * %s\n",NL,vencedores[i]);

    free(vencedores);
}
