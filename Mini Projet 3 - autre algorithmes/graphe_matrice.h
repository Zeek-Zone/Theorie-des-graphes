#ifndef H_GRAPHEM
#define H_GRAPHEM

/**
*   fichier header contenant les declarations de toutes mes structures
*   et fonctions des graphes repr�sent� sous forme de matrice.
*   @author Hassan Zekkouri
*   le 15/11/2018
*/

#define MAX 50 // nombre max de sommets : � adapter selon le besoin

/****************************************************************/
// D�finition des structures matrices:
struct matAdj{
          int  n; // nombre de sommets
          int matrice[MAX][MAX];
};
typedef  struct matAdj MatriceDAdjacence;

MatriceDAdjacence creerMatAdjGO();
MatriceDAdjacence creerMatAdjGNO();
void afficheArcs(MatriceDAdjacence m);
void afficheAretes(MatriceDAdjacence m);
void afficheMatriceAdjacence(MatriceDAdjacence m);

#endif // H_GRAPHEM

