
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


void Prim(MatriceDAdjacence graphe, int racine);

Arc* supprimerDebut(Arc *arcSortant);

void trouverArcSortant(MatriceDAdjacence m, Arc *arcSortant, int *M, int DSM);

Graphe* creerGraphe(int numSommet, int numLien);

// trouver l'ensemble qui contient i
int trouver(int pere[], int i);

// une fonction qui permet de faire l'union de deux ensembles
void Union(int pere[], int x, int y);

// Comparer deux arcs (aretes)
// Utilsé dans qsort() qui trie le tableau des arcs
int comparer(const void* a, const void* b);


void Kruskal(Graphe* graphe);
