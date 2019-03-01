#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utilitaires.h"
#include "graphe_matrice.h"

#define DEBUT printf("\n ######### Debut de parcours #############\n")

Graphe* creerGraphe(int numSommet, int numLien){

	Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
	graphe->numSommet = numSommet;
	graphe->numLien = numLien;

	graphe->arcs = (Arc*)malloc(numLien * sizeof(Arc));

	return graphe;
}

void afficherDistanceEtPere(int lambda[], int pi[], int n)
{
	printf("Distances a partir de source:\n");
	int i;
	char sommetReel[8] = {'A','B', 'C', 'D', 'E', 'F', 'G','H'};
	printf("\n Sommet \t Distance \t Pere\n");
	for (i = 0; i < n; ++i)
        if(i == 0)
           printf("%c \t\t %d \t\t null\n", sommetReel[i], lambda[i]);
        else
            printf("%c \t\t %d \t\t %c\n", sommetReel[i], lambda[i], sommetReel[pi[i]]);
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



/*
void mesBFS(){
    // Pour tester les fonctionalité liées aux parcours en largeur d'un graphe

      printf("\n___________ Graphe Non Oriente ____________\n");
      freopen("exo1.txt", "r", stdin);
      MatriceDAdjacence mgno = creerMatAdjGNO();
      DEBUT;
      printf("\n Test de parcoursLargeur(mgno, i);\n");

        printf("\n Parcours Pour La racine : %d", 0); // c'est le sommet 0 pour l'examen (racine+1)
        parcoursLargeur(mgno, 0);

}

void mesDFS(){
    // Pour tester les fonctionalité liées aux parcours en profondeur d'un graphe /

              printf("\n___________ Graphe Non Oriente ____________\n");
              freopen("exo1.txt", "r", stdin);
              MatriceDAdjacence mgno = creerMatAdjGNO();
              DEBUT;
              printf("\n Test de parcoursProfondeur(mgno, i);\n");

                printf("\n Parcours Pour La racine : %d", 0);
                printf("\n parcoursProfondeur(mgno, i);\n");
                //afficheMatriceAdjacence(mgno);
                parcoursProfondeur(mgno, 0);
                //printf("\n Test de DFS(mgno);\n");
                //DFS(mgno, 0);

}
*/

