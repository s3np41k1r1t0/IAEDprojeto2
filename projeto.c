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

    /*Le carateres da stdin ate encontrar o caso terminal
      ou um comando a executar*/
    while((op = getchar()) != 'x'){
        switch(op){
            case('a'):
                novo_jogo();
                break;

            case('A'):
                nova_equipa();
                break;

            case('l'):
                lista_jogos();
                break;

            case('p'):
                procura_jogo();
                break;

            case('P'):
                procura_equipa();
                break;

            case('r'):
                apaga_jogo();
                break;

            case('s'):
                altera_pontuacao();
                break;

            case('g'):
                encontra_vencedores();
                break;
        }
    }
    
    return 0;
}
