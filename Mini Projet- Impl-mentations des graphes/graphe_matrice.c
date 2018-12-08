#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"


MatriceDAdjacence creerMatAdjGO(){
          /* Cette fonction saisie et initialise la matrice d'adjacence
            d'un graphe orienté */
          MatriceDAdjacence m;
          printf("Saisir le nombre de sommets : n = ");
          scanf("%d", &m.n);
          int i,j;
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              printf("Si l\'arc  %d --> %d  existe taper 1 sinon taper 0 : ", i+1, j+1);
                              scanf("%d", &m.matrice[i][j]);
                    }
          }
return m;
}

/**********************************************************************/

MatriceDAdjacence creerMatAdjGNO(){
          /* Cette fonction saisie et initialise la matrice d'adjacence
            d'un graphe  non orienté*/
          MatriceDAdjacence m;
          printf("Saisir le nombre de sommets : n = ");
          scanf("%d", &m.n);
          int i,j;
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j <=i ; j++){
                              printf("Si l\'arete  %d ---- %d  existe taper 1 sinon taper 0 : ", i+1, j+1);
                              scanf("%d", &m.matrice[i][j]);
                              m.matrice[j][i] = m.matrice[i][j];
                    }
          }
return m;
}

/**********************************************************************/

void afficheArcs(MatriceDAdjacence m){
          /* Cette fonction affiche les arcs
            d'un graphe  orienté */
          int i,j;
          printf("\nVoici la Liste des arcs :\n");
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              if( m.matrice[i][j])
                                        printf("%d --> %d,\t",  i+1, j+1);
                    }
                    printf("\n");
          }
return;
}


/**********************************************************************/

void afficheArete(MatriceDAdjacence m){
          /* Cette fonction affiche les aretes
            d'un graphe non orienté */
          int i,j;
          printf("\nVoici la Liste des aretes :\n");
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j <= i; j++){
                              if( m.matrice[i][j])
                                        printf("%d ---- %d,\t ",  i+1, j+1);
                    }
                    printf("\n");
          }
return;
}

/**********************************************************************/
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

/**********************************************************************/
/*
* La partie de teste: pour tester ce code séparément

int main(int argc, char const *argv[])
{
     MatriceDAdjacence mgo = creerMatAdjGO();
     MatriceDAdjacence mgno = creerMatAdjGNO();
     afficheMatriceAdjacence(mgo);
     afficheArcs(mgo);
     afficheMatriceAdjacence(mgno);
     afficheArete(mgno);

     return 0;
}
*/
