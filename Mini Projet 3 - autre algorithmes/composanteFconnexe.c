
#include "graphe_matrice.h"
#include "utilitaires.h"
#include "pile.h"

int choisirUnSommet(int *sommetDansCFC, int n){
    int i;
    for(i = 0; i < n; i++){
        if(sommetDansCFC[i] == 0)
            return i;
    }
return -1;
}

void composanteFortementConnexe(MatriceDAdjacence graphe){
    CFC *cfc = creerCFC();
    Pile *P = initialiser();
    int *sommetDansCFC = (int*)malloc(graphe.n, sizeof(int));
    int *sommetDansP = (int*)malloc(graphe.n, sizeof(int));
    int nombreSommetDansCFC = 0;

    while(nombreSommetDansCFC < graphe.n){

        s = choisirUnSommet(sommetDansCFC, graphe.n);
        Composante *c = compsanteEmpile(s);
        emiler(P, c);
        sommetDansP[s] = 1;

        while(P->taille > 0){
                s = trouverArcNonMarqué(P, sommetDansCFC);
                if(s != -1){
                    if(sommetDansP[s] == 0){
                        Composante *cc = compsanteEmpile(s);
                        emiler(P, cc);
                        sommetDansP[s] = 1;
                    }else{
                        int i = trouverComposante(CFC, s);
                        metreAjourLaPile(P, i);
                    }
                }else{
                    c = deplier(P);
                    marquerSommet(c, sommetDansCFC);
                }
        }
    }
}

Composante *compsanteEmpile(int s){
        Composante *c = creerComposante();
        c->nbrSommet = 1;
        c->sommets = (int*)realloc(c->sommets, c->nbrSommet * sizeof(int));
        c->sommets[c->nbrSommet - 1] = s;
return c;
}
