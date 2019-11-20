#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"
#include "graphe_parcours.h"
#include "file.h"

#define NIVEAU 10 // niveau maximal, à adaper selon le besoin
int numSuccessurs;
int temps;

/***************************** construireListeSuccesseur(MatriceDAdjacence graphe, int x) ***********************************/

int* construireListeSuccesseur(MatriceDAdjacence graphe, int x){
    /* cette fonction retourne la liste des successeurs
    d'un sommet  x */

    int  i ,j = 0;
    numSuccessurs = 0;
    for(i = 0; i < graphe.n; i++)
        if(graphe.matrice[x][i] == 1){
                numSuccessurs++;
           }

    int *LS = (int*)malloc(numSuccessurs * sizeof(int));
    // remplissage de LS
    for(i = 0; i < graphe.n; i++)
        if(graphe.matrice[x][i] == 1){
                LS[j] = i;
                j++;
           }
return LS;
}

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

    printf("\nRacine: %d \n\n", racine);
    marque[racine] = 1; // marqué la racine

    printf("S(i) \t| \t Pere\n");
    printf("------------------------\n");
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
                printf("S(%d) \t| \t S(%d)\n", y, x);

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
    marque[r-1].couleur = 'g';
    marque[r-1].dist = 0;
    enfile(file, r-1);
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

/************************** partitionerEnCouche(Marque *marque, int n) **************************************/

pFile* partitionerEnCouche(Marque *marque, int n){
     // marque: contient le resultat de parcours en largeur
    // couches: tableau contenant les file de sommets de chaque niveau

    pFile *couches = (pFile*)malloc(NIVEAU * sizeof(pFile));
    int i;
    // initialisation
    for(i = 0; i < NIVEAU; i++)
        couches[i] = creerFile();

    for(i = 0 ; i < n; i ++){
        int niveau = marque[i].dist;
        //printf("Niveau %d Sommet %d\n",niveau, i);
        if(niveau <= NIVEAU)
          enfile(couches[niveau], i+1);
    }

return couches;
}

/************************** afficherCouches(MatriceDAdjacence graphe) **************************************/

void afficherCouches(MatriceDAdjacence graphe, int racine){

    Marque *marque = BFS(graphe, racine);
    pFile* couches = partitionerEnCouche(marque, graphe.n);
    int i;
    for(i = 0; i < NIVEAU; i++){
        if(couches[i]->taille){ // // couche (file) non vide
            printf("C(%d) : ", i);
            afficheFile(couches[i]);
            printf("\n");
        }
    }

}

/**************************** grapheBipartiBFS(MatriceDAdjacence graphe) ************************************/

int grapheBipartiBFS(MatriceDAdjacence graphe, int racine){

    Marque *marque = BFS(graphe, racine);
    pFile* couches = partitionerEnCouche(marque, graphe.n);

    /* S'il existe un arc entre deux éléments de même couches
    on return 0 (non biparti) */

    int i = 0;
    // on vérifier s'il existe des liens entre les sommets d'une couche
    for(i = 0; i < NIVEAU ; i++){

        if(couches[i]->taille > 1){ // couche (file) non vide

            pCellule x, y;
            x = couches[i]->tete;
            y = NULL;

            while(x->suivant != NULL){

                y = x->suivant;
                int a = x->element; // sommet 1
                int b = y->element; // sommet 2
                // on test avec le sommet suivant
                if( graphe.matrice[a-1][b-1] == 1 || graphe.matrice[b-1][a-1] == 1)
                    return 0;
                // on test avec les sommet apres le sommet suivant
                while(y->suivant != NULL){
                    y = y->suivant;
                    b = y->element; // sommet 2
                    if( graphe.matrice[a-1][b-1] == 1 || graphe.matrice[b-1][a-1] == 1)
                        return 0;
                }

                x = x->suivant;
            }
            printf("\n ");
        }
    }
return 1; // graphe biparti
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
    printf("\nSommet \t\t Pere\n", racine, pere[racine]);
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
    printf("Source %d:   et on a ( pere(S(i)) --->S(i) ) \n", racine);
    for(i = 0; i < graphe.n ; i++){
        if( tabSommet[i].couleur == 'B'){
            tabSommet[i].decouverte = temps++; //  ordre de visite
            tabSommet[i].couleur = 'G'; // visité : Gris
            printf("%d\n", i);
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
                printf("(%d --> ) %d\n", u, v);
                nombreDeSommetVisite++;
                // On va visité les successeurs de v
                DFS_Visite(graphe, tabSommet, v);
            }
        }

        tabSommet[u].fin = temps++; // ordre d'exploration
        free(LS);
        return;
}
