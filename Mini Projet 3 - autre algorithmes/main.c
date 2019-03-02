#include <stdio.h>
#include <stdlib.h>
#include "utilitaires.h"
#include "graphe_matrice.h"


// Driver program to test above functions
int main()
{
	/* Let us create following weighted graph
			10
		0--------1
		| \      |
       6|  5\    |15
		|	  \  |
		2--------3
			4	   */
	/*int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	Graphe* graphe = creerGraphe(V, E);


	// add edge 0-1
	graphe->arcs[0].src = 0;
	graphe->arcs[0].dest = 1;
	graphe->arcs[0].poids = 10;

	// add edge 0-2
	graphe->arcs[1].src = 0;
	graphe->arcs[1].dest = 2;
	graphe->arcs[1].poids = 6;

	// add edge 0-3
	graphe->arcs[2].src = 0;
	graphe->arcs[2].dest = 3;
	graphe->arcs[2].poids = 5;

	// add edge 1-3
	graphe->arcs[3].src = 1;
	graphe->arcs[3].dest = 3;
	graphe->arcs[3].poids = 15;

	// add edge 2-3
	graphe->arcs[4].src = 2;
	graphe->arcs[4].dest = 3;
	graphe->arcs[4].poids = 4;

	Kruskal(graphe);*/

	printf("\n EXAM \n");
	exo2();

	printf("\n");

	exo4();

	/* Let us create the following graph
        2   3
    (0)--(1)--(2)
    |    / \    |
   6|  8/   \5  |7
    |  /     \  |
    (3)-------(4)
          9         */
/*
    freopen("matriceDadjacence.txt", "r", stdin);
    MatriceDAdjacence graphe1 = creerMatAdjGO();

    Prim(graphe1, 1);*/

    // Print the solution
    //primMST(graph);

	return 0;
}
