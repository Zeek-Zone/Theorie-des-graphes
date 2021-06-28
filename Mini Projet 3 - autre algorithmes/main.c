#include <stdio.h>
#include <stdlib.h>
#include "utilitaires.h"
#include "graphe_matrice.h"

void menu1();

int main()
{
    menu1();

    int choix;
    scanf("%d", &choix);

    switch(choix){
    case 1:
          coloriage();
          break;
    case 2:
          fermeture();
          break;
    case 3:
          cfc();
          break;
    case 4:
          arbreMST();
          break;
    default:
           printf("choix non valide!\n");
  }
	return 0;
}

void menu1(){
  printf("**********************************\n");
  printf("**********************************\n\n");
  printf("Quelle Operations?\n");
  printf("1. Coloriage d'un graphe (Powell-Welsh);\n");
  printf("2. La fermeture transitive;\n");
  printf("3. Composantes fortement connexes (pile);\n");
  printf("4. Arbre couvrant de poids minimal;\n");
  printf("**********************************\n");
  printf("**********************************\n");
  printf("choix : ");
}

