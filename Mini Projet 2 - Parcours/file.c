#include <stdio.h>
#include <stdlib.h>
#include "file.h"

pFile creerFile(){
    pFile f = (pFile)malloc(sizeof(File));
    f->tete = NULL;
    f->queue = NULL;
    f->taille = 0;
return f;
}

void enfile(pFile f, int element){
          if( f == NULL){
                   printf("Ce file n\'existe pas. -Engfiler");
                   exit(-1);
          }
          pCellule cell = (pCellule)malloc(sizeof(Cellule));
          if( cell == NULL){
                    printf("Erreur: la cellule n\'est pas allouer. - enfiler ");
                    exit(-1);
          }
          cell->element = element;
          cell->suivant = NULL;
          if( f->taille == 0 )
                    f->tete = f->queue = cell;
          else{
                    f->queue->suivant = cell;
                    f->queue = cell;
          }

          (f->taille)++;
}

void empiler(pFile f, int element){
          if( f == NULL){
                   printf("Ce file n\'existe pas. -Engfiler");
                   exit(-1);
          }
          pCellule cell = (pCellule)malloc(sizeof(Cellule));
          if( cell == NULL){
                    printf("Erreur: la cellule n\'est pas allouer. - enfiler ");
                    exit(-1);
          }
          cell->element = element;
          cell->suivant = NULL;
          if( f->taille == 0 )
                    f->tete = f->queue = cell;
          else{
                    cell->suivant = f->tete;
                    f->tete = cell;
          }

          (f->taille)++;
}

void  defile(pFile f){
    /* supprime l'element en tete (pop) */
          if( f == NULL ){
                   printf("Ce file n\'existe pas. -defiler");
                   exit(-1);
          }
          pCellule cell = f->tete;

          if( f->taille == 1 )
                    f->tete = f->queue = NULL;
          else
                   f->tete = f->tete->suivant;

          free(cell);
          (f->taille)--;
}

int defilement(pFile f){
    /* supprime l'element en tete (pop) et le retourne */
          if( f == NULL ){
                   printf("Ce file n\'existe pas. -defiler");
                   exit(-1);
          }
          pCellule cell = f->tete;
          int element = cell->element;

          if( f->taille == 1 )
                    f->tete = f->queue = NULL;
          else
                   f->tete = f->tete->suivant;
          free(cell);
          (f->taille)--;
return element;
}

int depiler(pFile f){
    /* supprime l'element en tete (pop) et le retourne */
          if( f == NULL ){
                   printf("Ce file n\'existe pas. -defiler");
                   exit(-1);
          }
          pCellule cell = f->tete;
          int element = cell->element;

          if( f->taille == 1 )
                    f->tete = f->queue = NULL;
          else
                   f->tete = f->tete->suivant;
          free(cell);
          (f->taille)--;
return element;
}


void afficheFile(pFile f){
            if( f == NULL ){
                   printf("Ce file n\'existe pas. -afficheFile");
                   exit(-1);
          }

          pCellule cell = f->tete;
          while( cell != NULL){
                    printf("%d ", cell->element);
                    cell = cell->suivant;
          }
          printf("\n");
}
