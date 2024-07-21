#include <iostream>
#include "heros.hpp"

using namespace std;

Heros::Heros():Entite(){
    pv = 50;
    pvMax = 50;
    pa = 10;
    xp = 0;
    lvl = 1;
    luck = 0;
    //Entite *inventaire[];
}
Heros::Heros(const Heros &autre):Entite(autre){
    pv = autre.pv;
    pvMax = autre.pvMax;
    pa = autre.pa;
    xp = autre.xp;
    lvl = autre.lvl;
    luck = autre.luck;
}
int Heros::getPv(){
    return pv;
}
int Heros::getPa(){
    return pa;
}
int Heros::getXp(){
    return xp;
}
int Heros::getLuck(){
    return luck;
}
int Heros::getLvl(){
    return lvl;
}
void Heros::restorePv(int n){
    if((pv+n) < pvMax){
        pv = pv + n;
    }
    else{
        int temp;
        temp = pvMax - pv;
        pv = temp + n;
    }
}
void Heros::setPv(int n){
    pv = n;
}
void Heros::setPa(int n){
    pa = n;
}
void Heros::gagneXp(int n){
    xp = xp + n; 
}
void Heros::lvlUp(){
    if (xp > 100){
        xp = xp - 100;
        lvl = lvl + 1;
        setPv(pv + 15);
        setPa(pa + 5);
        restorePv(pv);
        ajouteLuck(2);
    }
}
void Heros::ajouteLuck(int n){
    luck = luck + n;
}
void Heros::afficher(){
    cout << "PV : ";
    cout << pv << endl;
    cout << "PA : ";
    cout << pa << endl;
    cout << "Experience : ";
    cout << xp << endl;
    cout << "LVL : ";
    cout << lvl << endl;
    cout << "LUCK : ";
    cout << luck << endl;
}
bool Heros::mort(){
    if(pv <= 0){
        return 0;
    }
    return 1;
}

