#ifndef H_GRAPHEPARCOURS
#define H_GRAPHEPARCOURS
#include "graphe_matrice.h"
#include "file.h"

typedef struct marque Marque;
struct marque{
    char couleur;
    int pere;
    int dist;
};

typedef struct sommet Sommet;
struct sommet{
    char couleur;
    int pere;
    int decouverte;
    int fin;
};

void parcoursLargeur(MatriceDAdjacence graphe, int r); // BFS
Marque* BFS(MatriceDAdjacence graphe, int r);
void parcoursProfondeur(MatriceDAdjacence, int); // DFS
int grapheBipartiBFS(MatriceDAdjacence);
int grapheBipartiDFS(MatriceDAdjacence);
pFile* partitionerEnCouche(Marque *marque, int n);
void DFS(MatriceDAdjacence graphe);

#endif // H_GRAPHEPARCOURS
