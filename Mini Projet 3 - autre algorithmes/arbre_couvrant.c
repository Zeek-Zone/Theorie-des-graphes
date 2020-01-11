#include "arbre_couvrant.h"

/************** Kruskal's Algorithm *********************/

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
	int poidsMinimal = 0;

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
			poidsMinimal += arcSuivant.poids;
		}
	}

	// Affichage de resultat
	// Affichage de resultat
    //char sommetReel[12] = {'A','B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J','K','L'};
	printf("\nVoici les arcs (aretes) de l\'arbre de poids minimal = %d \n", poidsMinimal);
	for (i = 0; i < rSize; ++i)
		//printf("%c --(%d)-- %c\n", sommetReel[resultat[i].src], resultat[i].poids, sommetReel[resultat[i].dest]);
		printf("%d --(%d)-- %d\n", resultat[i].src+1, resultat[i].poids, resultat[i].dest+1);
return;
}


/************************** Prim's Algorithm *****************/


// nombre d'arc sortant
int numArcSortant = 0;

void trouverArcSortant(MatriceDAdjacence m, Arc *arcSortant, int *M, int DSM){

          int j;
          for(j = 0; j < m.n; j++){
                      if( m.matrice[DSM][j] )
                                {
                                    // si le sommet j n'appartient pas au sous
                                    // graphe ajouter l'arc
                                    if(M[j] == 0){ /// j ne fait pas partie de sous graphe
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
    int poidsMinimal = 0;
    // M: les sommets marqués initialisé à zero (non marqué)
    int *M = (int*)calloc(ordre, sizeof(int)); ///  0 0 0
    // tableau des arcs (aretes) sortants
    Arc *arcSortant = (Arc*)malloc(sizeof(Arc));
    // Dernier sommet marque
    int DSM = racine - 1;
    // Marquer la racine
    M[DSM] = 1;
    trouverArcSortant(graphe, arcSortant, M, DSM);

    while(numArcSortant != 0 && rSize < ordre-1){
        //  Trier les arcs en ordre croissant de poids
        qsort(arcSortant, numArcSortant, sizeof(Arc), comparer);

        int x = arcSortant[0].src;
        int y = arcSortant[0].dest;
        if(M[y-1] == 0){ /// y-1 ne fait pas partie de sous graphe
            // marqué le sommet y
            M[y-1] = M[x-1] + 1;

            //Ajouter arc
            poidsMinimal += arcSortant[0].poids;
            resultat[rSize++] = arcSortant[0];
        }

        // on supprime l'arc ajouté ou celui créant un cycle
        arcSortant = supprimerDebut(arcSortant);

        DSM = y-1;
        trouverArcSortant(graphe, arcSortant, M, DSM);

    }

    // Affichage de resultat
	printf("\nVoici les arcs (aretes) de l\'arbre de poids minimal = %d \n", poidsMinimal);
	int i;
	for (i = 0; i < rSize; ++i)
		printf("%d --(%d)-- %d\n", resultat[i].src, resultat[i].poids, resultat[i].dest);
}



