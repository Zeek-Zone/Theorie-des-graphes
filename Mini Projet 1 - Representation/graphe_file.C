#include <stdio.h>
#include <stdlib.h>
#include "graphe_file.h"


/********************************* initialiserFile() *********************************************************/

Arc* creerArc(int initial, int terminal){
  Arc *arc = (Arc*)malloc(sizeof(Arc));
  arc->extInitial = initial;
  arc->extTerminal = terminal;
return arc;
}

/********************************* initialiserFile() *********************************************************/

Sommet* creerSommet(int extInitial, int extTerminal){
          /* Cette fonction cree un sommet element de la file */
          Sommet *som = (Sommet*)malloc(sizeof(Sommet));
          som->valeur = extTerminal;
          som->arc = creerArc(extInitial, extTerminal);
          som->suivant = NULL;
return som;
}
/********************************* creerFile() *********************************************************/
FileSuccesseur* creerFile()
{
          /* Cette fonction cree une file initialement vide */
              FileSuccesseur *file = (FileSuccesseur*)malloc(sizeof(FileSuccesseur));
              file->taille = 0;
              file->tete = NULL;
return file;
}
/*********************************** creerFile(int extInitial, int numSucc) *******************************************************/

FileSuccesseur* saisirFile(int extInitial, int numSucc){
          /* Cette fonction saisie la file */

          FileSuccesseur* file = creerFile();
          if (file == NULL)
              {
                  printf("Erreur Allocation - creerFile\n");
                  exit(EXIT_FAILURE);
              }

          int i, extTerminal;
          printf("\n-------> !!!! Saisie des successeur de %d en ordre croissant !!!! <------- \n", extInitial);
          for(  i = 0; i < numSucc; i++){
                    printf("\n---> Saisir successeur : ");
                    scanf("%d", &extTerminal);
                    enfiler(file, extInitial, extTerminal);
          }
return file;
}
/******************************** enfiler(FileSuccesseur *file, int extInitial,int extTerminal) **********************************************************/
void enfiler(FileSuccesseur *file, int extInitial,int extTerminal)
{
          /* Cette fonction enfile un élément dans la file */
              if (file == NULL)
              {
                    printf("Erreur Allocation - enfiler\n");
                    exit(EXIT_FAILURE);
              }

              Sommet *nouveau = creerSommet(extInitial, extTerminal);

              if (file->tete != NULL) /* La file n'est pas vide */
              {
                  /* On se positionne à la fin de la file */
                  Sommet *elementActuel = file->tete;
                  while (elementActuel->suivant != NULL)
                  {
                      elementActuel = elementActuel->suivant;
                  }
                  elementActuel->suivant = nouveau;
              }
              else /* La file est vide, notre élément est le premier */
              {
                  file->tete = nouveau;
              }
}

/************************************ defiler(FileSuccesseur *file) ******************************************************/
int defiler(FileSuccesseur *file)
{
          /* Cette fonction defile un élément de la file */
              if (file == NULL)
              {
                   printf("file vide! - defiler\n");
                   exit(EXIT_FAILURE);
              }

              int sommetDefile = 0;

              /* On vérifie s'il y a quelque chose à défiler */
              if (file->tete != NULL)
              {
                  Sommet *elementDefile = file->tete;

                  sommetDefile = elementDefile->valeur;
                  file->tete = elementDefile->suivant;
                  free(elementDefile);
              }
return sommetDefile;
}
/******************************* afficherFile(FileSuccesseur *file) ***********************************************************/
void afficherFile(FileSuccesseur *file)
{
          /* Cette fonction permet d'afficher la file */
              if (file == NULL)
              {
                  printf("Erreur -afficherFile");
                  exit(EXIT_FAILURE);
              }

              Sommet *courant = file->tete;

              while (courant != NULL)
              {
                  printf("%d, ", courant->valeur);
                  courant = courant->suivant;
              }
              printf("\n");
}

/*************************************/
/* Testes :
int main(int argc, char const *argv[])
{
  FileSuccesseur *file = creerFile(1, 4);
  afficherFile(file);
  printf("valeur defile %d\n", defiler(file));
  afficherFile(file);
  return 0;
}
*/


