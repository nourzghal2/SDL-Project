#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "background.h"
//background


void initBack(Background *b)
{	
	b->backgroundImg=IMG_Load("background.png");
	b->camera.x=0;
	b->camera.y=0;
	b->camera.h=600;
	b->camera.w=1000;
	
	b->backgroundPos.x=0;
	b->backgroundPos.y=0;
	b->backgroundPos.h=600;
	b->backgroundPos.w=500;

	b->backgroundPos2.x=500;
	b->backgroundPos2.y=0;
	b->backgroundPos2.h=600;
	b->backgroundPos2.w=500;

}

void afficherBack(Background b,SDL_Surface *screen)
{
	//b->backgroundImg=IMG_Load("background.png");
	SDL_BlitSurface(b.backgroundImg,&b.camera,screen,NULL);
}
void afficherBack_partage(Background b,SDL_Surface *screen)
{
	SDL_BlitSurface(b.backgroundImg,&b.backgroundPos,screen,NULL);
	SDL_Rect pos={500,0,600,600};
	SDL_BlitSurface(b.backgroundImg,&b.backgroundPos2,screen,&pos);

}

void scrolling(SDL_Rect *camera,int direction,int pasAvancement){
	if (direction==0)
	{
		if(camera->x < 3250) camera->x += pasAvancement;
	}else if (direction==1)
	{
		if (camera->x > 0) camera->x -= pasAvancement;
	}
		
}

SDL_Color GetPixel(SDL_Surface *mask,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//determine position
char * pPosition=(char*)mask->pixels;
pPosition+=(mask->pitch *y);
pPosition+=(mask->format->BytesPerPixel *x);
memcpy(&col,pPosition,mask->format->BytesPerPixel);
//convertir color 
SDL_GetRGB(col,mask->format,&color.r,&color.g,&color.b);
return(color);
}
int collisionbb_droite( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int pos[3][2];
pos[0][0]=100+camera.x+posjoueur.x+posjoueur.w;
pos[0][1]=120+posjoueur.y;
pos[1][0]=100+camera.x+posjoueur.x+posjoueur.w;
pos[1][1]=120+posjoueur.y+posjoueur.h/2;
pos[2][0]=100+camera.x+posjoueur.x+posjoueur.w;
pos[2][1]=120+posjoueur.y+posjoueur.h;
for(i=0;i<2 && collision==0;i++)
{test=GetPixel(mask,pos[i][0],pos[i][1]);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;
//collision=1;

}
return collision;
}


int collisionbb_gauche( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int pos[3][2];
pos[0][0]=100+camera.x+posjoueur.x;
pos[0][1]=120+posjoueur.y;
pos[1][0]=100+camera.x+posjoueur.x;
pos[1][1]=120+posjoueur.y+posjoueur.h/2;
pos[2][0]=100+camera.x+posjoueur.x;
pos[2][1]=120+posjoueur.y+posjoueur.h;
for(i=0;i<2 && collision==0;i++)
{test=GetPixel(mask,pos[i][0],pos[i][1]);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;
//collision=1;

}
return collision;
}




int collisionbb_up( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int posX,posY;
posX=100+camera.x+ posjoueur.x+ posjoueur.w/2;
posY=120+posjoueur.y;

test=GetPixel(mask,posX,posY);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;

return collision;
}


int collisionbb_down( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int posX,posY;
posX=100+camera.x+ posjoueur.x+ posjoueur.w/2;
posY=120+posjoueur.y+ posjoueur.h;

test=GetPixel(mask,posX,posY);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;

return collision;
}


