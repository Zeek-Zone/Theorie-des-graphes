#ifndef H_GUTILS
#define H_GUTILS
#include "graphe_matrice.h"
#include "graphe_liste.h"

/**
* Fichier header des utilités liés aux graphes:
*
*  @author Hassan Zekkouri
* @date 30/11/2018   23:30
*/

MatriceDAdjacence getMatriceDAdjacence( MesListeDAdjacence *liste);
void maMatriceDadjacence();
void maMatriceDincidence();
void mesListesDadjacence();
void mesTablesPSetLS();
void monFileFSetTabAPS();

#endif // H_GUTILS
