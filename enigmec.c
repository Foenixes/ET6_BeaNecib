/**
* @file enigme.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

/**
* @brief for the enigme.
* @param e the enigme
* @return Nothing
*/

void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;
}

/**
* @brief to generate the enigme.
* @param alea for the aleatory enigme.
* @param screen to load image.
* @param e the enigme
* @return Nothing
*/

 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
}
 
/**
* @brief for the solution.
* @param quest enigme.
* @return Nothing
*/

 int solution_e (char image [],int *ques)
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.png")==0)
 	{
     solution =3 ;
 	(*ques)=1;}
 	else  	if(strcmp(image,"2.png")==0)
 	{
 		solution =2;
		(*ques)=2;

 	}
 	else 	if(strcmp(image,"3.png")==0)
 	{
 		solution =1;
(*ques)=3;	 	}
 	
 }
return solution;
}

/**
* @brief for the resolution.
* @param r for the result.
* @return Nothing
*/

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
int doing=1;
while(doing){
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
doing=0;
			   break ;
			   case  SDLK_z :
			   r= 2;
doing=0;
			   break;
			   case SDLK_e: 
			   r=3 ;
doing=0;
			   break;
			    }
       break ;

                 
	}}
  return r ;
}
 
/**
* @brief for the result enigme.
* @param s for the solution.
* @param r for the result.
* @param en for the enigme.
* @return Nothing
*/

 int afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en,int ques)
 {SDL_Surface * image=NULL;
 switch(ques){
case 1:

image=IMG_Load("1e.png");
break;
case 2:

image=IMG_Load("2e.png");
break;
case 3:

image=IMG_Load("3e.png");
break;
}
	SDL_BlitSurface(image, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	if (r==s)
 	{

	en->img=IMG_Load("CORRECT.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
return 1;
 		} 	
 	else
 	{
 		en->img=IMG_Load("WRONG.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
return 0;
 	}
 }
 
