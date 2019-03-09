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

// Cette fonction cree une liste d'adjacence initialement vide
Liste* creerListe();

// Cette fonction permet d'ajouter une liste d'adjacence
void insert(MesListeDAdjacence *liste, int valeur);

// Cette fonction cree une liste de controle initialement vide
MesListeDAdjacence* creerListeDAdjacence();

// Cette fonction permet d'afficher toutes les listes d'adjacences
void afficherListeAdj(MesListeDAdjacence *liste);

#endif // H_GRAPHELISTE

