#include<stdio.h>
#include<stdlib.h>
#include "graphe_liste.h"
#include "graphe_file.c"


/**************************************** creerListe() **********************************************************/

/** \brief  Cette fonction cree une liste initialement vide
 *
 * \return  liste: une liste d'adjacence
 *
 */

Liste* creerListe(){
              Liste *liste = (Liste*) malloc(sizeof(Liste));

              if (liste == NULL)
              {
                  printf("Error Allocation - creerListeSommet");
                  exit(EXIT_FAILURE);
              }

              liste->extInitial = 0;
              liste->file = NULL;
              liste->suivant = NULL;
return liste;
}

/**************************************** creerListeDAdjacence() **********************************************************/
/** \brief  Cette fonction cree une liste initialement vide
 *
 * \return  liste: une liste de contrôle des listes d'adjacences
 *
 */
MesListeDAdjacence* creerListeDAdjacence(){
              MesListeDAdjacence *liste = (MesListeDAdjacence*) malloc(sizeof(*liste));

              if (liste == NULL)
              {
                  printf("Error Allocation - creerListeDAdjacence");
                  exit(EXIT_FAILURE);
              }

              liste->taille = 0;
              liste->debut = NULL;
              liste->fin = NULL;
return liste;
}
/******************************* insert(MesListeDAdjacence *liste, int valeur) ************************************************/
/** \brief Cette fonction permet d'ajouter une liste d'adjacence
 *  \param  liste : un pointeur  sur la liste de contrôle
 *  \param  valeur : Le sommet pour laquelle on veut stocker la liste d'adjacence
 *  \return rien
 */

void insert(MesListeDAdjacence *liste, int valeur){
          /* Création en insertion du nouvel élément */

              Liste *nouveau = creerListe();
              Liste *courant, *pred;
              int numSucc;
              nouveau->extInitial = valeur;

              printf("\n---> Saisir le nombre des successeur de %d\n", valeur);
              scanf("%d", &numSucc);
              nouveau->file = saisirFile(valeur, numSucc);

              /* Insertion de l'élément dans la liste  en order croissant*/
              if( liste->taille == 0){ //liste vide
                         nouveau->suivant = liste->debut;
                         liste->debut = nouveau;
              }
              else{ // liste non vide
                       courant = liste->debut;
                       pred = NULL;
                      while(courant !=NULL && courant->extInitial  <  valeur){
                          pred = courant;
                          courant = courant->suivant;
                      }
                          nouveau->suivant = courant;
                          pred->suivant = nouveau;
              }
              liste->taille++;
}
/************************************** afficherListeAdj(MesListeDAdjacence *liste) *****************************************/
/** \brief Cette fonction permet d'afficher toutes
 * les listes d'adjacences
 * \param liste : un pointeur  sur liste de contrôle
 * \return rien
 */

void afficherListeAdj(MesListeDAdjacence *liste){
              if (liste == NULL)
              {
                  printf("Error Liste vide - afficherListe\n");
                  exit(EXIT_FAILURE);
              }

              Liste *actuel = liste->debut;
              printf("\n--------------- Voici vos listes d\'adjacences  ----------------------\n");
              while (actuel != NULL)
              {
                  printf("%d :  ", actuel->extInitial);
                  afficherFile(actuel->file);
                  actuel = actuel->suivant;
              }
              printf("\n");
}
/****************************** supprimeListeAdj(MesListeDAdjacence *liste) *************************************************/
/** \brief Cette fonction permet de supprimer tout
 *  les listes d'adjacences
 * \param  liste : un pointeur  sur liste de contrôle
 * \return  rien
 */

void supprimeListeAdj(MesListeDAdjacence *liste){
          if (liste == NULL)
              {
                  printf("Erreur -supprime");
                  exit(EXIT_FAILURE);
              }

              if (liste->debut != NULL)
              {
                  Liste* aSupprimer = liste->debut;
                  liste->debut = liste->debut->suivant;
                  free(aSupprimer);
                  liste->taille--;
              }
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
  return 0;
}
*/

