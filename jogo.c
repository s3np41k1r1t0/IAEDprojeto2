#include "jogo.h"

Jogo cria_jogo(char* nome, int size_nome, Equipa equipa1, Equipa equipa2, int score1, int score2){
    Jogo novo;

    novo = malloc(sizeof(struct jogo));
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

void free_jogo(Jogo jg){
    if(jg != NULL){
        free(nome_jogo(jg));
        free(jg);
    }
}

