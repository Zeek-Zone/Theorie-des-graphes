#include "bellman_ford.h"

void BellmanFord(Graphe* graphe, int x0)
{
	int V = graphe->numSommet;
	int E = graphe->numLien;
	int *lambda = (int*)malloc(V * sizeof(int));
	int *pi = (int*)malloc(V * sizeof(int));
	int i, j;

	// Etape 1: Initialisation()
	initialisation(lambda, pi, x0, V);

	// Etape 2: Realacher les arcs |V| - 1 fois
	// (c'est le nombre maximal d'arc que peut
    // avoir un plus court chemin
	for ( i = 1; i <= V-1; i++)
	{
		for ( j = 0; j < E; j++)
		{
			int u = graphe->arcs[j].src;
			int v = graphe->arcs[j].dest;
			int poids = graphe->arcs[j].poids;
			// si la distance est differente de l'infini
			// alors relacher encore une fois
			// la racine est à distance 0!
			if (lambda[u] != INT_MAX)
				relacher(lambda, pi, u, v, poids);
		}
	}

	// Etape 3: Detecter les cycles absorbants.
	// si on trouve une autre amélioration de la distance
	// alors on a un cycle absorbant.
	for (i = 0; i < E; i++)
	{
		int u = graphe->arcs[i].src;
		int v = graphe->arcs[i].dest;
		int poids = graphe->arcs[i].poids;
		if (lambda[u] != INT_MAX && lambda[u] + poids < lambda[v]){
                    printf("Le graphe contient un cycle absorbant!\n");
                    return;
		}
	}

	afficherDistanceEtPere(lambda, pi, V);

	return;
}


//  Hassan Zekkouri

