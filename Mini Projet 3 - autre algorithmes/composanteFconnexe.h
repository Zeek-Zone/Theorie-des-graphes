
#ifndef H_CFC
#define H_CFC

#include "graphe_matrice.h"
#include "utilitaires.h"
#include "pile.h"

void ajouterComposante(CFC *cfc, Composante *c);

int* fusioner(int *tab1, int n, int *tab2, int m);

int choisirUnSommet(int *sommetDansCFC, int n);

int trouverArcNonMarque(MatriceDAdjacence graphe, Pile *P, int *sommetDansCFC, Arc *arcsMarque);

int trouverComposante(Pile *P, int s);

void mettreAjourLaPile(Pile *P, int indice);

void marquerSommet(Composante c, int *sommetDansCFC);

void marquerArc(Arc *arcMarque, int s, int ss);

int arcNestPasMarque(Arc *arcMarque, int s, int ss);

Composante *compsanteEmpile(int s);

void composanteFortementConnexe(MatriceDAdjacence graphe);

#endif // H_CFC


