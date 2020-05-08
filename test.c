#include "equipa.c"
#include <stdio.h>

int main(){
    char nome[1024];
    int size;
    equipa* temp;

    inicializa_equipas();

    size = get_string(nome);
    temp = cria_equipa(nome,size);
    printf("%s %d\n",temp->nome, size);
   
    insere_equipa(temp);

    temp = cria_equipa("aba\0",4);
    printf("%d\n",hash("aba",31));
    insere_equipa(temp);

    temp = procura_equipa(nome);
    

    if(temp == NULL)
        puts("NOP");

    printf("%s %d\n",temp->nome, size);
    
    destroi_equipas();
}
