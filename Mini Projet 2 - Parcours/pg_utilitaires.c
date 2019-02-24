#include<stdio.h>
#include<stdlib.h>
#include "graphe_matrice.h"
#include "graphe_parcours.h"
#include "pg_utilitaires.h"

#define DEBUT printf("\n################### DEBUT ###################\n")
void menu1(){
    printf("\n>>>>>>> Saisir un type de graphe\n");
    printf("----> 1. Graphe Oriente\n");
    printf("----> 2. Graphe Non Oriente\n");
}


void mesBFS(){
    /* Pour tester les fonctionalité liées aux parcours en largeur d'un graphe */
  int choix;
  debut:
      menu1();
      scanf("%d", &choix);

      int i;
      switch(choix){
        case 1:

              printf("\n___________ Graphe Oriente ____________\n");
              freopen("gOrienteMatAdj.txt", "r", stdin); // fichier test
              MatriceDAdjacence mgo = creerMatAdjGO();
              DEBUT;
              printf("\n Test de parcoursLargeur(mgo, i);\n", i);
              for(i = 1; i <= mgo.n ; i++){
                printf("\n Parcours Pour La racine : %d", i);
                parcoursLargeur(mgo, i);
              }
        break;

        case 2:

              printf("\n___________ Graphe Non Oriente ____________\n");
              freopen("gNonOrienteMatAdj.txt", "r", stdin);
              MatriceDAdjacence mgno = creerMatAdjGNO();
              DEBUT;
              printf("\n Test de parcoursLargeur(mgno, i);\n", i);
              for(i = 1; i <= mgno.n ; i++){
                printf("\n Parcours Pour La racine : %d", i);
                parcoursLargeur(mgno, i);
              }
        break;

        default:
               goto debut;
      }

}

void mesDFS(){
    /* Pour tester les fonctionalité liées aux parcours en profondeur d'un graphe */
  int choix;
  debut:
      menu1();
      scanf("%d", &choix);
      int i;
      switch(choix){
        case 1:

              printf("\n___________ Graphe Oriente ____________\n");
              freopen("gOrienteMatAdj.txt", "r", stdin);
              MatriceDAdjacence mgo = creerMatAdjGO();
              DEBUT;
              printf("\n Test de parcoursProfondeur(mgo, i);\n");
              for(i = 1; i <= mgo.n ; i++){
                printf("\n Parcours Pour La racine : %d", i);
                parcoursProfondeur(mgo, i);
              }

              printf("\n Test de DFS(mgno);\n");
              DFS(mgo);
        break;

        case 2:

              printf("\n___________ Graphe Non Oriente ____________\n");
              freopen("gNonOrienteMatAdj.txt", "r", stdin);
              MatriceDAdjacence mgno = creerMatAdjGNO();
              DEBUT;
              printf("\n Test de parcoursProfondeur(mgno, i);\n");
              for(i = 1; i <= mgno.n ; i++){
                printf("\n Parcours Pour La racine : %d", i);
                parcoursProfondeur(mgno, i);
              }

              printf("\n Test de DFS(mgno);\n");
              DFS(mgno);
        break;

        default:
               goto debut;
      }
}

void monGrapheBipartiBFS(){
    /* Pour tester les fonctionalité liées aux parcours en largeur d'un graphe */
  int choix;
  debut:
      menu1();
      scanf("%d", &choix);
      int resultat;
      switch(choix){
        case 1:

              printf("\n___________ Graphe Oriente ____________\n");
              freopen("gOrienteMatAdj.txt", "r", stdin); // fichier test
              MatriceDAdjacence mgo = creerMatAdjGO();
              DEBUT;
              resultat = grapheBipartiBFS(mgo, 5);
              printf("\n___________ Graphe Bibarti\? ____________\n");
              if(resultat == 1) printf("Le graphe est biparti!\n");
              else printf("Le graphe est n\'est pas biparti!\n");
        break;

        case 2:

              printf("\n___________ Graphe Non Oriente ____________\n");
              freopen("gNonOrienteMatAdj.txt", "r", stdin);
              MatriceDAdjacence mgno = creerMatAdjGNO();
              DEBUT;
              printf("\n___________ Graphe Bibarti\? ____________\n");
              resultat = grapheBipartiBFS(mgno, 5);
              if(resultat == 1) printf("Le graphe est biparti!\n");
              else printf("Le graphe est n\'est pas biparti!\n");
        break;

        default:
               goto debut;
      }

}

void monGrapheBipartiDFS(){
}

void couches(){
    int choix;
  debut:
      menu1();
      scanf("%d", &choix);
      int resultat;
      switch(choix){
        case 1:

              printf("\n___________ Graphe Oriente ____________\n");
              freopen("gOrienteMatAdj.txt", "r", stdin); // fichier test
              MatriceDAdjacence mgo = creerMatAdjGO();
              DEBUT;
              printf("\n___________ Les couches du graphe ____________\n");
              afficherCouches(mgo);
        break;

        case 2:

              printf("\n___________ Graphe Non Oriente ____________\n");
              freopen("gNonOrienteMatAdj.txt", "r", stdin);
              MatriceDAdjacence mgno = creerMatAdjGNO();
              DEBUT;
              printf("\n___________ Les couches du graphe ____________\n");
              afficherCouches(mgno);
        break;

        default:
               goto debut;
      }

}
