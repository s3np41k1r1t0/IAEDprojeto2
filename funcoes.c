#include "funcoes.h"

unsigned int NL;

void inicializa(){
    inicializa_jogos();
    inicializa_equipas();
    NL=1;
}

void destroi(){
    destroi_jogos();
    destroi_equipas();
}

void a(){
    Jogo novo;
    Equipa eq1, eq2;
    char nome[MAX_STR], nome_eq1[MAX_STR], nome_eq2[MAX_STR];
    int size_nome, score1, score2;

    size_nome = get_string(nome);
    get_string(nome_eq1);
    get_string(nome_eq2);

    scanf("%d:%d",&score1,&score2);

    if(procura_jogo(nome) != NULL){
        printf("%u Jogo existente.\n",NL++);
        return;
    }

    else if((eq1 = procura_equipa(nome_eq1)) == NULL || (eq2 = procura_equipa(nome_eq2)) == NULL){
        printf("%u Equipa inexistente.\n",NL++);
        return;
    }

    novo = cria_jogo(nome, size_nome, eq1, eq2, score1, score2);

    insere_jogo(novo);
    NL++;
}

void l(){
    print_todos_jogos(NL);
    NL++;
}

void p(){
    Jogo atual;
    char nome[MAX_STR];

    get_string(nome);

    atual = procura_jogo(nome);

    if(atual == NULL){
        printf("%u Jogo inexistente.\n",NL++);
        return;
    }

    else
        printf("%u %s %s %s %d %d\n",NL++,nome_jogo(atual),nome_equipa(atual->equipa1),nome_equipa(atual->equipa2),atual->score1,atual->score2);
}

void A(){
    char nome[MAX_STR];
    int size;
    Equipa nova;

    size = get_string(nome);

    if(procura_equipa(nome) != NULL){
        printf("%u Equipa existente.\n",NL++);
        return;
    }

   nova = cria_equipa(nome,size); 
   insere_equipa(nova);   
   NL++;
} 

void P(){
    Equipa atual;
    char nome[MAX_STR];

    get_string(nome);
    atual = procura_equipa(nome);

    if(atual == NULL){
        printf("%u Equipa inexistente.\n",NL++);
        return;
    }

    else
        printf("%u %s %d\n",NL++,nome_equipa(atual),jogos_ganhos(atual));
}

void r(){
    char nome[MAX_STR];
    No_Jogo no;
    Jogo jg;

    get_string(nome);

    if((no = procura_no_jogos(nome)) ==  NULL){
        printf("%u Jogo inexistente.\n",NL++);
        return;
    }

    jg = remove_no_jogo(no);
    remove_jogo(jg);

    NL++;
}

void s(){
    char nome[MAX_STR];
    int score1,score2;
    Jogo jg;

    get_string(nome);
    scanf("%d:%d",&score1,&score2);

    if((jg = procura_jogo(nome)) == NULL){
        printf("%u Jogo inexistente.\n",NL++);
        return;
    }

    altera_score(jg,score1,score2);

    NL++;
}
