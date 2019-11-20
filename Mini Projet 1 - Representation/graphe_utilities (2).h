#ifndef H_GUTILS
#define H_GUTILS

#include<stdlib.h>
#include<stdio.h>
#include "graphe_parcours.h"
#include "graphe_matrice.h"
#include "graphe_liste.h"

/**
* Fichier header des utilitaires liés aux graphes:
*
* @author Hassan Zekkouri
* @date 30/11/2018   23:30
*/

// Cette fonction parcours les listes d'adjacences et
// retourne la matrice d'adjacence associée
MatriceDAdjacence getMatriceDAdjacence( MesListeDAdjacence *liste);

//Pour tester les fonctionalité liées aux matrices d'adjacences
void maMatriceDadjacence();

// Pour tester les fonctionalité liées aux matrices d'incidences
void maMatriceDincidence();

// Pour tester les fonctionalité liées aux listes d'adjacences
void mesListesDadjacence();

// Cette fonction represente le graphe avec les deux tableaux PS et LS
void mesTablesPSetLS();

//Cette fonction represente le graphe avec les deux tableaux FS et APS
void monFileFSetTabAPS();


// Affichage d'un tableau tab de taille n
void afficherTableau(int tab[], int n);
// Saisie d'un tableau tab de taille n
void saisirTableau(int tab[], int n);

// une structure representant l'arc
typedef struct arC{   // arete
	int src,
        dest,
        poids;
}ArcValue;


// la structure representant le graphe par ses arcs (aretes) valué
typedef struct graphe{

	int numSommet, numLien;
	ArcValue* arcs;

}Graphe;

// Cette fonction permet de representer le graphe avec ses liaison
Graphe* creerGraphe(int numSommet, int numLien);

// Cette fonction permet de saisir le graphe
void saisirGraphe(Graphe *graphe);

// Tester le graphe "Graphe"
void grapheEnLiaison();


#endif // H_GUTILS
// Hassan Zekkouri
