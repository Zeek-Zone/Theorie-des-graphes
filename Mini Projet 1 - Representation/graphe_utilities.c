#include<stdlib.h>
#include<stdio.h>
#include "graphe_matrice.h"
#include "graphe_utilities.h"
#include "graphe_liste.h"
#include "graphe_parcours.h"


/******************************** getMatriceDAdjacence( MesListeDAdjacence *liste) ***************************************/

MatriceDAdjacence getMatriceDAdjacence( MesListeDAdjacence *liste){
          /*
             Cette fonction parcours les listes d'adjacences et
             retourne la matrice d'adjacence associ�e
          */

          MatriceDAdjacence m;
          m.n = liste->taille;
          int i,j;

          // met tous � zero
          for(i = 0; i < m.n ; i++){
                    for(j = 0; j < m.n; j++){
                              m.matrice[i][j] = 0;
                    }
          }

          // Marquer  les arcs entre sommets avec 1 sur la matrice
              Liste *listeActuel = liste->debut;
              while (listeActuel != NULL)
              {
                            if (listeActuel->file != NULL) // les successeurs existent
                             {
                                     Sommet* sommetCourant = listeActuel->file->tete;
                                     while (sommetCourant != NULL)
                                     {
                                                  int i, j;
                                                  i = listeActuel->extInitial - 1;
                                                  j = sommetCourant->valeur - 1; //extremite terminale

                                                  m.matrice[i][j] = 1;
                                                  sommetCourant = sommetCourant->suivant;
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

// Cette partie contient les fonctions de choix de la fonction main.c

/*********************** maMatriceDadjacence() *******************************/

void maMatriceDadjacence(){
    /* Pour tester les fonctionalit� li�es aux matrices d'adjacences */
  int choix;

  debut: // etiquete goto en default

  printf("\n>>>>>>> Saisir un type de graphe\n");
  printf("----> 1. Graphe Oriente\n");
  printf("----> 2. Graphe Non Oriente\n");
  scanf("%d", &choix);

  switch(choix){
    case 1:

          printf("\n___________ Graphe Oriente ____________\n");
          freopen("gOrienteMatAdj.txt", "r", stdin); // fichier de test

          MatriceDAdjacence mgo = creerMatAdjGO();
          afficheMatriceAdjacence(mgo);
          afficheArcs(mgo);

    break;
    case 2:

          printf("\n___________ Graphe Non Oriente ____________\n");
          freopen("gNonOrienteMatAdj.txt", "r", stdin);

          MatriceDAdjacence mgno = creerMatAdjGNO();
          afficheMatriceAdjacence(mgno);
          afficheArete(mgno);
    break;
    default:
           goto debut; // refaire le choix!
  }

}

/*********************** maMatriceDincidence() *******************************/

void maMatriceDincidence(){
    /* Pour tester les fonctionalit� li�es aux matrices d'incidences */
  int choix;

  debut:

  printf("\n>>>>>>> Saisir un type de graphe\n");
  printf("----> 1. Graphe Oriente\n");
  printf("----> 2. Graphe Non Oriente\n");
  scanf("%d", &choix);
  switch(choix){
    case 1:

          printf("\n___________ Graphe Oriente ____________\n");
          freopen("gOrienteMatIncid.txt", "r", stdin);

          MatriceDIncidence mgo = creerMatIncidGO();
          afficheMatriceIncidence(mgo);
          afficheArcMatriceIncidence(mgo);

    break;
    case 2:

          printf("\n___________ Graphe Non Oriente ____________\n");
          freopen("gNonOrienteMatIncid.txt", "r", stdin);

          MatriceDIncidence mgno = creerMatIncidGNO();
          afficheMatriceIncidence(mgno);
          afficheAreteMatriceIncidence(mgno);

    break;
    default:
           goto debut;
  }
}
/************************* mesListesDadjacence() *****************************/

void mesListesDadjacence(){
    /* Pour tester les fonctionalit� li�es aux listes d'adjacences */
  MesListeDAdjacence *li = creerListeDAdjacence();

  printf("##### Debut #######\n");
  freopen("grapheListes.txt", "r", stdin);

  int i, n;
  printf("**************** Saisir le nombtre de sommets ****************\n");
  printf("\nNombre Sommet : ");
  scanf("%d",&n);

  printf("\n**************** Saisie des sommets ****************\n");
  for(i = 0; i < n ; i++){
        int val;
        printf("\nSaisir Sommet: ");
        scanf("%d", &val);
        insert(li, val);
        printf("\n***********************************************************\n");
  }

  afficherListeAdj(li);
  MatriceDAdjacence m = getMatriceDAdjacence(li);
  afficheMatriceAdjacence(m);
}


/*********************** mesTablesPSetLS() *******************************/

void afficherTableau(int tab[], int n){
    /* Affichage d'un tableau tab de taille n */
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d\t", tab[i]);
	}
	printf("\n");
}

void mesTablesPSetLS(){
        /* Cette fonction represente le graphe avec les deux tableaux PS et LS */

      int n, m, i;
      freopen("gPSetLS.txt", "r", stdin);
      printf("Saisire |X|= nombre de sommets:\n");
      scanf("%d", &n);
      printf("Saisire |U|= nombre de d'arc:\n");
      scanf("%d", &m);
      int *PS = (int*)malloc((n+1)*sizeof(int)); // Premier Successeur
      int *LS = (int*)malloc(m*sizeof(int)); // Listes des Successeurs

      printf("Saisir les successeurs de chaque sommet en ordre croissant:\n\
      	Commencer par cels de premier sommet puis du deuxieme ...\n LS: \n");

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
      	/* ici si le sommet i n'a pas de successeurs alors PS[i+1] = PS[i] cette propri�t� est automatiquement
      	g�rer car l'ajout de zero ne change pas la valeur ;  PS[i+1] = PS[i] + 0
      	*/
      }
      PS[n] = m+1;

      printf("\nPS: "); afficherTableau(PS, n+1);
      printf("\nLS: "); afficherTableau(LS, m);

}

/************************ monFileFSetTabAPS() ******************************/


void monFileFSetTabAPS(){
    /* Cette fonction represente le graphe avec les deux tableaux FS et APS */
      int n, m, i;
      freopen("gAPSetFS.txt", "r", stdin);
      printf("Saisire |X|= nombre de sommets:\n");
      scanf("%d", &n);
      printf("Saisire |U|= nombre de d'arc:\n");
      scanf("%d", &m);
      int *APS = (int*)malloc((n+1)*sizeof(int)); // Adresse de Premier Successeur
      int *FS = (int*)malloc(m*sizeof(int)); // File des successeurs

      printf("\nSaisir les successeurs de chaque sommet en oredre croissant:\n\
      	Commencer par cels de premier sommet puis du deuxieme ...\n FS:\n");
      for ( i = 0; i < m; ++i)
      {
      	scanf("%d", &FS[i]);
      }

      printf("\nAPS:\n");
      APS[0] = 1;
      for ( i = 1; i < n; ++i)
      {
      	int numSuccess;
      	printf("Saisir le nombre des successeurs du sommet %d :\n", i);
      	scanf("%d", &numSuccess);
      	APS[i] = APS[i-1] + numSuccess;
      }

      APS[n] = m+1;

      printf("\nAPS: "); afficherTableau(APS, n+1);
      printf("\nFS: "); afficherTableau(FS, m);
}

