#include <stdio.h>
#include <stdlib.h>
#include "utilitaires.h"
#include "bellman_ford.h"
#include "djikstra.h"
#include "bellman.h"

void menu();

int main()
{
    printf("############ Bienvenu sur le Mini Projet: ##############\n");
    printf("-----------> A la recherche de plus court chemin!\n");

    int choix, x0;
    printf("Veuillez saisir le sommet source x0 :\n");
    scanf("%d", &x0);

    debut:
        menu();
        scanf("%d", &choix);

        switch(choix){
        case 1:
            freopen("dijkstra.txt", "r", stdin);
            MatriceDAdjacence graphe1 = creerMatAdjGO();
            Dijkstra(graphe1, x0);
            break;
        case 2:
            freopen("bellman.txt", "r", stdin);
            graphe1 = creerMatAdjGO();
            Bellman(graphe1, x0);
            break;
        case 3:
            freopen("bellman_ford.txt", "r", stdin);
            int V, E;
            scanf("%d%d", &V, &E);
            Graphe *graphe = creerGraphe(V, E);
            saisirGraphe(graphe);
            BellmanFord(graphe, x0);
            break;
        default:
            printf("Choix non valide, veuillez reconsidérer votre choix SVP!\n");
            goto debut;
        }

    return 0;
}

void menu(){
    printf("\nChoix de l\'algorithme!\n");
    printf("\n1. Dijkstra (poids positifs);\n");
    printf("2. Bellman (graphe acyclique);\n");
    printf("3. Bellman Ford (cas general);\n");
    printf("\nVeuillez saisir votre choix!\n");
}
