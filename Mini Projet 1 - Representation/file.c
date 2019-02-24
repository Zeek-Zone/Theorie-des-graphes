#include <stdio.h>
#include <stdlib.h>
#include "file.h"


/**********************************************************/

void enfile(pFile f, int element){
    /** cette fonction nous permet d'enfiler element dans la file f **/
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

          if( f->taille == 0 ) // file vide
                    f->tete = f->queue = cell;
          else{  // file non vide
                    f->queue->suivant = cell;
                    f->queue = cell;
          }

          (f->taille)++;
}


