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
    /*Variavel que contem o comando a ser executado*/
    char op;

    /*Variavel que contem o numero da linha do comando*/
    unsigned int NL = 1;

    inicializa();

    /*Le carateres da stdin ate encontrar o caso terminal
      ou um comando a executar*/
    while((op = getchar()) != 'x'){
        switch(op){
            case('a'):
                getchar();
                a(NL);
                break;

            case('A'):
                getchar();
                A(NL);
                break;
            
            case('l'):
                getchar();
                l(NL);
                break;
            
            case('p'):
                getchar();
                p(NL);
                break;
            
            case('P'):
                getchar();
                P(NL);
                break;
            
            case('r'):
                getchar();
                r(NL);
                break;
            /*
            case('s'):
                getchar();
                s(NL);
                break;

            case('g'):
                getchar();
                g(NL);
                break;
            */
        }
    }

    destroi();

    return 0;
}
