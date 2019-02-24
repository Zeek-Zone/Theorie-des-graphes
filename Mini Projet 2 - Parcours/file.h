#ifndef H_FIFO
#define H_FIFO

typedef struct cellule* pCellule;
typedef struct cellule Cellule;

struct cellule{
    int element;// sommet
    pCellule suivant;
};

typedef struct file File;

struct file{
       int taille;
       pCellule tete;
       pCellule queue;
};

typedef  File* pFile;

pFile creerFile();
void enfile(pFile f, int element);
void defile(pFile f);
int defilement(pFile f);
void afficheFile(pFile f);

void empiler(pFile f, int element);
int depiler(pFile f);

#endif // H_FIFO
