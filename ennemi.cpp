#include "ennemi.hpp"
#include <iostream>

Ennemi::Ennemi(){
    pv = 0;
    pa = 0;
}
Ennemi::Ennemi(const Ennemi &autre){
    pv = autre.pv;
    pa = autre.pa;
}
int Ennemi::getPv(){
    return pv;
}
int Ennemi::getPa(){
    return pa;
}
void Ennemi::setPv(int n){
    pv = n;
}
void Ennemi::setPa(int n){
    pa = n;
}
bool Ennemi::mort(){
    if(pv <= 0){
        return 0;
    }
    return 1;
}
void Ennemi::afficher(){
    std::cout << "PV : ";
    std::cout << pv << std::endl;
    std::cout << "PA : ";
    std::cout << pa << std::endl;
}