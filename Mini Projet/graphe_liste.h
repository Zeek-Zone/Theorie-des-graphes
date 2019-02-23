#ifndef H_GRAPHELISTE
#define H_GRAPHELISTE
#include "graphe_file.h"

/**
* Fichier header des élément lié aux listes chainées de projets
* @author Hassan Zekkouri
* @date 18/11/2018   20:30
* @project Mini-projet : Imlémentations des graphes
*/

/****************************************************************/

/**
*  Liste: (Element de la structure principale)
          extInitial : Entier
          file : Pointeur sur le file des successeurs de extInitial
          suivant : Pointeur sur la liste suivante
*/
typedef struct liste Liste;
struct liste{
          int extInitial;
          FileSuccesseur *file;
          Liste* suivant;
};

/**
*  MesListeDAdjacence: (structure principale/controle)
          taille : Entier
          debut : Pointeur sur la premiere liste d'adjacence
          fin: Pointeur sur la derniere liste d'adjacence
*/
typedef struct mesListAdj MesListeDAdjacence;
struct mesListAdj{
          int taille;
          Liste* debut;
          Liste* fin;
};


Liste* creerListe(); // liste des elements
void insert(MesListeDAdjacence *liste, int valeur);
MesListeDAdjacence* creerListeDAdjacence(); // la liste de controle
void afficherListeAdj(MesListeDAdjacence *liste);
void supprimeListeAdj(MesListeDAdjacence *liste);

#endif // H_GRAPHELISTE

