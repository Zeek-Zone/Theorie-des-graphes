#ifndef H_GRAPHEFILE
#define H_GRAPHEFILE
/**
* Fichier header des élément lié aux files de projets
* @author Hassan Zekkouri
* @date 18/11/2018   22:30
* @project Mini-projet : Imlémentations des graphes
*/


/****************************************************************/
/**
*  Arc: arc ou arête
          extInitial : Entier
          extTerminal : Entier

*/
typedef struct arc Arc;
struct arc { //Arete
          int extInitial;
          int extTerminal;
};

/****************************************************************/
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

/****************************************************************/
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

/****************************************************************/
// les fonctions de manipulation

/* Cette fonction cree un arc */
Arc* creerArc(int initial, int terminal);

/* Cette fonction cree un sommet element de la file */
Sommet* creerSommet(int extInitial, int extTerminal);

/* Cette fonction saisie la file */
FileSuccesseur* saisirFile(int extInitial, int numSucc);

/* Cette fonction cree une file initialement vide */
FileSuccesseur *creerFile();

/* Cette fonction enfile un élément dans la file */
void enfiler(FileSuccesseur *file, int extInitial, int extTerminal);

/* Cette fonction defile un élément de la file */
int defiler(FileSuccesseur *file);

/* Cette fonction permet d'afficher la file */
void afficherFile(FileSuccesseur *file);

#endif //H_GRAPHEFILE

