#include "equipa.h"

Equipa cria_equipa(char* nome, int size_nome){
    Equipa nova;
        
    nova = malloc(sizeof(struct equipa));
    nova->nome = malloc(size_nome*sizeof(char));
    nova->ganhos = 0;

    strncpy(nova->nome,nome,size_nome);

    return nova;
}

void adiciona_vitoria(Equipa eq){
    eq->ganhos += 1;
}

void remove_vitoria(Equipa eq){
    if(eq->ganhos>0)
        eq->ganhos -= 1;
}

void free_equipa(Equipa eq){
    free(nome_equipa(eq));
    free(eq);
}
