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

    inicia();

    /*Le carateres da stdin ate encontrar o caso terminal
      ou um comando a executar*/
    while((op = getchar()) != 'x'){
        switch(op){
            case('a'):
                novo_jogo(NL);
                break;

            case('A'):
                nova_equipa(NL);
                break;

            case('l'):
                lista_jogos(NL);
                break;

            case('p'):
                procura_jogo(NL);
                break;

            case('P'):
                procura_equipa(NL);
                break;

            case('r'):
                apaga_jogo(NL);
                break;

            case('s'):
                altera_pontuacao(NL);
                break;

            case('g'):
                encontra_vencedores(NL);
                break;
        
            case('\n'):
                NL++;
                break;
        }
    }
    
    return 0;
}
