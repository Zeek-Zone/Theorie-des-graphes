#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"
#include "graphe_parcours.h"
#include "file.h"

int* construireListeSuccesseur(MatriceDAdjacence graphe, int x){

    int numSuccessurs = 0, i ,j = 0;
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
    File *file = (File*)malloc(sizeof(File));
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
        for(j = 0; j < 1; j++){
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
    printf("\nFin de parcours! \n");
}
