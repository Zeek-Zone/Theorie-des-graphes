
#include "graphe_matrice.h"


/******************************** creerMatAdjGO() **************************************/

MatriceDAdjacence creerMatAdjGO(){
          /** Cette fonction saisie et initialise la matrice d'adjacence
            d'un graphe orienté */

          MatriceDAdjacence m;

          scanf("%d", &m.n);

          int i,j;
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              scanf("%d", &m.matrice[i][j]);
                    }
          }
return m;
}

/********************************** creerMatAdjGNO() ************************************/

MatriceDAdjacence creerMatAdjGNO(){
          /** Cette fonction saisie et initialise la matrice d'adjacence
            d'un graphe non orienté*/

          MatriceDAdjacence m;

          scanf("%d", &m.n);

          int i,j;
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j <=i ; j++){
                              scanf("%d", &m.matrice[i][j]);
                              m.matrice[j][i] = m.matrice[i][j];
                              // Ici on stock une partie triangulaire
                              // et on en deduit l'autre (matrice symetrique)
                    }
          }
return m;
}

/****************************** afficheArcs(MatriceDAdjacence m) ****************************************/

void afficheArcs(MatriceDAdjacence m){
          /* Cette fonction affiche les arcs
            d'un graphe  orienté */
          int i,j;
          printf("\nVoici la Liste des arcs :\n");
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              if( m.matrice[i][j] )
                                        printf("%d --> %d,\t",  i+1, j+1);
                    }
                    printf("\n");
          }
return;
}

Arc* trouverArcs(MatriceDAdjacence m){
          /* Cette fonction affiche les arcs
            d'un graphe  orienté */
          int i,j, size = 0;
          Arc *arc = (Arc*)malloc(sizeof(Arc));
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              if( m.matrice[i][j] )
                                        {
                                            size++;
                                            arc = (Arc*)realloc(arc, size * sizeof(Arc));
                                            arc[size-1].src = i+1;
                                            arc[size-1].dest = j+1;
                                            arc[size-1].poids = m.matrice[i][j];
                                        }
                    }
          }
return arc;
}

/******************************* afficheArete(MatriceDAdjacence m) ***************************************/

void afficheArete(MatriceDAdjacence m){
          /* Cette fonction affiche les aretes
            d'un graphe non orienté */
          int i,j;
          printf("\nVoici la Liste des aretes :\n");
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j <= i; j++){
                              if( m.matrice[i][j] )
                                        printf("%d ---- %d,\t ",  i+1, j+1);
                    }
                    printf("\n");
          }
return;
}

/**************************** afficheMatriceAdjacence(MatriceDAdjacence m) ******************************************/

void afficheMatriceAdjacence(MatriceDAdjacence m){
          /* Cette fonction affiche la matrice d'adjacence
            d'un graphe */
          int i, j;
          printf("\nVoici la matrice d'adjacence de votre graphe:\n");
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                        printf("%d\t",  m.matrice[i][j]);
                    }
                    printf("\n");
          }
return;
}



// Hassan Zekkouri
