#ifndef H_FIFO
#define H_FIFO

#include "utilitaires.h"

/**
Fichier header de la structure file et pile: même structure de données
*/

typedef struct element Element;

struct element{
    Arc arc;
    Element *suivant;
};

typedef struct file File;

struct file{
       int taille;
       Element *tete;
       Element *queue;
};

typedef  File* pFile;

// fonctions de la file
pFile creerFile();
void enfiler(pFile f, Arc);
void defiler(pFile f);

#endif // H_FIFO
