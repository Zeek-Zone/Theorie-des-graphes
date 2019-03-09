#include <stdio.h>
#include <stdlib.h>
#include "graphe_utilities.h"

void menu();

int main()
{
  menu();
  int choix = 0;
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
    case 6:
          grapheEnLiaison();
    default:
           printf("choix non valide!\n");
  }

  return 0;
}

void menu(){
      printf("**********************************\n");
      printf("**********************************\n\n");
      printf("Quelle representation aimerez vous faire?\n");
      printf("1. Matrice d\'adjacence;\n");
      printf("2. Matrice d\'incidence;\n");
      printf("3. Listes d\'adjacence;\n");
      printf("4. Liste des successeur: les deux tables PS et LS;\n");
      printf("5. File des successeur: File FS et la table APS;\n\n");
      printf("6. Représentation avec les liaisons (arcs/aretes).\n\n");
      printf("**********************************\n");
      printf("**********************************\n");
      printf("choix : ");
}
