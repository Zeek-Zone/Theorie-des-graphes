#ifndef H_MST
#define H_MST

#include "graphe_matrice.h"
#include "utilitaires.h"

// trouver l'ensemble qui contient i
int trouver(int pere[], int i);

// une fonction qui permet de faire l'union de deux ensembles
void Union(int pere[], int x, int y);

// Comparer deux arcs (aretes)
// Utilsé dans qsort() qui trie le tableau des arcs
int comparer(const void* a, const void* b);


void Kruskal(Graphe* graphe);


void Prim(MatriceDAdjacence graphe, int racine);

Arc* supprimerDebut(Arc *arcSortant);

void trouverArcSortant(MatriceDAdjacence m, Arc *arcSortant, int *M, int DSM);

#endif // H_MST
