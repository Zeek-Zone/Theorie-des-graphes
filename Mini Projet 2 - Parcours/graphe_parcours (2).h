#ifndef H_GRAPHEPARCOURS
#define H_GRAPHEPARCOURS
#include "graphe_matrice.h"
#include "file.h"

/**
*   fichier header contenant les declarations de toutes les structures
*   et fonctions des graphes nécessaire pour les différents parcours.
*   @author Hassan Zekkouri
*   le 02/02/2019
*/

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

int grapheBipartiBFS(MatriceDAdjacence, int);

int grapheBipartiDFS(MatriceDAdjacence);

pFile* partitionerEnCouche(Marque *marque, int n);

void afficherCouches(MatriceDAdjacence graphe, int racine);

void DFS(MatriceDAdjacence graphe, int);

void DFS_Visite(MatriceDAdjacence graphe, Sommet *tabSommet, int u);

#endif // H_GRAPHEPARCOURS
