#ifndef H_PILE
#define H_PILE

#include <stdio.h>
#include <stdlib.h>
#include "utilitaires.h"


typedef struct Element Element;
struct Element
{
    Composante comp;
    Element *suivant;
};


typedef struct Pile Pile;
struct Pile
{
    int taille;
    Element *premier;
};

Pile *initialiser();
void empiler(Pile *pile, Composante *c);
Composante* depiler(Pile *pile);
//void afficherPile(Pile *pile);

#endif
