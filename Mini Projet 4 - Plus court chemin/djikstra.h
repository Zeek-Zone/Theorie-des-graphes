#ifndef H_DIJKSTRA
#define H_DIJKSTRA

#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include "graphe_matrice.h"
#include "utilitaires.h"

int* construireListeSuccesseur(MatriceDAdjacence graphe, int x);

int sommetSuivant(int *lambda, int n, int *marque);

void Dijkstra(MatriceDAdjacence graphe, int x0);


#endif // H_DIJKSTRA

//  Hassan Zekkouri
