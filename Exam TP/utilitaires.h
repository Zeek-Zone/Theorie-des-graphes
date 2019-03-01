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


//void mesBFS();

//void mesDFS();

#endif // UTIL
