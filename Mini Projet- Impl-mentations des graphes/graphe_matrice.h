#ifndef H_GRAPHEM
#define H_GRAPHEM
/**
*   fichier header contenant les declarations de toutes mes structures
*   et fonctions des graphes représenté sous forme de matrice.
*   @author Hassan Zekkouri
*   le 15/11/2018
*/

#define MAX 50 // nombre max de sommets : à adapter selon le besoin

/****************************************************************/
// Définition des structures matrices:
struct matAdj{
          int  n; // nombre de sommets
          int matrice[MAX][MAX];
};
typedef  struct matAdj MatriceDAdjacence;

struct matIncid{
          int numSommet; // nombre ligne
          int numLiaison; // nombre colonne
          int matrice[MAX][MAX];
};
typedef  struct matIncid MatriceDIncidence;


MatriceDAdjacence creerMatAdjGO();
MatriceDAdjacence creerMatAdjGNO();
void afficheArcs(MatriceDAdjacence m);
void afficheAretes(MatriceDAdjacence m);
void afficheMatriceAdjacence(MatriceDAdjacence m);

MatriceDIncidence creerMatIncidGNO();
void afficheMatriceIncidence(MatriceDIncidence  m);
void afficheAreteMatriceIncidence(MatriceDIncidence m);
MatriceDIncidence creerMatIncidGO();
void afficheMatriceIncidence(MatriceDIncidence m);
void afficheArcMatriceIncidence(MatriceDIncidence m);


#endif // H_GRAPHEM

