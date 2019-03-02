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
	/// ADAPTATION
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

/// ADAPTATION
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



// nombre d'arc sortant
int numArcSortant = 0;
void trouverArcSortant(MatriceDAdjacence m, Arc *arcSortant, int *M, int DSM){

          int j;
          for(j = 0; j < m.n; j++){
                      if( m.matrice[DSM][j] )
                                {
                                    // si le sommet j n'appartient pas au sous
                                    // graphe ajouter l'arc
                                    if(M[j] == 0){
                                        (numArcSortant)++;
                                        arcSortant = (Arc*)realloc(arcSortant, (numArcSortant) * sizeof(Arc));
                                        arcSortant[numArcSortant-1].src = DSM+1;
                                        arcSortant[numArcSortant-1].dest = j+1;
                                        arcSortant[numArcSortant-1].poids = m.matrice[DSM][j];
                                    }
                                }
            }
}


Arc* supprimerDebut(Arc *arcSortant){
    int taille = numArcSortant;
    Arc *temp = (Arc*)malloc( (taille-1) * sizeof(Arc));
    int i, j = 0;
    for(i = 1; i < taille; i++, j++)
        temp[j] = arcSortant[i];
    numArcSortant--;
    free(arcSortant);
return temp;
}

void Prim(MatriceDAdjacence graphe, int racine){
    int ordre = graphe.n;
    Arc resultat[ordre-1];
    int rSize = 0;
    // M: les sommets marqués
    int *M = (int*)malloc(ordre * sizeof(int));
    // tableau des arcs (aretes) sortants
    Arc *arcSortant = (Arc*)malloc(sizeof(Arc));
    // initialisé M et marqueArc à zero (non marqué)
    memset(M, 0, ordre * sizeof(int));
    // Dernier sommet marque
    int DSM = racine - 1;
    // Marquer la racine
    M[racine-1] = 1;
    trouverArcSortant(graphe, arcSortant, M, DSM);

    while(numArcSortant != 0 && rSize < ordre-1){
        //  Trier les arcs en ordre croissant de poids
        qsort(arcSortant, sizeof(arcSortant), sizeof(Arc), comparer);

        int x = arcSortant[0].src;
        int y = arcSortant[0].dest;
        // marqué le sommet y
        M[y-1] = M[x-1] + 1;
        resultat[rSize++] = arcSortant[0];
        // on supprime l'arc ajouter
        arcSortant = supprimerDebut(arcSortant);
        DSM = y-1;
        trouverArcSortant(graphe, arcSortant, M, DSM);

    }

    // Affichage de resultat
	printf("\nVoici les arcs (aretes) de l\'arbre de poids minimal: \n");
	int i;
	for (i = 0; i < rSize; ++i)
		printf("%d --(%d)-- %d\n", resultat[i].src, resultat[i].poids, resultat[i].dest);
}




void exo2(){

	int V = 12; // Number of vertices in graph
	int E = 23; // Number of edges in graph
	Graphe* graphe = creerGraphe(V, E);
	saisirArcs(graphe);

	Kruskal(graphe);
}

void exo4(){
    freopen("exo4.txt", "r", stdin);
    MatriceDAdjacence graphe = creerMatAdjGNO();
    int *degre = (int*)calloc(10, sizeof(int)); // tous à zero
    int *colore = (int*)calloc(10, sizeof(int));  // tous à zero: non coloré
    printf("\n ########## Debut de Coloriage ########\n");
    Powell_Welsh(graphe, degre, colore);
}

void saisirArcs(Graphe *graphe){
    freopen("exo2.txt", "r", stdin);
    int i;
    for(i = 0; i < graphe->numLien; i++){
        scanf("%d%d%d", &graphe->arcs[i].src, &graphe->arcs[i].dest, &graphe->arcs[i].poids);
    }
}
/** \brief
 *
 * \param
 * \param
 * \return
 * Chercher le nombre de liaison total de dans le graphe
    Arc *arcs = trouverArcs(graphe);
    int numLien = sizeof(arcs);
    memset(marqueArc, 0, numLien * sizeof(int));
// les arcs marqués
    int *marqueArc = (int*)malloc(numLien * sizeof(int));
 */
