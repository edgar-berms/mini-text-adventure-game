#include "carte.hpp"
#include <iostream>
#include <random>

Carte::Carte(){
    tailleLarg = 9;
    tailleLong = 9;
    lvl = 1;
}

Carte::Carte(int niv){
    tailleLarg = 9;
    tailleLong = 9;
    lvl = niv;
}

Carte::Carte(const Carte &autre){
    tailleLarg = autre.tailleLarg;
    tailleLong = autre.tailleLong;
    lvl = autre.lvl;
}

Carte::~Carte(){
    std::cout << "Détruire la carte" << std::endl;
}

void Carte::creerCarte(int **carte){
    for(int i = 0; i < tailleLarg;i++){
        for(int j = 0;j < tailleLong; j++){
            if(j == 0 || i == 0 || j == tailleLong-1 || i == tailleLarg-1){
                carte[i][j] = 1;
            }
            else{
                carte[i][j] = 0;
            }
        }
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(1,tailleLarg-2);
    carte[4][4] = 4;
    for(int obj = 0; obj <= 6; obj++){
        int objX = distribution(mt);
        int objY = distribution(mt);
        if(carte[objX][objY] == 0 || carte[objX][objY] != 4){
            carte[objX][objY] = 3;
        }
        else{
            obj = obj - 1;
        }
    }
    for(int e = 0; e <= 14; e++){
        int ennemiX = distribution(mt);
        int ennemiY = distribution(mt);
        if(carte[ennemiX][ennemiY] == 0 || carte[ennemiX][ennemiY] != 4){
            carte[ennemiX][ennemiY] = 2;
        }
        else{
            e = e - 1;
        }
    }
    int sortieX = distribution(mt);
    int sortieY = distribution(mt);
    if(carte[sortieX][sortieY] == 4){
        while(carte[sortieX][sortieY] == 4){
            sortieX = distribution(mt);
            sortieY = distribution(mt);
        }
    }
    else{
        carte[sortieX][sortieY] = 5;
    }
}

void Carte::parcour(int **carte){
    for(int i = 0; i < tailleLarg;i++){
        for(int j = 0;j < tailleLong; j++){
            std::cout << carte[i][j];
        }
        std::cout << std::endl;
    } 
}

int Carte::getLong(){
    return tailleLong;
}
int Carte::getLarg(){
    return tailleLarg;
}
int Carte::getLvl(){
    return lvl;
}

void Carte::desalloue(int **carte){
    for(int i = 0; i < tailleLarg; i++){
        delete [] carte[i];
    }
    delete [] carte;
    std::cout << "Carte désallouer" << std::endl;
}

void Carte::setLvl(int n){
    lvl = n;
}