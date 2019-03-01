#include <stdio.h>
#include <stdlib.h>
#include "lesExercices.h"

void menu1();

int main()
{
    printf("Hello world!\n");
    menu1();
    int choix;
    scanf("%d", &choix);
    switch(choix){
    case 1:
          exo1();
          break;
    case 2:
          //exo2();
          break;
    default:
           printf("choix non valide!\n");
  }
    return 0;
}

void menu1(){
  printf("**********************************\n");
  printf("**********************************\n\n");
  printf("Quelle EXERCICE?\n");
  printf("1. Exercice 1;\n");
  printf("2. Exercice 2;\n");
  printf("3. Exercice 3;\n");
  printf("4. Exercice 4;\n");
  printf("**********************************\n");
  printf("**********************************\n");
  printf("choix : ");
}
