#ifndef sauvegarde_H_INCLUDED
#define sauvegarde_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Personne.h"
#include "background.h"

typedef struct save
{
  
  Personne p;
  Background b;
}save;



void sauvegarder (Personne p,Background b) ; 
int charger (Personne *p,Background *b);


#endif
