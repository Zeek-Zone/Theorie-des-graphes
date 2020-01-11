
#include "utilitaires.h"
#include "graphe_matrice.h"

Graphe* creerGraphe(int numSommet, int numLien){

	Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
	graphe->numSommet = numSommet;
	graphe->numLien = numLien;

	graphe->arcs = (Arc*)malloc(numLien * sizeof(Arc));

	return graphe;
}

Composante* creerComposante(){
    Composante *neuf = (Composante*)malloc(sizeof(Composante));

    neuf->nbrSommet = 0;
    neuf->sommets = (int*)malloc(sizeof(int));

return neuf;
}

void cfc(){
    freopen("composanteFconnexe.txt", "r", stdin);
    MatriceDAdjacence graphe = creerMatAdjGO();
    composanteFortementConnexe(graphe);
}


CFC* creerCFC(){
    CFC *neuf = (CFC*)malloc(sizeof(CFC));
    neuf->taille = 0;
    neuf->composantes = (Composante*)malloc(sizeof(Composante));

return neuf;
}

void saisirArcs(Graphe *graphe){
    freopen("kruskal.txt", "r", stdin);
    int i;
    for(i = 0; i < graphe->numLien; i++){
        scanf("%d%d%d", &graphe->arcs[i].src, &graphe->arcs[i].dest, &graphe->arcs[i].poids);
    }
}

void fermeture(){
    freopen("fermeture_trans.txt", "r", stdin);
    MatriceDAdjacence graphe1 = creerMatAdjGO();
    Warshall(graphe1);
}


void arbreMST(){

    printf("\nQuelle algorithme?\n");
    printf("---->>> 1. Kruskal\n");
    printf("---->>> 2. Prim\n");
    printf("Veuillez saisir votre choix:\n");
    int choix;
    scanf("%d", &choix);

    int V = 12; // nombre de sommets
    int E = 23; // nombre d'arcs
    Graphe* graphe = creerGraphe(V, E);

    switch(choix){
        case 1:
            saisirArcs(graphe);
            Kruskal(graphe);
            break;
        case 2:
            freopen("prim.txt", "r", stdin);
            MatriceDAdjacence graphe1 = creerMatAdjGNO();
            Prim(graphe1, 1);
            break;
        default:
            printf("choix non valide!\n");
    }

}

void coloriage(){
    freopen("coloriage.txt", "r", stdin);
    MatriceDAdjacence graphe = creerMatAdjGNO();
    int *degre = (int*)calloc(10, sizeof(int)); // tous à zero
    int *colore = (int*)calloc(10, sizeof(int));  // tous à zero: non coloré
    printf("\n########## Debut de Coloriage ########\n");
    Powell_Welsh(graphe, degre, colore);
}

