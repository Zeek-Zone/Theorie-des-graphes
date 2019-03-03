#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilitaires.h"
#include "graphe_matrice.h"


Graphe* creerGraphe(int numSommet, int numLien){

	Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
	graphe->numSommet = numSommet;
	graphe->numLien = numLien;

	graphe->arcs = (Arc*)malloc(numLien * sizeof(Arc));

	return graphe;
}

void saisirArcs(Graphe *graphe){
    freopen("exo2.txt", "r", stdin);
    int i;
    for(i = 0; i < graphe->numLien; i++){
        scanf("%d%d%d", &graphe->arcs[i].src, &graphe->arcs[i].dest, &graphe->arcs[i].poids);
    }
}

void fermeture(){
    freopen("fermeture_trans.txt", "r", stdin);
    MatriceDAdjacence graphe1 = creerMatAdjGO();
    Warshall(graphe1);
}


void KruskalMST(){

	int V = 12; // Number of vertices in graph
	int E = 23; // Number of edges in graph
	Graphe* graphe = creerGraphe(V, E);
	saisirArcs(graphe);

	Kruskal(graphe);
}

void coloriage(){
    freopen("exo4.txt", "r", stdin);
    MatriceDAdjacence graphe = creerMatAdjGNO();
    int *degre = (int*)calloc(10, sizeof(int)); // tous à zero
    int *colore = (int*)calloc(10, sizeof(int));  // tous à zero: non coloré
    printf("\n ########## Debut de Coloriage ########\n");
    Powell_Welsh(graphe, degre, colore);
}

