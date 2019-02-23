#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"


MatriceDAdjacence creerMatAdjGO(){
          /* Cette fonction saisie et initialise la matrice d'adjacence
            d'un graphe orienté */
          MatriceDAdjacence m;
          printf("Saisir le nombre de sommets de votre graphe: |X| = ");
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
            d'un graphe non orienté*/
          MatriceDAdjacence m;
          printf("Saisir le nombre de sommets : |X| = ");
          scanf("%d", &m.n);
          int i,j;
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j <=i ; j++){
                              printf("Si l\'arete  %d ---- %d  existe taper 1 sinon taper 0 : ", i+1, j+1);
                              scanf("%d", &m.matrice[i][j]);
                              m.matrice[j][i] = m.matrice[i][j];
                              // Ici on stocke une partie triangulaire
                              // et on en deduit l'autre
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

MatriceDIncidence creerMatIncidGO(){
          /* Cette fonction saisie et initialise la matrice d'incidence
            d'un graphe orienté */

          MatriceDIncidence m;
          printf("Saisir le nombre de sommets de votre graphe: |X|\n");
          scanf("%d", &m.numSommet);
          printf("Saisir le nombre d\'arc: |U|\n");
          scanf("%d", &m.numLiaison);

          int i,j;
          printf("Regle:\n a. taper 1 si le sommet est initial\
               \n b. taper -1 s\'elle terminal\
               \n c. taper 0 sinon.\n\n");

          for(i = 0; i < m.numSommet ; i++){
                    printf(">>>> Sommet numero %d:\n", i+1);
                    for(j = 0; j < m.numLiaison; j++){
                              printf(">>>>>> Liaison numero %d:\n",j+1);
                              scanf("%d", &m.matrice[i][j]);
                    }
          }
return m;
}
/***********************************************************************/
MatriceDIncidence creerMatIncidGNO(){
          /* Cette fonction saisie et initialise la matrice d'incidence
            d'un graphe non orienté */
          MatriceDIncidence m;
          printf("Saisir le nombre de sommets de votre graphe: |X|\n");
          scanf("%d", &m.numSommet);
          printf("Saisir le nombre d\'arete: |E|\n");
          scanf("%d", &m.numLiaison);

          int i,j;
          printf("Regle:\n a. taper 1 si le sommet participe a la liaison\
               \n c. taper 0 sinon.\n\n");

          for(i = 0; i < m.numSommet ; i++){
                    printf(">>>> Sommet numero %d:\n", i+1);
                    for(j = 0; j < m.numLiaison; j++){
                              printf(">>>> Liaison numero %d:\n", j+1);
                              scanf("%d", &m.matrice[i][j]);
                    }
          }
return m;
}

void afficheAreteMatriceIncidence(MatriceDIncidence m){
          /* Cette fonction affiche les aretes
            d'un graphe non orienté */
          int i,j, s1 = 0, s2 = 0;
          printf("\nVoici la Liste des aretes :\n");

          for(j = 0; j < m.numLiaison ; j++){
                    s1 = 0; s2 = 0;
                    for(i = 0; i <= m.numSommet; i++){
                              if( m.matrice[i][j] == 1){
                                  if(s1 == 0) s1 = i+1;
                                  else s2 = i+1;
                              }

                    }
                    if(s1 && s2)
                         printf("%d ---- %d \n",  s1, s2);
          }
return;
}

void afficheMatriceIncidence(MatriceDIncidence m){
          /* Cette fonction affiche la matrice d'adjacence
            d'un graphe */
          int i, j;
          printf("\nVoici la matrice d'incidence de votre graphe:\n");
          for(i = 0; i < m.numSommet ; i++){
                    for(j = 0; j < m.numLiaison; j++){
                                        printf("%d\t",  m.matrice[i][j]);
                    }
                    printf("\n");
          }
return;
}
void afficheArcMatriceIncidence(MatriceDIncidence m){
          /* Cette fonction affiche les arcs
            d'un graphe orienté */
          int i,j, s1 = 0, s2 = 0;
          printf("\nVoici la Liste des arcs :\n");
          for(j = 0; j < m.numLiaison ; j++){
                    s1 = 0;  s2 = 0;
                    for(i = 0; i < m.numSommet; i++){

                              if( m.matrice[i][j]  > 0){
                                  s1 = i+1;
                              }
                              else if( m.matrice[i][j] < 0){
                                  s2 = i+1;
                              }

                    }

                         printf("%d ----> %d \n",  s1, s2);

          }
return;
}
