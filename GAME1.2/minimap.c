#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
void initmap( minimap * m)
{
m->img_map=IMG_Load("minimap.png");//minimap
m->img_joueur=IMG_Load("mini_joueur.png");

m->pos_map.x=0;
m->pos_map.y=0;
}
SDL_Rect MAJMinimap (SDL_Rect Posjoueur,int redemensionement,SDL_Rect camera)////////pos absoluee
{
SDL_Rect pos_joueur;
pos_joueur.x= ((camera.x +Posjoueur.x)*redemensionement)/100;
pos_joueur.y= 20+((camera.y +Posjoueur.y)*redemensionement)/100;
return pos_joueur;
}
void afficherminimap (minimap m,SDL_Surface *screen)
{

SDL_BlitSurface(m.img_map,NULL,screen,&m.pos_map);
SDL_BlitSurface(m.img_joueur,NULL,screen,&m.pos_joueur);
}
void affichertemp (Uint32 *temps,SDL_Surface *screen,TTF_Font *police)
{

SDL_Surface *chrono = NULL;
SDL_Rect positionChrono;
SDL_Color couleur = {255,255,255};
int min=0,sec=0;
char texteChrono [40] = "";
positionChrono.x = 840;
positionChrono.y = 10;
(*temps)=SDL_GetTicks();
(*temps)/=1000;
min=((*temps)/60);
sec=(*temps) - (60*min);


sprintf(texteChrono,"%02d:%02d",min,sec);
SDL_FreeSurface(chrono);
chrono = TTF_RenderText_Solid(police,texteChrono,couleur);
SDL_BlitSurface(chrono,NULL,screen,&positionChrono);
//}

}


