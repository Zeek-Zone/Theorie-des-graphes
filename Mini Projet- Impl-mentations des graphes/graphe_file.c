#include <stdio.h>
#include <stdlib.h>
#include "graphe_file.h"

Arc* creerArc(int initial, int terminal){
  Arc *arc = (Arc*)malloc(sizeof(Arc));
  arc->extInitial = initial;
  arc->extTerminal = terminal;
return arc;
}

Sommet* creerSommet(int extInitial, int extTerminal){
          /* Cette fonction cree un sommet de file */
          Sommet *som = (Sommet*)malloc(sizeof(Sommet));
          som->valeur = extTerminal;
          som->arc = creerArc(extInitial, extTerminal);
          som->suivant = NULL;
return som;
}
/******************************************************************************************/
FileSuccesseur *initialiserFile()
{
          /* Cette fonction cree un file initialement vide */
              FileSuccesseur *file = (FileSuccesseur*)malloc(sizeof(FileSuccesseur));
              file->taille = 0;
              file->tete = NULL;
return file;
}
/******************************************************************************************/
FileSuccesseur* creerFile(int extInitial, int numSucc){
          /* Cette fonction saisie le file */
          FileSuccesseur* file = initialiserFile();
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
/******************************************************************************************/
void enfiler(FileSuccesseur *file, int extInitial,int extTerminal)
{
          /* Cette fonction enfile un Ã©lÃ©ment dans le file */
              if (file == NULL)
              {
                    printf("Erreur Allocation - enfiler\n");
                    exit(EXIT_FAILURE);
              }

              Sommet *nouveau = creerSommet(extInitial, extTerminal);

              if (file->tete != NULL) /* La file n'est pas vide */
              {
                  /* On se positionne Ã  la fin de la file */
                  Sommet *elementActuel = file->tete;
                  while (elementActuel->suivant != NULL)
                  {
                      elementActuel = elementActuel->suivant;
                  }
                  elementActuel->suivant = nouveau;
              }
              else /* La file est vide, notre Ã©lÃ©ment est le premier */
              {
                  file->tete = nouveau;
              }
}

/******************************************************************************************/
int defiler(FileSuccesseur *file)
{
          /* Cette fonction defile un Ã©lÃ©ment du file */
              if (file == NULL)
              {
                   printf("file vide! - defiler\n");
                   exit(EXIT_FAILURE);
              }

              int sommetDefile = 0;

              /* On vÃ©rifie s'il y a quelque chose Ã  dÃ©filer */
              if (file->tete != NULL)
              {
                  Sommet *elementDefile = file->tete;

                  sommetDefile = elementDefile->valeur;
                  file->tete = elementDefile->suivant;
                  free(elementDefile);
              }
return sommetDefile;
}
/******************************************************************************************/
void afficherFile(FileSuccesseur *file)
{
          /* Cette fonction permet d'afficher le file */
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

