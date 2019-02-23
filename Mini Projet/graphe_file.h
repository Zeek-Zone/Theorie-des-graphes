#ifndef H_GRAPHEFILE
#define H_GRAPHEFILE
/**
* Fichier header des élément lié aux files de projets
* @author Hassan Zekkouri
* @date 18/11/2018   22:30
* @project Mini-projet : Imlémentations des graphes
*/

/****************************************************************/
typedef struct arc Arc;
struct arc { //Arete
          int extInitial;
          int extTerminal;
};
/**
*  Sommet: (Element du file)
          valeur : Entier
          arc : pointeur sur l'Arc
          suivant : Pointeur sur le sommet suivant
*/
typedef struct sommet Sommet;
struct sommet {
          int valeur;
          Arc  *arc;
          Sommet *suivant;
};
/**
*  FileSucc (structure principale du file)
          nbrSucc : Entier
          tete : Pointeur sur la premiere sommet dans le file
*/
typedef struct fileSuccesseur FileSuccesseur;
struct fileSuccesseur{
          int taille;
          Sommet *tete;
};

// les fonctions de manipulation
Arc* creerArc(int initial, int terminal);
Sommet* creerSommet(int extInitial, int extTerminal);
FileSuccesseur* creerFile(int extInitial, int numSucc);
FileSuccesseur *initialiserFile();
void enfiler(FileSuccesseur *file, int extInitial, int extTerminal);
int defiler(FileSuccesseur *file);
void afficherFile(FileSuccesseur *file);

#endif //H_GRAPHEFILE

