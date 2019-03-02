#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utilitaires.h"
#include "graphe_matrice.h"
#include "graphe_parcours.h"

#define DEBUT printf("\n ######### Debut de parcours #############\n")

Graphe* creerGraphe(int numSommet, int numLien){

	Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
	graphe->numSommet = numSommet;
	graphe->numLien = numLien;

	graphe->arcs = (Arc*)malloc(numLien * sizeof(Arc));

	return graphe;
}



/**************************************** Pour Exo3 *********************************/
void afficherDistanceEtPere(int lambda[], int pi[], int n)
{
	printf("\n\nDistances a partir de la source:\n");
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


/**************************************** Pour Exo1 *********************************/

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
                printf("\n Test de DFS(mgno);\n");
                DFS(mgno, 0);

}


/**************************************** Pour Exo2 *********************************/

void saisirArcs(Graphe *graphe){
    freopen("exo2.txt", "r", stdin);
    int i;
    for(i = 0; i < graphe->numLien; i++){
        scanf("%d%d%d", &graphe->arcs[i].src, &graphe->arcs[i].dest, &graphe->arcs[i].poids);
    }
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

	// ADAPTATION
	resultat[rSize++] = graphe->arcs[0];
	resultat[rSize++] = graphe->arcs[1];

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

    // ADAPTATION
	pere[4] = 0;
	pere[7] = 6;

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
	// Affichage de resultat
    char sommetReel[12] = {'A','B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J','K','L'};
	printf("\nVoici les arcs (aretes) de l\'arbre de poids minimal: \n");
	for (i = 0; i < rSize; ++i)
		printf("%c --(%d)-- %c\n", sommetReel[resultat[i].src], resultat[i].poids, sommetReel[resultat[i].dest]);
return;
}
