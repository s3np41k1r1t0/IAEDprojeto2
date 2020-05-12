/*
  Ficheiro: projeto.h
  Autor: Bruno Miguel da Silva Mendes ist195544/al95544
  Descricao: Ponto de entrada para o projeto de IAED19/20
*/

/*IMPORTS*/
#include "funcoes.h"

/*FUNCAO MAIN*/

/*
  main: () -> int
  Primeira funcao a ser executada, trata de reconhecer o comando presente na input
*/
int main(){
    /*Variavel que conteem o comando a ser executado e o numero de linhas*/
    char op;
    unsigned int NL = 1;

    /*Variaveis que conteem as estruturas usadas para guardar os jogos e as equipas*/
    Jogos_HT ht_jogos;
    Lista_Jogos ll_jogos;
    Equipas_HT ht_equipas;
    Lista_Equipas ll_equipas;

    /*Inicializa estruturas de jogos e equipas*/
    init_hashtable_jogos(ht_jogos);
    ll_jogos = init_lista_jogos();
    init_hashtable_equipas(ht_equipas);
    ll_equipas = init_lista_equipas();

    /*Le carateres da stdin ate encontrar o caso terminal
      ou um comando a executar*/
    while((op = getchar()) != 'x'){
        switch(op){
            case('a'):
                /*elimina o ' ' entre o comando e o conteudo do comando*/
                getchar(); 
                NL = a(NL, ht_jogos, ll_jogos, ht_equipas, ll_equipas);
                break;
            case('A'):
                getchar();
                NL = A(NL, ht_equipas, ll_equipas);
                break;
            case('l'):
                getchar();
                NL = l(NL, ll_jogos);
                break;
            case('p'):
                getchar();
                NL = p(NL, ht_jogos);
                break;
            case('P'):
                getchar();
                NL = P(NL, ht_equipas);
                break;
            case('r'):
                getchar();
                NL = r(NL, ht_jogos, ll_jogos, ll_equipas);
                break;
            case('s'):
                getchar();
                NL = s(NL, ht_jogos, ll_equipas);
                break;
            case('g'):
                getchar();
                NL = g(NL, ll_equipas);
                break;   
        }
    }

    /*destroi todos os jogos e equipas*/
    destroi_jogos(ll_jogos);
    destroi_equipas(ll_equipas);

    /*destroi todas as estruturas de jogos e equipas*/
    destroi_hashtable_jogos(ht_jogos);
    destroi_lista_jogos(ll_jogos);
    destroi_hashtable_equipas(ht_equipas);
    destroi_lista_equipas(ll_equipas);

    return 0;
}
