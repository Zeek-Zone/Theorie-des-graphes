#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

Pile *initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
    pile->taille = 0;
}

void empiler(Pile *pile, Composante *c)
{
    Element *nouveau = (Element*)malloc(sizeof(Element));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = c;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

Composante* depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Composante *ComposanteDepile = creerComposante();
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        ComposanteDepile = elementDepile->comp;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return ComposanteDepile;
}


/*
void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n");
}*/

