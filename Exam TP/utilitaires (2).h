#ifndef UTIL
#define UTIL

#include "graphe_matrice.h"

// une structure representant l'arc
typedef struct arc{   // arete
	int src,
        dest,
        poids;
}Arc;


// la structure representant le graphe par ses arcs (aretes)
typedef struct graphe{

	int numSommet, numLien;
	Arc* arcs;

}Graphe;

void initialisation(int *lambda, int *pi, int x0, int n);
void relacher(int *lambda, int *pi, int i, int j, int poids);
void afficherDistanceEtPere(int lambda[], int pi[], int n);

Graphe* creerGraphe(int numSommet, int numLien);

void saisirArcs(Graphe *graphe);

void mesBFS();

void mesDFS();

// trouver l'ensemble qui contient i
int trouver(int pere[], int i);

// une fonction qui permet de faire l'union de deux ensembles
void Union(int pere[], int x, int y);

// Comparer deux arcs (aretes)
// Utilsé dans qsort() qui trie le tableau des arcs
int comparer(const void* a, const void* b);


void Kruskal(Graphe* graphe);


#endif // UTIL
