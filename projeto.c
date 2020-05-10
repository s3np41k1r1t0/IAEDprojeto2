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

    inicializa();

    /*Le carateres da stdin ate encontrar o caso terminal
      ou um comando a executar*/
    while((op = getchar()) != 'x'){
        switch(op){
            case('a'):
                getchar();
                a();
                break;

            case('A'):
                getchar();
                A();
                break;
            
            case('l'):
                getchar();
                l();
                break;
            
            case('p'):
                getchar();
                p();
                break;
            
            case('P'):
                getchar();
                P();
                break;
            
            case('r'):
                getchar();
                r();
                break;
            
            case('s'):
                getchar();
                s();
                break;
            
            case('g'):
                getchar();
                g();
                break;
            
        }
    }

    destroi();

    return 0;
}
