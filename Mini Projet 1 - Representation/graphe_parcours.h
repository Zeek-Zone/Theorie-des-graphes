#ifndef H_GRAPHEPARCOURS
#define H_GRAPHEPARCOURS
#include "graphe_matrice.h"
void parcoursLargeur(MatriceDAdjacence graphe, int x); // BFS
void parcoursProfondeur(MatriceDAdjacence, int); // DFS
int grapheBipartiBFS(MatriceDAdjacence);
int grapheBipartiDFS(MatriceDAdjacence);

#endif // H_GRAPHEPARCOURS
