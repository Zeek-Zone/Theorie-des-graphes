#include <stdio.h>
#include <stdlib.h>
#include "graphe_utilities.h"

int main()
{
  //freopen("input.txt", "r", stdin);
  /*
  La fonction freopen permet de tester avec des fichier sans avoir
  besoin a taper les information à chaque fois que l'on veut retester!
  */
  int choix = 0;
  printf("**********************************\n");
  printf("**********************************\n\n");
  printf("Quelle representation aimerez vous faire?\n");
  printf("1. Matrice d\'adjacence;\n");
  printf("2. Matrice d\'incidence;\n");
  printf("3. Listes d\'adjacence;\n");
  printf("4. Liste des successeur: les deux tables PS et LS;\n");
  printf("5. File des successeur: File FS et la table APS.\n\n");
  printf("**********************************\n");
  printf("**********************************\n");
  printf("choix : ");
  scanf("%d", &choix);
  switch(choix){
    case 1:
          maMatriceDadjacence();
          break;
    case 2:
          maMatriceDincidence();
          break;
    case 3:
          mesListesDadjacence();
          break;
    case 4:
          mesTablesPSetLS();
          break;
    case 5:
          monFileFSetTabAPS();
          break;
    default:
           printf("choix non valide!\n");
  }

  return 0;
}
