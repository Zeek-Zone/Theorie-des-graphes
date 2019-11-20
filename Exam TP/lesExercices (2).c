#include<stdio.h>
#include "lesExercices.h"
#include "graphe_matrice.h"
#include "utilitaires.h"
#include "djikstra.h"

void menu(){
  printf("**********************************\n");
  printf("**********************************\n\n");
  printf("Quelle operation aimerez vous faire?\n");
  printf("1. Parcours en largeur (BFS);\n");
  printf("2. Parcours en profondeur (DFS);\n");
  printf("**********************************\n");
  printf("**********************************\n");
  printf("choix : ");
}


void exo1(){
    menu();
    int choix;
    scanf("%d", &choix);
    switch(choix){
    case 1:
          mesBFS();
          break;
    case 2:
          mesDFS();
          break;
    default:
           printf("choix non valide!\n");
  }
}


void exo2(){
	int V = 12; // Number of vertices in graph
	int E = 23; // Number of edges in graph
	Graphe* graphe = creerGraphe(V, E);
	saisirArcs(graphe);

	Kruskal(graphe);
}


void exo3(){

    freopen("exo3.txt", "r", stdin);
    MatriceDAdjacence graphe1 = creerMatAdjGO();
    Dijkstra(graphe1, 0); // sommet A comme racine
    fclose(stdin);
}

void exo4(){
    freopen("exo4.txt", "r", stdin); // ouvre le fichier contenant la matrice d'adjacence
    MatriceDAdjacence graphe = creerMatAdjGNO();
    int *degre = (int*)calloc(10, sizeof(int)); // tous à zero
    int *colore = (int*)calloc(10, sizeof(int));  // tous à zero: non coloré
    printf("\n ########## Debut de Coloriage ########\n");
    Powell_Welsh(graphe, degre, colore);
}
