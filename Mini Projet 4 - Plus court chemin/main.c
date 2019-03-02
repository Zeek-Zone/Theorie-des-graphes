#include <stdio.h>
#include <stdlib.h>
#include "utilitaires.h"
#include "bellman_ford.h"
#include "djikstra.h"

int main()
{
    printf("Hello world!\n");
    /* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	Graphe* graph = creerGraphe(V, E);

	// add edge 0-1 (or A-B in above figure)
	graph->arcs[0].src = 0;
	graph->arcs[0].dest = 1;
	graph->arcs[0].poids = -1;

	// add edge 0-2 (or A-C in above figure)
	graph->arcs[1].src = 0;
	graph->arcs[1].dest = 2;
	graph->arcs[1].poids= 4;

	// add edge 1-2 (or B-C in above figure)
	graph->arcs[2].src = 1;
	graph->arcs[2].dest = 2;
	graph->arcs[2].poids = 3;

	// add edge 1-3 (or B-D in above figure)
	graph->arcs[3].src = 1;
	graph->arcs[3].dest = 3;
	graph->arcs[3].poids = 2;

	// add edge 1-4 (or A-E in above figure)
	graph->arcs[4].src = 1;
	graph->arcs[4].dest = 4;
	graph->arcs[4].poids = 2;

	// add edge 3-2 (or D-C in above figure)
	graph->arcs[5].src = 3;
	graph->arcs[5].dest = 2;
	graph->arcs[5].poids = 5;

	// add edge 3-1 (or D-B in above figure)
	graph->arcs[6].src = 3;
	graph->arcs[6].dest = 1;
	graph->arcs[6].poids = 1;

	// add edge 4-3 (or E-D in above figure)
	graph->arcs[7].src = 4;
	graph->arcs[7].dest = 3;
	graph->arcs[7].poids = -3;

	BellmanFord(graph, 0);

		/* Let us create the following graph
        2   3
    (0)--(1)--(2)
    |    / \    |
   6|  8/   \5  |7
    |  /     \  |
    (3)-------(4)
          9         */

    freopen("matriceDadjacence.txt", "r", stdin);
    MatriceDAdjacence graphe1 = creerMatAdjGO();
    Dijkstra(graphe1, 0);


    return 0;
}
