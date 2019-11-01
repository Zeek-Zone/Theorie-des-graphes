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

// Fonction principale pour l'algorrithme de Kruskal
void Kruskal(Graphe* graphe);

// Fonction principale pour l'algorrithme de Prim
void Prim(MatriceDAdjacence graphe, int racine);

// supprime le premier arc dans le tableau arcSortant
Arc* supprimerDebut(Arc *arcSortant);

void trouverArcSortant(MatriceDAdjacence m, Arc *arcSortant, int *M, int DSM);



#endif // H_MST
// Hassan Zekkouri
