#include <stdio.h>
#include <stdlib.h>
#include "lesExercices.h"

/** \brief  Réponses pratiques de l'examen de théorie des graphe
 *
 * @responsable Prof. M. D. AOURAGH
 * @date 02/03/2019
 * @author Hassan Zekkouri
 *
 */

void menu1();

int main()
{
    printf("Bonjour!\n");
    menu1();
    int choix;
    scanf("%d", &choix);
    switch(choix){
    case 1:
          exo1();
          break;
    case 2:
          exo2();
          break;
    case 3:
          exo3();
          break;
    case 4:
          exo4();
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
