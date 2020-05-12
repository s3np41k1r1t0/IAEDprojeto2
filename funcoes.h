#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "equipa.h"
#include "estruturas_equipa.h"
#include "jogo.h"
#include "estruturas_jogo.h"
#include "auxiliares.h"

unsigned int a(unsigned int NL, Jogos_HT ht_jogos, Lista_Jogos ll_jogos, Equipas_HT ht_equipas, Lista_Equipas ll_equipas);
unsigned int A(unsigned int NL, Equipas_HT ht_equipas, Lista_Equipas ll_equipas);
unsigned int l(unsigned int NL, Lista_Jogos ll_jogos);
unsigned int p(unsigned int NL, Jogos_HT ht_jogos);
unsigned int P(unsigned int NL, Equipas_HT ht_equipas);
unsigned int r(unsigned int NL, Jogos_HT ht_jogos, Lista_Jogos ll_jogos, Lista_Equipas ll_equipas);
unsigned int s(unsigned int NL, Jogos_HT ht_jogos, Lista_Equipas ll_equipas);
unsigned int g(unsigned int NL, Lista_Equipas ll_equipas);

#endif
