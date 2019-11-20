#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"
#include "utilitaires.h"

/******************************** creerMatAdjGO() **************************************/

MatriceDAdjacence creerMatAdjGO(){
          /** Cette fonction saisie et initialise la matrice d'adjacence
            d'un graphe orienté */

          MatriceDAdjacence m;
          printf("Saisir le nombre de sommets de votre graphe: |X| = ");
          scanf("%d", &m.n);

          int i,j;
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              printf("Si l\'arc  %d --> %d  existe taper son poids sinon 0: ", i+1, j+1);
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
          printf("Saisir le nombre de sommets : |X| = ");
          scanf("%d", &m.n);

          int i,j;
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j <=i ; j++){
                              printf("Si l\'arete  %d ---- %d  existe taper son poids sinon taper 0 : ", i+1, j+1);
                              scanf("%d", &m.matrice[i][j]);
                              m.matrice[j][i] = m.matrice[i][j];
                              // Ici on stock une partie triangulaire
                              // et on en deduit l'autre (matrice symetrique)
                    }
          }
return m;
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


