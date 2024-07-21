#ifndef __UTILE__
#define __UTILE__

#include "ennemi.hpp"
#include "heros.hpp"
#include "carte.hpp"

void creerEnnemi(Ennemi &,Carte &);

void ennemiAttaque(Heros &,Ennemi &);
void herosAttaque(Heros &,Ennemi &);
void combat(Heros &, Ennemi &);

bool inWall(int **,int,int);
void deplacement(int **,Heros &);

bool bas(int **,Heros &);
bool haut(int **,Heros &);
bool gauche(int **,Heros &);
bool droite(int **,Heros &);

int getPos(int **,int,int);
void setPos(int**,int,int,int);
void rencontre(int **,Heros &,bool &,Carte &,bool &);

#endif