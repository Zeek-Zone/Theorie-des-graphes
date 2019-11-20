#ifndef H_UTIL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H_UTIL
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

struct comp{
    int nbrSommet;
    int *sommets;
};
typedef struct comp Composante;



struct cfc{
    int taille;
    Composante *composantes;
};

typedef struct cfc CFC;


CFC* creerCFC();
Composante* creerComposante();
Graphe* creerGraphe(int numSommet, int numLien);



#endif // H_UTIL
