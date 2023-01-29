#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

typedef struct {
	SDL_Surface *backgroundImg;
        SDL_Rect camera,backgroundPos,backgroundPos2;
    
}Background;

void initBack(Background *b);
void afficherBack(Background b,SDL_Surface *screen);
void afficherBack_partage(Background b,SDL_Surface *screen);
void scrolling(SDL_Rect *camera,int direction,int pasAvancement);
SDL_Color GetPixel(SDL_Surface *mask,int x,int y);
int collisionbb_droite( SDL_Rect posJoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionbb_gauche( SDL_Rect posJoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionbb_up( SDL_Rect posJoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionbb_down( SDL_Rect posJoueur, SDL_Surface *mask,SDL_Rect camera);


#endif // JEUX_H_INCLUDED
