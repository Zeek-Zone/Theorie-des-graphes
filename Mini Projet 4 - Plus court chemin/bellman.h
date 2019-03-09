
#ifndef H_BELLMAN
#define H_BELLMAN

#include<stdlib.h>
#include<stdio.h>
#include "graphe_matrice.h"
#include "utilitaires.h"

int* triTopo(MatriceDAdjacence graphe, int x0);

void Bellman(MatriceDAdjacence graphe, int x0);

int sommetSansPred(MatriceDAdjacence graphe, int *sommetTrie);

int sommetSuivantANumerote(MatriceDAdjacence graphe, int *sommetTrie);

#endif // H_BELLMAN

//  Hassan Zekkouri
