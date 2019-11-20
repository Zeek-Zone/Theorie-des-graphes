#include <stdio.h>
#include <stdlib.h>
#include "file.h"

/************** creerFile() *******************/

pFile creerFile(){
    pFile f = (pFile)malloc(sizeof(File));
    f->tete = NULL;
    f->queue = NULL;
    f->taille = 0;
return f;
}

/************** enfile(pFile f, int element) *******************/

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
          if( f->taille == 0 ) // file vide
                    f->tete = f->queue = cell;
          else{ // file non vide
                    f->queue->suivant = cell;
                    f->queue = cell; // on ajoute à la fin (file)
          }

          (f->taille)++;
}

/************** empiler(pFile f, int element) *******************/

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
                    f->tete = cell; // en ajoute au debut (pile)
          }

          (f->taille)++;
}

/************** defile(pFile f) *******************/

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

/************** defilement(pFile f){ *******************/

int defilement(pFile f){
    /* supprime l'element en tete (pop) et retourne sa valeur */

          if( f == NULL ){
                   printf("Ce file n\'existe pas. -defiler");
                   exit(-1);
          }

          pCellule cell = f->tete;
          int element = cell->element;

          if( f->taille == 1 ) // la file devient vide
                    f->tete = f->queue = NULL;
          else
                   f->tete = f->tete->suivant;
          free(cell);
          (f->taille)--;
return element;
}

/************** depiler(pFile f) *******************/

int depiler(pFile f){
    /* supprime l'element en tete (pop) et et retourne sa valeur */

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

/************** afficheFile(pFile f) *******************/

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
