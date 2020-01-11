#ifndef H_FIFO
#define H_FIFO

/**
Fichier header de la structure de données File
*/

typedef struct cellule* pCellule;
typedef struct cellule Cellule;

// La structure cellule represente l'element de la file == Sommet
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

void enfile(pFile f, int element);

#endif // H_FIFO
