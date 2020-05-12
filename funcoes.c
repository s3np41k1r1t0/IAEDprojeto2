#include "funcoes.h"

unsigned int a(unsigned int NL, Jogos_HT ht_jogos, Lista_Jogos ll_jogos, Equipas_HT ht_equipas, Lista_Equipas ll_equipas){
    Jogo novo;
    Equipa eq1, eq2;
    char nome[MAX_STR], nome_eq1[MAX_STR], nome_eq2[MAX_STR];
    int size_nome, score1, score2;

    size_nome = get_string(nome);
    get_string(nome_eq1);
    get_string(nome_eq2);

    scanf("%d:%d",&score1,&score2);

    if(procura_jogo(ht_jogos, nome) != NULL){
        printf("%u Jogo existente.\n",NL);
        return ++NL;
    }

    else if((eq1 = procura_equipa(ht_equipas, nome_eq1)) == NULL || (eq2 = procura_equipa(ht_equipas, nome_eq2)) == NULL){
        printf("%u Equipa inexistente.\n",NL);
        return ++NL;
    }

    novo = cria_jogo(nome, size_nome, eq1, eq2, score1, score2, ll_equipas);

    insere_jogo(ht_jogos, ll_jogos, novo);

    return ++NL;
}

unsigned int l(unsigned int NL, Lista_Jogos ll_jogos){
    print_todos_jogos(ll_jogos, NL);
    return ++NL;
}

unsigned int p(unsigned int NL, Jogos_HT ht_jogos){
    Jogo atual;
    char nome[MAX_STR];

    get_string(nome);

    if((atual = procura_jogo(ht_jogos, nome)) == NULL)
        printf("%u Jogo inexistente.\n",NL);

    else
        printf("%u %s %s %s %d %d\n",NL,nome_jogo(atual),nome_equipa(atual->equipa1),
            nome_equipa(atual->equipa2),atual->score1,atual->score2);

    return ++NL;
}

unsigned int A(unsigned int NL, Equipas_HT ht_equipas, Lista_Equipas ll_equipas){
    char nome[MAX_STR];
    int size;
    Equipa nova;

    size = get_string(nome);

    if(procura_equipa(ht_equipas, nome) != NULL){
        printf("%u Equipa existente.\n",NL);
        return ++NL;
    }

    nova = cria_equipa(nome,size); 
    insere_equipa(ht_equipas, ll_equipas, nova);   
    return ++NL;
} 

unsigned int P(unsigned int NL, Equipas_HT ht_equipas){
    Equipa atual;
    char nome[MAX_STR];

    get_string(nome);

    if((atual = procura_equipa(ht_equipas, nome)) == NULL){
        printf("%u Equipa inexistente.\n",NL);
        return ++NL;
    }

    else
        printf("%u %s %d\n",NL,nome_equipa(atual),jogos_ganhos(atual));

    return ++NL;
}

unsigned int r(unsigned int NL, Jogos_HT ht_jogos, Lista_Jogos ll_jogos, Lista_Equipas ll_equipas){
    char nome[MAX_STR];
    Jogo jogo;

    get_string(nome);

    if((jogo = remove_jogo_ht(ht_jogos, nome)) == NULL || 
       (jogo = remove_jogo_ll(ll_jogos, nome)) == NULL)
        printf("%u Jogo inexistente.\n",NL);

    else
        remove_jogo(jogo, ll_equipas);
    
    return ++NL;
}

unsigned int s(unsigned int NL, Jogos_HT ht_jogos, Lista_Equipas ll_equipas){
    char nome[MAX_STR];
    int score1,score2;
    Jogo jg;

    get_string(nome);
    scanf("%d:%d",&score1,&score2);

    if((jg = procura_jogo(ht_jogos, nome)) == NULL){
        printf("%u Jogo inexistente.\n",NL);
        return ++NL;
    }

    altera_score(jg, score1, score2, ll_equipas);
    
    return ++NL;
}

unsigned int g(unsigned int NL, Lista_Equipas ll_equipas){
    print_vencedores(ll_equipas, NL);
    return ++NL;
}
