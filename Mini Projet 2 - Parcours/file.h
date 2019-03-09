#ifndef H_FIFO
#define H_FIFO

/**
   Fichier header de la structure file et pile: même structure de données
*/

/// LA STRUCTURE FILE EST UTILISE AUSSI COMME UNE PILE,
/// ENFILER ET DEFILER ----> FILE
/// EMPILER ET DEOILER ----> PILE

typedef struct cellule* pCellule;
typedef struct cellule Cellule;

struct cellule{
    int element;
    pCellule suivant;
};

typedef struct file File;

struct file{
       int taille;
       pCellule tete;
       pCellule queue;
};

typedef  File* pFile;

// fonctions de gestion de la file
pFile creerFile();
void enfile(pFile f, int element);

/* supprime l'element en tete  */
void defile(pFile f);

/* supprime l'element en tete  et retourne sa valeur */
int defilement(pFile f);
void afficheFile(pFile f);

// fonctions de gestion de la pile
void empiler(pFile f, int element);

/* supprime l'element en tete (top) et et retourne sa valeur */
int depiler(pFile f);

#endif // H_FIFO
// HASSAN ZEKKOURI
