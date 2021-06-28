#include<stdlib.h>
#include<stdio.h>
#include "graphe_matrice.h"
#include "bellman.h"
#include "utilitaires.h"
int* triTopo(MatriceDAdjacence graphe, int x0){
    int *sommetTrie = (int*)calloc(graphe.n , sizeof(int));
    // on numerote 1 le sommet x0
    sommetTrie[x0] = 1;
    int k = 2;
    while(k <= graphe.n){
        // cherchons un sommet non num�roter et sans pr�decesseurs
        int s = sommetSansPred(graphe, sommetTrie);
        if(s != -1){
            sommetTrie[s] = k++;
        }else{
            // pas sommet isol� et non num�roter
            // chercher le sommets avec predecesseurs d�j� num�rot�s
            s = sommetSuivantANumerote(graphe, sommetTrie);
            sommetTrie[s] = k++;
        }
    }
return sommetTrie;
}

int sommetSansPred(MatriceDAdjacence graphe, int *sommetTrie){
    int i, j, nbrPred;

    for(i = 0; i < graphe.n; i++){
            if(sommetTrie[i] == 0){
                nbrPred = 0;
                for(j = 0; j < graphe.n; j++){
                    if(graphe.matrice[j][i] != 0){
                        nbrPred++;
                        break;
                    }
                }
                if(nbrPred == 0) return i;
            }
    }
return -1;
}

int sommetSuivantANumerote(MatriceDAdjacence graphe, int *sommetTrie){
    int i, j, temp;
    for(i = 0; i < graphe.n; i++){
            if(sommetTrie[i] == 0){
                temp = 0;
                for(j = 0; j < graphe.n; j++){
                    // si j est un pr�decesseur non num�rot�
                    if(graphe.matrice[j][i] != 0 && sommetTrie[j] == 0){
                            break;
                    }
                    temp++;
                }
                // si temp egale le nombre de sommet alors
                // pas de predecesseurs non num�rot�
                if(temp == graphe.n) return i;
            }
    }
return -1;
}

void Bellman(MatriceDAdjacence graphe, int x0)
{
	int V = graphe.n;
	int *lambda = (int*)malloc(V * sizeof(int));
	int *pi = (int*)malloc(V * sizeof(int));
	int i, j;

	// Etape 1: Tri Topologique
	int *sommetTrie = triTopo(graphe, x0);
	// Etape 2: Initialisation()
	initialisation(lambda, pi, x0, V);
	// Etape 3: Realacher les arcs
	int s, k;
	for ( k = 2; k <= V; k++)
	{
	    // chercher le sommet dont la num�rotation est �gale � k
	    for(s = 0; s < V ; s++){
            if(sommetTrie[s] == k){
                j = s; // sommet j trouv�
                break;
            }
	    }
	    // pour tout i pr�decesseur de j, relacher!
		for ( i = 0; i < V; i++)
		{
			if (graphe.matrice[i][j] != 0)
				relacher(lambda, pi, i, j, graphe.matrice[i][j]);
		}

	}

	afficherDistanceEtPere(lambda, pi, V);

	return;
}


//  Hassan Zekkouri
