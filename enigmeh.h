#ifndef  ENIGME_H_INCLUDED 
#define ENIGMLE_H_INCLUDED

#include<stdio.h> 
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h> 

typedef struct enigmes_question
{
char reponse[4];
char q[400];
char rep1[3];
char rep2[3];
char rep3[3];
char rep4[3];
}enigmes_question;

typedef struct enigme
{
enigmes_question en[30];
int reponse;
}enigme;

int initialiser_enigmes();
void generation(enigme *E,int val);
void affichage(enigme *E ,int val);
int resolution_enigmes(char reponse_choisie[4], int val,enigme *E);// 
void free_enigme;
#endif  /* ENIGME_H_ */
