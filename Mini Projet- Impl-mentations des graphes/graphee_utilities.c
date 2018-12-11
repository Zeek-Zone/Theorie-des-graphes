#include<stdlib.h>
#include<stdio.h>
#include "graphe_matrice.h"
#include "graphe_utilities.h"

MatriceDAdjacence getMatriceDAdjacence( MesListeDAdjacence *liste){
          /*
          Cette fonction parcours les listes d'adjacences et
          retourne la matrice d'adjacence associée
          */
          MatriceDAdjacence m;
          m.n = liste->taille;
          int i,j;
          // met tous à zero
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              m.matrice[i][j] = 0;
                    }
          }
          // Marquer  les arcs entre sommet avec 1
              Liste *listeActuel = liste->debut;
              while (listeActuel != NULL)
              {
                            if (listeActuel->file != NULL)
                             {
                                      Sommet* courant = listeActuel->file->tete;
                                     while (courant != NULL)
                                     {
                                                  int i, j;
                                                  i = listeActuel->extInitial - 1;
                                                  j = courant->valeur - 1;
                                                  m.matrice[i][j] = 1;
                                                  courant = courant->suivant;
                                     }
                             }
                  listeActuel = listeActuel->suivant;
              }

return m;
}

/**********************************/
/* Teste:
*  

int main(int argc, char const *argv[])
{
  MesListeDAdjacence *li = creerListeDAdjacence();
  int i, val;
  for (i = 0; i < 4; ++i)
  {
    printf("\ndonner sommet\n");
    scanf("%d", &val);
    insert(li, val);
  }
  afficherListeAdj(li);
  MatriceDAdjacence m = getMatriceDAdjacence(li);
  afficheMatriceAdjacence(m);
  return 0;
}

*/
/******************************************************/
void maMatriceDadjacence(){
  int choix;
  debut:
  printf("\n>>>>>>> Saisir un type de graphe\n");
  scanf("%d", &choix);
  printf("----> 1. Graphe Oriente\n");
  printf("----> 2. Graphe Non Oriente\n");
  switch(choix){
    case 1:
          printf("\n___________ Graphe Oriente ____________\n");
          MatriceDAdjacence mgo = creerMatAdjGO();
          afficheMatriceAdjacence(mgo);
          afficheArcs(mgo);
    break;
    case 2: 
          printf("\n___________ Graphe Non Oriente ____________\n");
          MatriceDAdjacence mgno = creerMatAdjGNO();
          afficheMatriceAdjacence(mgno);
          afficheArete(mgno);
    break;
    default:
           goto debut;
  }
    
}
/******************************************************/

void maMatriceDincidence(){
  int choix;
  debut:
  printf("\n>>>>>>> Saisir un type de graphe\n");
  scanf("%d", &choix);
  printf("----> 1. Graphe Oriente\n");
  printf("----> 2. Graphe Non Oriente\n");
  switch(choix){
    case 1:
          printf("\n___________ Graphe Oriente ____________\n");
          MatriceDIncidence mgo = creerMatIncidGO();
          afficheMatriceIncidence(mgo);
          afficheArcs(mgo);
    break;
    case 2: 
          printf("\n___________ Graphe Non Oriente ____________\n");
          MatriceDIncidence mgno = creerMatIncidGNO();
          afficheMatriceIncidence(mgno);
          afficheArete(mgno);
    break;
    default:
           goto debut;
  }
}
/******************************************************/

void mesListesDadjacence(){
  MesListeDAdjacence *li = creerListeDAdjacence();
  int i, val, n;
  printf("Saisir le nombre de sommets: \n");
  scanf("%d", &n);
  for (i = 0; i < n; ++i)
  {
    printf("\nSaisir une Sommet:\n");
    scanf("%d", &val);
    insert(li, val);
  }

  MatriceDAdjacence m = getMatriceDAdjacence(li);
  afficheMatriceAdjacence(m);
}
/******************************************************/

void afficherTableau(int tab[], int n){
	int i;
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t", tab[i]);
	}
}

void mesTablesPSetLS(){	
      int n, m, i;
      printf("Saisire |X|= nombre de sommets:\n");
      scanf("%d", &n);
      printf("Saisire |U|= nombre de d'arc:\n");
      scanf("%d", &m);
      int *PS = (int*)malloc((n+1)*sizeof(int));
      int *LS = (int*)malloc(m*sizeof(int));

      printf("Saisir les successeurs de chaque sommet en oredre croissant:\n\
      	Commencer par cels de premier sommet puis du deuxieme ...\n");
      for ( i = 0; i < m; ++i)
      {
      	scanf("%d", &LS[i]);
      }

      PS[0] = 1;
      for ( i = 1; i < n; ++i)
      {
      	int numSuccess;
      	printf("Saisir le nombre des successeurs du sommet %d :\n", i);
      	scanf("%d", &numSuccess);
      	PS[i] = PS[i-1] + numSuccess;
      }
      PS[n] = m+1;

      printf("PS: "); afficherTableau(PS, n+1);
      printf("\nLS: "); afficherTableau(LS, m);

}
/******************************************************/

void monFileFSetTabAPS(){

}
