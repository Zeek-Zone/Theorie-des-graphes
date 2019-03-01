#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"
#include "graphe_parcours.h"
#include "file.h"
#include "djikstra.h"
#define NIVEAU 10 // niveau maximal, à adaper selon le besoin
int numSuccessurs;
int temps;

/***************************** construireListeSuccesseur(MatriceDAdjacence graphe, int x) dens djikstra.h ***********************************/


/************************** parcoursLargeur(MatriceDAdjacence graphe, int racine)**************************************/

void parcoursLargeur(MatriceDAdjacence graphe, int racine){

    int tete, queue, i;
    pFile file = creerFile();
    int *marque = (int*)malloc(graphe.n * sizeof(int));

    /// au debut tout les sommets sont non marqué
    for(i = 0; i < graphe.n ; i++) marque[i] = 0;

    tete  = 0;
    queue = 0;

    enfile(file, racine);
    //printf("\n%d ", racine); // affichage sans père

    printf("\n Racine: %d \n", racine);
    marque[racine] = 1; // marqué la racine

    while(tete <= queue){
        int x = defilement(file);
        int *LS = construireListeSuccesseur(graphe, x);
        int j;
        for(j = 0; j < numSuccessurs; j++){
            int y = LS[j];
            if(marque[y] == 0){
                marque[y] = marque[x] + 1;  // marqué y
                queue++;
                enfile(file, y);
                //printf("%d ", y); // affichage sans père
                printf("S(%d) :  le pere est S(%d)\n", y, x);

            }
        }
        tete++;
    }
    printf("\nFin de parcoursLargeur (BFS)! \n");
}

/************************** BFS(MatriceDAdjacence graphe, int r) **************************************/

Marque* BFS(MatriceDAdjacence graphe, int r){

    /* cette fonction retourne le resultat de parcours en Largeur
    qui sera exploiter en construction des couches et tester si
    un graphe est biparti!
    */

    Marque *marque = (Marque*)malloc(graphe.n * sizeof(Marque));
    pFile file = creerFile();
    int i;

    /// au debut tout les sommets sont non marqués
    for(i = 0; i < graphe.n ; i++){
        marque[i].couleur = 'b'; //blanc
        marque[i].pere = -1;
        marque[i].dist = 999999999;
    }

    // marquer la racine
    marque[r].couleur = 'g';
    marque[r].dist = 0;
    enfile(file, r);
    //printf("\n%d ", r);

    while(file->taille > 0){
        int x = defilement(file), y;
        int *LS = construireListeSuccesseur(graphe, x);
        int j;
        for(j = 0; j < numSuccessurs; j++){
            y = LS[j];
            if(marque[y].couleur == 'b'){
                marque[y].couleur = 'g'; // visité
                marque[y].pere = x;
                marque[y].dist = marque[x].dist + 1;
                enfile(file, y);
                //printf("%d ", y+1);
            }
        }
        marque[x].couleur = 'n'; // exploré
    }
    //printf("\nFin de parcoursBFS 2! \n");
return marque;
}



/****************************** parcoursProfondeur(MatriceDAdjacence graphe, int racine) **********************************/

void parcoursProfondeur(MatriceDAdjacence graphe, int racine){

    /* cette fonction affiche le resultat de parcours en profondeur */

    int i;
    pFile pile = creerFile(); // ici c'est un pile : ajout et suppression en tete
    int *marque = (int*)malloc(graphe.n * sizeof(int));

    for(i = 0; i < graphe.n ; i++)
        marque[i] = 0; //Faux: non marqué

    empiler(pile, racine);
    marque[racine] = 1;// Vrai: marqué

    while(pile->taille){ // pile non vide
        int x = depiler(pile);
        //printf("%d ", x); // affichage sans père
         printf("%d ", x);
        int *LS = construireListeSuccesseur(graphe, x);
        int j;
            for(j = 0; j < numSuccessurs; j++){
                int y = LS[j];
                if(marque[y] == 0){
                    marque[y] = 1; // Vrai: marqué
                    empiler(pile, y);
                }
            }

    }

    printf("\nFin de parcours en profondeur (DFS)! \n");
}

/*************************** DFS(MatriceDAdjacence graphe) *************************************/

/*
void DFS(MatriceDAdjacence graphe, int racine){
    Sommet *tabSommet = (Sommet*)malloc((graphe.n) * sizeof(Sommet));
    int i;
    for(i = 0 ; i < graphe.n; i++){
        tabSommet[i].couleur = 'B';
        tabSommet[i].pere = -1;
    }
    temps = 0;
    for(i = 0; i < graphe.n ; i++){
        if( tabSommet[i].couleur == 'B'){
            tabSommet[i].decouverte = temps++;
            tabSommet[i].couleur = 'G';
            printf("S%d ", i);
            DFS_Visite(graphe, tabSommet, i);
        }
    }
    printf("hh");
    free(tabSommet);
    return;
}
*/
/***************************** DFS_Visite(MatriceDAdjacence graphe, Sommet *tabSommet, int u) ***********************************/
/*
void DFS_Visite(MatriceDAdjacence graphe, Sommet *tabSommet, int u){
    int v, j;

    int *LS = construireListeSuccesseur(graphe, u);
        for(j = 0; j < numSuccessurs; j++){
            v = LS[j];
            printf(" here %d\n", v);
            if(tabSommet[v].couleur == 'B'){
                tabSommet[v].couleur = 'G'; // visité
                tabSommet[v].pere = u;
                tabSommet[v].decouverte = temps++;
                printf("S%d ", v);
                DFS_Visite(graphe, tabSommet, v);
            }
        }

        tabSommet[u].fin = temps++;
        free(LS);
        return;
}
*/
