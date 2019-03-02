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




/****************************** parcoursProfondeur(MatriceDAdjacence graphe, int racine) **********************************/

void parcoursProfondeur(MatriceDAdjacence graphe, int racine){

    /* cette fonction affiche le resultat de parcours en profondeur */

    int i;
    pFile pile = creerFile(); // ici c'est un pile : ajout et suppression en tete
    int *marque = (int*)malloc(graphe.n * sizeof(int));
    int *pere = (int*)malloc(graphe.n * sizeof(int));

    for(i = 0; i < graphe.n ; i++){
        marque[i] = 0; //Faux: non marqué
        pere[i] = -1;
        }

    empiler(pile, racine);
    printf("Sommet \t\t Pere\n", racine, pere[racine]);
    marque[racine] = 1;// Vrai: marqué

    while(pile->taille){ // pile non vide

        int x = depiler(pile);
        //printf("%d ", x); // affichage sans père
         printf("%d \t\t %d\n", x, pere[x]);

        int *LS = construireListeSuccesseur(graphe, x);
        int j;
            for(j = 0; j < numSuccessurs; j++){
                int y = LS[j];
                if(marque[y] == 0){
                    marque[y] = 1; // Vrai: marqué
                    empiler(pile, y);
                    pere[y] = x;
                }
            }

    }

    printf("\nFin de parcours en profondeur (DFS)! \n");
}

/*************************** DFS(MatriceDAdjacence graphe) *************************************/

int nombreDeSommetVisite = 0;

void DFS(MatriceDAdjacence graphe, int racine){
    Sommet *tabSommet = (Sommet*)malloc((graphe.n) * sizeof(Sommet));
    int i;
    // Initialisation
    for(i = 0 ; i < graphe.n; i++){
        tabSommet[i].couleur = 'B'; // non visité: blanc
        tabSommet[i].pere = -1;
    }
    temps = 0;
    // Pour tous les sommets
    // On va faire un DFS_visit
    for(i = 0; i < graphe.n ; i++){
        if( tabSommet[i].couleur == 'B'){
            tabSommet[i].decouverte = temps++; //  ordre de visite
            tabSommet[i].couleur = 'G'; // visité : Gris
            printf("Source :%d \n", i);
            nombreDeSommetVisite++;
            // On va visité les successeurs de i
            DFS_Visite(graphe, tabSommet, i);
        }
    }
    free(tabSommet);
    return;
}

/***************************** DFS_Visite(MatriceDAdjacence graphe, Sommet *tabSommet, int u) ***********************************/

void DFS_Visite(MatriceDAdjacence graphe, Sommet *tabSommet, int u){
    int v, j;

    if(nombreDeSommetVisite == graphe.n) exit(0);

    int *LS = construireListeSuccesseur(graphe, u);
        for(j = 0; j < numSuccessurs; j++){
            v = LS[j];
            if(tabSommet[v].couleur == 'B'){
                tabSommet[v].couleur = 'G'; // visité
                tabSommet[v].pere = u;
                tabSommet[v].decouverte = temps++; // ordre de visite
                printf("(%d -->) %d\n", u, v);
                nombreDeSommetVisite++;
                // On va visité les successeurs de v
                DFS_Visite(graphe, tabSommet, v);
            }
        }

        tabSommet[u].fin = temps++; // ordre d'exploration
        free(LS);
        return;
}

