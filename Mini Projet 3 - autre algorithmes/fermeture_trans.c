
#include "fermeture_trans.h"

void Warshall(MatriceDAdjacence graphe){

    int ordre = graphe.n;

    int **fermetureTransitive = (int**)malloc(ordre*sizeof(int*));
    int i;
    for(i = 0; i < ordre; i++){
        fermetureTransitive[i] = (int*)malloc(ordre*sizeof(int));
    }

    //copier la matrice d'adjacence
    int j;
    for(i = 0; i < ordre; i++)
       for(j = 0; j < ordre; j++)
          fermetureTransitive[i][j] = graphe.matrice[i][j];

    // Warshall
    int k;
    for(i = 0; i < ordre; i++){
        for(j = 0; j < ordre; j++)
                   if(fermetureTransitive[j][i] == 1){
                        for(k = 0; k < ordre; k++)
                                if(fermetureTransitive[i][k] == 1){
                                    fermetureTransitive[j][k] = 1;
                                }

           }
    }

    // Affichage
    printf("\nVoici la matrice de la fermeture transitive!\n");
    for(i = 0; i < ordre; i++){
            for(j = 0; j < ordre; j++)
                    printf("%d ", fermetureTransitive[i][j]);
            printf("\n");
    }

}
