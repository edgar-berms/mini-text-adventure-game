#include "entite.hpp"
#include <random>
#include <iostream>

using namespace std;

Entite::Entite(){
    x = 4;
    y = 4;
    lvl = 1;
}
Entite::Entite(int posx,int posy, int niveau){
    x = posx;
    y = posy;
    lvl = niveau;
}
Entite::Entite(const Entite &autre){
    x = autre.x;
    y = autre.y;
    lvl = autre.lvl;
}
int Entite::getX(){
    return x;
}
void Entite::setX(int n){
    x = n;
}
int Entite::getY(){
    return y;
}
void Entite::setY(int n){
    y = n;
}
void Entite::afficher(){
    cout << "(" << x << "," << y << ")" << endl;
}
void Entite::setLvl(int n){
    lvl = n;
}
int Entite::getLvl(){
    return lvl;
}