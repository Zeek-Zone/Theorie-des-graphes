#include<stdlib.h>
#include<stdio.h>
#include "coloriage.h"
#include "graphe_matrice.h"

#define _MAX = 10 // nombre max de sommet

// si le nombre de couleurs peut d�passer 9, il faut ajouter le reste
const int couleurs[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // les couleurs
int compteur = 0; // combien de couleurs utils�s
int problem = 0;

int tousColore = 0; // combien de sommet color�

//welsh powell
void Powell_Welsh(MatriceDAdjacence graphe, int *degre, int *colore) {

    if(tousColore == graphe.n){
        printf("\n###### FIN de COLORIAGE ######\n");
        return;
    }

	int x = graphe.n;
	int grand = 0;
	int temp = 0;
	int i, j, w, t, e;

	//Calculer les degr�s des sommet
	if (compteur == 1)
		for ( i = 0; i < x; i++)
			for ( j = 0; j < x; j++)
				if (graphe.matrice[i][j])
					degre[i]++;

	// Chercher le sommet avec le plus grand degr�
	// parmi les sommets non encore coulor�
	for ( w = 0; w < x; w++)
		if (colore[w] == 0)
        {
			if (temp < degre[w])
            {
				temp = degre[w];
				grand = w;
			}
		}

	// Colorer le sommet "grand"
    colore[grand] = couleurs[compteur]; // color�
	tousColore++;
	printf("\nSommet S(%d) --> couleur %d\n", grand+1, colore[grand]);

	// Coloriage de la m�me couleur des sommets non adjacents � "grand"
	// c'est � dire matrice[grand][e] == 0
	// et non adjacents entre eux

	for ( e = 0; e < x; e++){
        // si e n'est pas adjacent � "grand" et non color�
		if (!graphe.matrice[grand][e] && grand != e && !colore[e])
        {
            int temp_degre = degre[e];
            int sommetSuivant = e;
			for ( t = 0; t < x; t++)
            {
                // tester s'il n'existent pas de sommets t
                // adjacent au sommet e avec la m�me couleur que "grand"
				if(graphe.matrice[e][t] && colore[t] == colore[grand])
				     problem = 1; // oui
                else if(degre[t] > temp_degre){
                    // Garder le sommet valable ayant le plus grand degre
                    sommetSuivant = t;
                    temp_degre = degre[t];
                }

                // Si c'est la fin de boucle t == x-1
                //     si problrm == 0 alors colorer le sommetSuivant et remettre problem � 0
                //     sinon remettre problem � 0
                if (t == x - 1 && !problem)
                {
                    colore[sommetSuivant] = couleurs[compteur];// color�
                    tousColore++;
                    printf("Sommet S(%d) --> couleur %d\n", sommetSuivant+1, colore[sommetSuivant]);
                    problem = 0; // non
                }
                else if (t == x - 1) problem = 0;
			}
		}
    }

    // R�cursivit�: Passer au sommet suivant
    // Sommet non color� avec le plus grand degr�
    compteur++;
    Powell_Welsh(graphe, degre, colore);
}

