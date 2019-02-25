#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitaires.h"


Graphe* creerGraphe(int numSommet, int numLien){

	Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
	graphe->numSommet = numSommet;
	graphe->numLien = numLien;

	graphe->arcs = (Arc*)malloc(numLien * sizeof(Arc));

	return graphe;
}

// trouver l'ensemble qui contient i
int trouver(int pere[], int i)
{
    // trouver la racine de sommet i
	if (pere[i] == -1)
		return i;
    // les sommets retournés constituent l'ensemble
	return trouver(pere, pere[i]);
}

// une fonction qui permet de faire l'union de deux ensembles
void Union(int pere[], int x, int y)
{
    int ensembleX = trouver(pere, x);
    int ensembleY = trouver(pere, y);
    if(ensembleX != ensembleY){
       pere[ensembleX] = ensembleY;
    }
}
// Comparer deux arcs (aretes)
// Utilsé dans qsort() qui trie le tableau des arcs
int comparer(const void* a, const void* b)
{
    Arc* a1 = (Arc*)a;
    Arc* b1 = (Arc*)b;
    return a1->poids > b1->poids;
}


void Kruskal(Graphe* graphe)
{
	int ordre = graphe->numSommet;
	Arc resultat[ordre]; // les arcs de l'arbre de poids minimal
	int rSize = 0; // iterateur de resultat[]
	int i = 0; // iterateurs pour l'ensemble des arcs du graphe

	// Etape 1: Trier les arcs en ordre croissant de poids
	qsort(graphe->arcs, graphe->numLien, sizeof(Arc), comparer);

	// allocation de la table pere representant le pere de chaque sommet
	int *pere = (int*)malloc(ordre * sizeof(int));

	// initialiser tout à -1, chaque sommet constitue un ensemble
	int s;
	for (s = 0; s < ordre; ++s)
	{
		pere[s] = -1;
	}

	// nomber d'iteration est de (order - 1)
	while (rSize < ordre - 1)
	{
		// Etape 2: choisir l'arc de poids minimal.
		// et incrementer i pour passer à l'arcs suivant
		Arc arcSuivant = graphe->arcs[i++];

		int x = trouver(pere, arcSuivant.src);
		int y = trouver(pere, arcSuivant.dest);

		// si l'ajout de cette arc (arete) ne genere pas un cycle,
		// ajouter le (la) au resultat et incrementer rSize
		if (x != y)
		{
			resultat[rSize++] = arcSuivant;
			//lier les deux sous ensemble
			Union(pere, x, y);
		}
	}

	// Affichage de resultat
	printf("\nVoici les arcs (aretes) de l\'arbre de poids minimal: \n");
	for (i = 0; i < rSize; ++i)
		printf("%d --(%d)-- %d\n", resultat[i].src, resultat[i].poids, resultat[i].dest);
return;
}
