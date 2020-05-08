#include "jogo.h"

static no_jogo *jogos;

jogo* cria_jogo(char* nome, int size_nome, equipa* equipa1, equipa* equipa2, int score1, int score2){
    jogo* novo;

    novo = malloc(sizeof(jogo));
    novo->nome = malloc(sizeof(char)*size_nome);
    novo->equipa1 = equipa1;
    novo->equipa2 = equipa2;
    novo->score1 = score1;
    novo->score2 = score2;

    strncpy(novo->nome,nome,size_nome);

    if(score1 > score2)
        adiciona_vitoria(equipa1);
    
    else if(score1 < score2)
        adiciona_vitoria(equipa2);
    
    return novo;
}

/* HASH TABLE */

void inicializa_jogo(){
    int i;

    jogos = malloc(M_equipas*sizeof(no_jogo));

    for(i=0;i<M_equipas;i++)
        jogos[i] = NULL;         
}
