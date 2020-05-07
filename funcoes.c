#include "funcoes.h"
#include "jogo.h"
#include "auxiliares.h"

/*
void novo_jogo(unsigned int NL){
    jogo* novo = NULL;
    char nome[MAX_STR], equipa1[MAX_STR], equipa2[MAX_STR];
    int size_nome, size1, size2;

    size_nome = get_string(nome);
    size1 = get_string(equipa1);
    size2 = get_string(equipa2);

    novo = cria_jogo(nome, size_nome, equipa1, size1, equipa2, size2);

    insere(novo);
}
*/

void inicializa(){
    inicializa_jogos();
    inicializa_equipas();
}
