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

/* cette fonction retourne la liste des successeurs
    d'un sommet  x */
int* construireListeSuccesseur(MatriceDAdjacence graphe, int x);

/* cette fonction affiche le resultat de
     parcours en Largeur */
void parcoursLargeur(MatriceDAdjacence graphe, int r); // BFS

/* cette fonction retourne le resultat de parcours en Largeur
    qui sera exploiter en construction des couches et tester si
    un graphe est biparti!
*/
Marque* BFS(MatriceDAdjacence graphe, int r);


/* cette fonction affiche le resultat de
     parcours en Profondeur */
void parcoursProfondeur(MatriceDAdjacence, int); // DFS

/* Tester si un graphe est biparti avec
un parcours en largeur
*/
int grapheBipartiBFS(MatriceDAdjacence, int);

/* cette fonction retourne une file
Contenant les couches obtenues par un parcours en largeur */
pFile* partitionerEnCouche(Marque *marque, int n);

void afficherCouches(MatriceDAdjacence graphe);

/* cette fonction affiche le resultat de
     parcours en Profondeur */
void DFS(MatriceDAdjacence graphe, int);
void DFS_Visite(MatriceDAdjacence graphe, Sommet *tabSommet, int u);


#endif // H_GRAPHEPARCOURS
// HASSAN ZEKKOURI
