#include "funcoes.h"

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

void A(unsigned int NL){
    char nome[MAX_STR];
    int size;
    equipa* nova;

    size = get_string(nome);

    if(procura_equipa(nome) != NULL){
        printf("%ud Equipa inexistente.\n",NL);
        return;
    }

   nova = cria_equipa(nome,size); 
   insere_equipa(nova);        
} 

void P(unsigned int NL){
    equipa* atual;
    char nome[MAX_STR];

    get_string(nome);
    atual = procura_equipa(nome);

    if(atual == NULL){
        printf("%ud Equipa inexistente.\n",NL);
        return;
    }

    else
        printf("%s %d",atual->nome,atual->ganhos);
}
