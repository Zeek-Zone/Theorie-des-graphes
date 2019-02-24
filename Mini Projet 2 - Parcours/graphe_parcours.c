#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"
#include "graphe_parcours.h"
#include "file.h"

#define NIVEAU 10
int numSuccessurs;
int temps;

int* construireListeSuccesseur(MatriceDAdjacence graphe, int x){

    int  i ,j = 0;
    numSuccessurs = 0;
    for(i = 0; i < graphe.n; i++)
        if(graphe.matrice[x][i] == 1){
                numSuccessurs++;
           }

    int *LS = (int*)malloc(numSuccessurs * sizeof(int));
    for(i = 0; i < graphe.n; i++)
        if(graphe.matrice[x][i] == 1){
                LS[j] = i;
                j++;
           }
return LS;
}

void parcoursLargeur(MatriceDAdjacence graphe, int racine){
    int tete, queue, *marque, i;
    pFile file = creerFile();
    marque = (int*)malloc(graphe.n * sizeof(int));
    for(i = 0; i < graphe.n ; i++) marque[i] = 0;
    tete  = 0;
    queue = 0;
    enfile(file, racine-1);
    printf("\n%d ", racine);
    marque[racine-1] = 1;

    while(tete <= queue){
        int x = defilement(file);
        int *LS = construireListeSuccesseur(graphe, x);
        //int taille = sizeof(LS)/sizeof(LS[0]);
        int j;
        for(j = 0; j < numSuccessurs; j++){
            int y = LS[j];
            if(marque[y] == 0){
                marque[y] = marque[x] + 1;
                queue++;
                enfile(file, y);
                printf("%d ", y+1);
            }
        }
        tete++;
    }
    printf("\nFin de parcours BFS! \n");
}

Marque* BFS(MatriceDAdjacence graphe, int r){
    /* cette fonction retourne le resultat de parcours en Largeur */
    Marque *marque = (Marque*)malloc(graphe.n * sizeof(Marque));
    pFile file = creerFile();
    int i;
    for(i = 0; i < graphe.n ; i++){
        marque[i].couleur = 'b'; //blanc
        marque[i].pere = -1;
        marque[i].dist = 999999999;
    }

    // marquer la racine
    marque[r-1].couleur = 'g';
    marque[r-1].dist = 0;
    enfile(file, r-1);
    //printf("\n%d ", r);

    while(file->taille > 0){
        int x = defilement(file), y;
        int *LS = construireListeSuccesseur(graphe, x);
        //int taille = sizeof(LS)/sizeof(LS[0]);
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
    //printf("\nFin de parcours! \n");
return marque;
}

pFile* partitionerEnCouche(Marque *marque, int n){
    pFile *couches = (pFile*)malloc(NIVEAU * sizeof(pFile));
    int i;
    for(i = 0; i < NIVEAU; i++) couches[i] = creerFile();

    for(i = 0 ; i < n; i ++){
        int niveau = marque[i].dist;
        //printf("-N%d %d \n",niveau, i);
        if(niveau <= NIVEAU)
          enfile(couches[niveau], i+1);
    }
return couches;
}

void afficherCouches(MatriceDAdjacence graphe){
    Marque *marque = BFS(graphe, 1);
    pFile* couches = partitionerEnCouche(marque, graphe.n);
    int i;
    for(i = 0; i < NIVEAU; i++){
        if(couches[i]->taille){
            printf("C(%d) : ", i);
            afficheFile(couches[i]);
            printf("\n");
        }
    }
}

int grapheBipartiBFS(MatriceDAdjacence graphe){
    Marque *marque = BFS(graphe, 5);

    pFile* couches = partitionerEnCouche(marque, graphe.n);

    /* S'il existe un arc entre deux éléments de même couches
    on return 0 (non biparti) */
    int i = 0;
    for(i = 0; i < NIVEAU ; i++){
        if(couches[i]->taille > 1){
            pCellule x, y;
            x = couches[i]->tete;
            y = NULL;
            while(x->suivant != NULL){
                y = x->suivant; //printf("-N%d %d ", i,y->element);
                if( graphe.matrice[x->element -1][y->element -1] == 1 || graphe.matrice[y->element -1][x->element -1] == 1)
                    return 0;
                while(y->suivant != NULL){
                    y = y->suivant; //printf("-N%d %d ", i, y->element);
                    if( graphe.matrice[x->element -1][y->element -1] == 1 || graphe.matrice[y->element -1][x->element -1] == 1)
                        return 0;
                }
                x = x->suivant;
            }
            printf("\n ");
        }
    }
return 1; // graphe biparti
}


void parcoursProfondeur(MatriceDAdjacence graphe, int racine){
    /* cette fonction retourne le resultat de parcours en profondeur */
    int *marque, i;
    pFile pile = creerFile();
    marque = (int*)malloc(graphe.n * sizeof(int));
    for(i = 0; i < graphe.n ; i++) marque[i] = 0;//Faux
    empiler(pile, racine-1);
    printf("\n%d ", racine);
    marque[racine-1] = 1;// Vrai

    while(pile->taille){
        int x = depiler(pile);
        int *LS = construireListeSuccesseur(graphe, x);
        int j;
            for(j = 0; j < numSuccessurs; j++){
                int y = LS[j];
                if(marque[y] == 0){
                    marque[y] = 1; // Vrai
                    empiler(pile, y);
                    printf("%d ", y+1);
                }
            }

    }
    printf("\nFin de parcours DFS! \n");
}


void DFS(MatriceDAdjacence graphe){
    Sommet *tabSommet = (Sommet*)malloc((graphe.n) * sizeof(Sommet));
    int i;
    for(i = 0; i < graphe.n; i++){
        tabSommet[i].couleur = 'B';
        tabSommet[i].pere = -1;
    }
    temps = 0;
    for(i = 0; i < graphe.n; i++){
        if( tabSommet[i].couleur == 'B'){
            tabSommet[i].decouverte = temps++;
            tabSommet[i].couleur = 'G';
            printf("S%d ", i+1);
            DFS_Visite(graphe, tabSommet, i);
        }
    }
}

void DFS_Visite(MatriceDAdjacence graphe, Sommet *tabSommet, int u){
    int v, j;
    int *LS = construireListeSuccesseur(graphe, u);
        for(j = 0; j < numSuccessurs; j++){
            v = LS[j];
            if(tabSommet[v].couleur == 'B'){
                tabSommet[v].couleur = 'G'; // visité
                tabSommet[v].pere = u;
                tabSommet[v].decouverte = temps++;
                DFS_Visite(graphe, tabSommet, v);
                printf("S%d ", v+1);
            }
        }
        tabSommet[u].fin = temps++;
}
