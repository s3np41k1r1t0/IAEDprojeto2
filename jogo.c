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

    if(score1 > score2){
        adiciona_vitoria(equipa1);
        atualiza_maximo(equipa1);
    }

    else if(score1 < score2){
        adiciona_vitoria(equipa2);
        atualiza_maximo(equipa2);
    }

    return novo;
}

void free_jogo(Jogo jg){
    if(jg != NULL){
        free(nome_jogo(jg));
        free(jg);
    }
}

void remove_jogo(Jogo jg){
    if(jg->score1 > jg->score2){
        remove_vitoria(obtem_equipa1(jg));
        atualiza_maximo(obtem_equipa1(jg));
    }

    else if(jg->score2 > jg->score1){
        remove_vitoria(obtem_equipa2(jg));
        atualiza_maximo(obtem_equipa2(jg));
    }

    free_jogo(jg);
}

void altera_score(Jogo jg, int score1, int score2){
    if(jg->score1 == jg->score2){
        if(score1 > score2)
            adiciona_vitoria(jg->equipa1);

        if(score2 > score1)
            adiciona_vitoria(jg->equipa2);
    }

    else if(jg->score1 > jg->score2){
        if(score1 == score2)
            remove_vitoria(jg->equipa1);

        else if(score2 > score1){
            remove_vitoria(jg->equipa1);
            adiciona_vitoria(jg->equipa2);
        }
    }

    else{
        if(score1 == score2)
            remove_vitoria(jg->equipa2);

        else if(score1 > score2){
            remove_vitoria(jg->equipa2);
            adiciona_vitoria(jg->equipa1);
        }
    }

    jg->score1 = score1;
    jg->score2 = score2;

    atualiza_maximo(obtem_equipa1(jg));
    atualiza_maximo(obtem_equipa2(jg));
}

