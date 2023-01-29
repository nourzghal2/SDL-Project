#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct Personne
{
	SDL_Surface *images[2][4]; /*!< matrices contenant les 24 frames*/
	SDL_Rect position;/*!< position de perso*/
	int direction;/*!< direction du perso*/
	int nbr_frame;/*!< nombre de frame a afficher*/
	/*
		0:droite
		1:gauche
	*/
	double vitesse,acceleration,vitesse_saut;
	double dx;
	int ground,up;

}Personne;

typedef struct  vie
{
	SDL_Surface *vie;
	int valeur_vie;
	SDL_Rect pos_spr,pos;
}vie;



void initPerso2(Personne *p);

void initPerso(Personne *p);

void afficherPerso(Personne p, SDL_Surface * screen);

void deplacerPerso (Personne *p,int dt);
void deplacerPerso2 (Personne *p,int dt);

void animerPerso (Personne* p);

void saut (Personne* p) ;


void initialiser_score(vie *v);
void update_score(vie *v);
void afficher_vie(vie *v,SDL_Surface *screen);

 #endif
