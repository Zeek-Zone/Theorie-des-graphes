
#include "composanteFconnexe.h"

int nbrArcMarque = 0;


int* fusioner(int *tab1, int n, int *tab2, int m){
    int taille = n + m;
    int *res = (int*)malloc(taille*sizeof(int));
    int i,j;
    for(i = 0, j = 0; i < n ; i++ , j++){
        res[j] = tab1[i];
    }

    for(i = 0; i < m ; i++ , j++){
        res[j] = tab2[i];
    }
return res;
}

int choisirUnSommet(int *sommetDansCFC, int n){
    int i;
    for(i = 0; i < n; i++){
        if(sommetDansCFC[i] == 0)
            return i;
    }
return -1;
}

int trouverArcNonMarque(MatriceDAdjacence graphe, Pile *P, int *sommetDansCFC, Arc *arcsMarque){

    Element *top = P->premier;

    // Cherchons un arc sortant de "top" et non encore marqu�
    int s, i, j;
    for(i = 0; i < top->comp.nbrSommet; i++){
            // chercher un arc non marqu�
            // et rrtourener son extremite terminal j
            s = top->comp.sommets[i];
            for(j = 0 ; j < graphe.n ; j++){
                if(graphe.matrice[s][j] != 0 && sommetDansCFC[j] == 0){
                    if(arcNestPasMarque(arcsMarque, s, j) == 1){
                        return j;
                    }
                }
            }
    }

return -1;
}

int trouverComposante(Pile *P, int s){
    int i = 0;
    Element *courant = P->premier;
    while(courant != NULL){
            int j ;
            for(j = 0; j < courant->comp.nbrSommet ; j++){
                if(courant->comp.sommets[j] == s)
                    return i;
            }
            i++;
    }
return -1;
}

void mettreAjourLaPile(Pile *P, int indice){
    int i = 1, taille = 0;
    Element *pred = P->premier,
            *courant = pred->suivant;
    int *tab = fusioner(pred->comp.sommets, pred->comp.nbrSommet, courant->comp.sommets, courant->comp.nbrSommet);
    taille += pred->comp.nbrSommet + courant->comp.nbrSommet;

    while(i != indice && courant->suivant != NULL){
            pred = courant;
            courant = pred->suivant;
            i++;
            tab = fusioner(tab, taille, courant->comp.sommets, courant->comp.nbrSommet);
            taille += courant->comp.nbrSommet;
    }
    // d�piler "indice" fois
    for(i = 0; i <= indice ; i++){
        free( depiler(P) );
    }
    // emplier l'union (les composante fusionn�e
    Composante *c = creerComposante();
    c->nbrSommet = taille;
    c->sommets = tab;
    empiler(P, c);
return;
}

void marquerSommet(Composante c, int *sommetDansCFC){
    int i;
    for(i = 0; i < c.nbrSommet ; i++){
        sommetDansCFC[ c.sommets[i] ] = 1;
    }
return;
}


void marquerArc(Arc *arcMarque, int s, int ss){
    nbrArcMarque++;
    arcMarque = realloc(arcMarque, nbrArcMarque * sizeof(Arc));

    arcMarque[nbrArcMarque - 1].src = s;
    arcMarque[nbrArcMarque - 1].dest = ss;
    arcMarque[nbrArcMarque - 1].poids = 1; // pas int�ressant
}

int arcNestPasMarque(Arc *arcMarque, int s, int ss){
    int i;
    for(i = 0; i < nbrArcMarque ; i++){
        if(arcMarque[i].src == s && arcMarque[i].dest == ss)
            return 0;
    }
return 1;
}


Composante *compsanteEmpile(int s){
        Composante *c = creerComposante();
        c->nbrSommet = 1;
        c->sommets = (int*)realloc(c->sommets, sizeof(int));
        c->sommets[0] = s;
return c;
}

void ajouterComposante(CFC *cfc, Composante *c){
    cfc->taille++;
    cfc->composantes = (Composante*)realloc(cfc->composantes, cfc->taille * sizeof(Composante));
    cfc->composantes[cfc->taille - 1] = *c;
}

void composanteFortementConnexe(MatriceDAdjacence graphe){

    CFC *cfc = creerCFC(); // les composantes fortement connexes

    Pile *P = initialiser();
    int *sommetDansCFC = (int*)calloc(graphe.n, sizeof(int));
    int *sommetDansP = (int*)calloc(graphe.n, sizeof(int));
    Arc *arcMarque = (Arc*)malloc(sizeof(Arc));
    int nombreSommetDansCFC = 0;
    int s , ss;
    printf("1\n");
    // tant que il exite des sommets non encore regrouper dans une composante
    while(nombreSommetDansCFC < graphe.n){
            printf("2 ");
        s = choisirUnSommet(sommetDansCFC, graphe.n);
        Composante *c = compsanteEmpile(s);
        empiler(P, c);
        sommetDansP[s] = 1;
        while(P->taille > 0){
                printf("3 ");
                ss = trouverArcNonMarque(graphe, P, sommetDansCFC, arcMarque);
                printf("  SS %d\n", ss);
                if(ss != -1){
                    if(sommetDansP[ss] == 0){
                        Composante *cc = compsanteEmpile(s);
                        empiler(P, cc); printf("4\n");
                        sommetDansP[ss] = 1;
                        marquerArc(arcMarque, s, ss);
                    }else{
                        int i = trouverComposante(P, ss); printf("5 ");
                        if(i > 0){
                            mettreAjourLaPile(P, i);
                        }
                    }
                }else{
                    printf("6\n");
                    c = depiler(P);
                    marquerSommet(*c, sommetDansCFC);
                    ajouterComposante(cfc, c);
                    nombreSommetDansCFC += c->nbrSommet;
                    free(c);
                }
        }
    }
return;
}

void afficherCFC(CFC *cfc){
    int i, j;

    for(i = 0; i < cfc->taille ; i++){
        printf("\nComposante %d:\n", i+1);
        for(j = 0; j < cfc->composantes[i].nbrSommet ; j++)
            printf("%d ", cfc->composantes[i].sommets[j]);
        printf("\n");
    }

}

