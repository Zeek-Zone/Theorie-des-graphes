#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "graphe_matrice.h"
#include "utilitaires.h"

int numSuccessurs;

int* construireListeSuccesseur(MatriceDAdjacence graphe, int x){
    /* cette fonction retourne la liste des successeurs
    d'un sommet x */

    int  i ,j = 0;
    numSuccessurs = 0;
    // detection de nombre de successeurs
    for(i = 0; i < graphe.n; i++)
        if(graphe.matrice[x][i] != 0){
                numSuccessurs++;
           }

    int *LS = (int*)malloc(numSuccessurs * sizeof(int));
    // remplissage de LS
    for(i = 0; i < graphe.n; i++)
        if(graphe.matrice[x][i] != 0){
                LS[j] = i;
                j++;
           }
return LS;
}


int sommetSuivant(int *lambda, int n, int *marque){
    int res = 0, temp = INT_MAX;
    int i;
    for(i = 0; i < n; i++){
        if(lambda[i] < temp && marque[i] == 0){
            res = i;
            temp = lambda[i];
        }
    }
return res;
}

void Dijkstra(MatriceDAdjacence graphe, int x0){

    int ordre = graphe.n;
    int *marque = (int*)malloc(ordre * sizeof(int));
    int *LS;
    int *lambda = (int*)malloc(ordre * sizeof(int));
    int *pi = (int*)malloc(ordre * sizeof(int));
    int nsm = 0; // nombre de sommets marqués
    int i, j, s;
    memset(marque, 0, ordre * sizeof(int));
    initialisation(lambda, pi, x0, ordre);
    while(nsm < ordre){
        i = sommetSuivant(lambda, ordre, marque);
        marque[i] = 1;
        nsm++;
        LS = construireListeSuccesseur(graphe, i);
        for(s = 0; s < numSuccessurs ; s++){
            j = LS[s];
            if(marque[j] == 0){
                relacher(lambda, pi, i, j, graphe.matrice[i][j]);
            }
        }

    }

    afficherDistanceEtPere(lambda, pi, ordre);
}
