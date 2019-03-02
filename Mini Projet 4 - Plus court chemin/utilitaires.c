#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utilitaires.h"
#include "graphe_matrice.h"


Graphe* creerGraphe(int numSommet, int numLien){

	Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
	graphe->numSommet = numSommet;
	graphe->numLien = numLien;

	graphe->arcs = (Arc*)malloc(numLien * sizeof(Arc));

	return graphe;
}

void afficherDistanceEtPere(int lambda[], int pi[], int n)
{
	printf("Distances a partir de la source:\n");
	int i;
	printf("\n Sommet \t Distance \t Pere\n");
	for (i = 0; i < n; ++i)
		printf("%d \t\t %d \t\t %d\n", i, lambda[i], pi[i]);
}

void initialisation(int *lambda, int *pi, int x0, int n){
    int i;
    for(i = 0; i < n; i++){
        lambda[i] = INT_MAX;
        pi[i] = 0;
    }
    lambda[x0] = 0;
}

void relacher(int *lambda, int *pi, int i, int j, int poids){
    if( lambda[j] > lambda[i] + poids){
        lambda[j] = lambda[i] + poids;
        pi[j] = i;
    }
}




