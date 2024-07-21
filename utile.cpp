#include "utile.hpp"
#include <iostream>
#include <random>

using namespace std;

void ennemiAttaque(Heros &h,Ennemi &e){
    h.setPv(h.getPv() - e.getPa());
}

void herosAttaque(Heros &h,Ennemi &e){
    e.setPv(e.getPv() - h.getPa()); 
}

void combat(Heros &h, Ennemi &e){
    cout << "PV initiaux du héros : "<< h.getPv() << " et Pv initiaux de l'ennemi : " << e.getPv() << endl;
    while(e.mort() && h.mort()){
        herosAttaque(h,e);
        if(e.mort()){
            ennemiAttaque(h,e);
        }
    }
    if(!(e.mort())){
        cout << "Ennemi mort" << endl; 
        int minXp = 10;
        int maxXp = 25;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> d(minXp,maxXp);
        h.gagneXp(d(gen));
        h.lvlUp();
    }
    else{
        cout << "Le héros est mort" << endl;
    }
    h.afficher();
    e.afficher();
}

bool inWall(int **carte,int x,int y){
    if(carte[x][y] == 1){
        return 1;
    }
    else{
        return 0;
    }
}

void deplacement(int **carte,Heros &h){
    if(bas(carte,h) && haut(carte,h) && gauche(carte,h) && droite(carte,h)){
        cout << "On peut se déplacer dans les 4 directions" << endl;
        cout << "Pour aller en haut saisir : h" << endl;
        cout << "Pour aller en bas saisir : b" << endl;
        cout << "Pour aller a gauche saisir : g" << endl;
        cout << "Pour aller a droite saisir : d" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement == "h"){
            h.setX(h.getX()-1);
        }
        else if(deplacement  == "b"){
            h.setX(h.getX()+1);
        }
        else if(deplacement == "g"){
            h.setY(h.getY()-1);
        }
        else if(deplacement == "d"){
            h.setY(h.getY()+1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(haut(carte,h) && gauche(carte,h) && droite(carte,h)){
        cout << "On peut se déplacer dans 3 directions" << endl;
        cout << "Pour aller en haut saisir : h" << endl;
        cout << "Pour aller a gauche saisir : g" << endl;
        cout << "Pour aller a droite saisir : d" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement == "h"){
            h.setX(h.getX()-1);
        }
        else if(deplacement == "g"){
            h.setY(h.getY()-1);
        }
        else if(deplacement == "d"){
            h.setY(h.getY()+1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(haut(carte,h) && bas(carte,h) && droite(carte,h)){
        cout << "On peut se déplacer dans 3 directions" << endl;
        cout << "Pour aller en haut saisir : h" << endl;
        cout << "Pour aller en bas saisir : b" << endl;
        cout << "Pour aller a droite saisir : d" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement == "h"){
            h.setX(h.getX()-1);
        }
        else if(deplacement == "b"){
            h.setX(h.getX()+1);
        }
        else if(deplacement == "d"){
            h.setY(h.getY()+1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(haut(carte,h) && gauche(carte,h) && bas(carte,h)){
        cout << "On peut se déplacer dans 3 directions" << endl;
        cout << "Pour aller en haut saisir : h" << endl;
        cout << "Pour aller a gauche saisir : g" << endl;
        cout << "Pour aller a bas saisir : b" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement == "h"){
            h.setX(h.getX()-1);
        }
        else if(deplacement == "g"){
            h.setY(h.getY()-1);
        }
        else if(deplacement == "b"){
            h.setX(h.getX()+1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(droite(carte,h) && gauche(carte,h) && bas(carte,h)){
        cout << "On peut se déplacer dans 3 directions" << endl;
        cout << "Pour aller en haut saisir : h" << endl;
        cout << "Pour aller a gauche saisir : g" << endl;
        cout << "Pour aller a bas saisir : b" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement == "d"){
            h.setY(h.getY()+1);
        }
        else if(deplacement == "g"){
            h.setY(h.getY()-1);
        }
        else if(deplacement == "b"){
            h.setX(h.getX()+1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(haut(carte,h) && droite(carte,h)){
        cout << "On peut se déplacer dans dans 2 directions" << endl;
        cout << "Pour aller en haut saisir : h" << endl;
        cout << "Pour aller a droite saisir : d" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement == "h"){
            h.setX(h.getX()-1);
        }
        else if(deplacement == "d"){
            h.setY(h.getY()+1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(haut(carte,h) && gauche(carte,h)){
        cout << "On peut se déplacer dans dans 2 directions" << endl;
        cout << "Pour aller en haut saisir : h" << endl;
        cout << "Pour aller a gauche saisir : g" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement == "h"){
            h.setX(h.getX()-1);
        }
        else if(deplacement == "g"){
            h.setY(h.getY()-1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(bas(carte,h) && droite(carte,h)){
        cout << "On peut se déplacer dans dans 2 directions" << endl;
        cout << "Pour aller en bas saisir : b" << endl;
        cout << "Pour aller a droite saisir : d" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement  == "b"){
            h.setX(h.getX()+1);
        }
        else if(deplacement == "d"){
            h.setY(h.getY()+1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }

    else if(bas(carte,h) && gauche(carte,h)){
        cout << "On peut se déplacer dans 2 directions" << endl;
        cout << "Pour aller en bas saisir : b" << endl;
        cout << "Pour aller a gauche saisir : g" << endl;
        string deplacement;
        cout << "Votre saisi : ";
        cin >> deplacement;
        if(deplacement  == "b"){
            h.setX(h.getX()+1);
        }
        else if(deplacement == "g"){
            h.setY(h.getY()-1);
        }
        else{
            cout << "erreur de frappe !!" << endl;
        }
    }
}

bool bas(int **carte,Heros &h){
    if(inWall(carte,h.getX()+1,h.getY())){
        return 0;
    }
    else{
        return 1;
    }
}
bool haut(int **carte,Heros &h){
    if(inWall(carte,h.getX()-1,h.getY())){
        return 0;
    }
    else{
        return 1;
    }
}
bool gauche(int **carte,Heros &h){
    if(inWall(carte,h.getX(),h.getY()-1)){
        return 0;
    }
    else{
        return 1;
    }
}
bool droite(int **carte,Heros &h){
    if(inWall(carte,h.getX()+1,h.getY()+1)){
        return 0;
    }
    else{
        return 1;
    }
}

int getPos(int **carte,int x,int y){
    return carte[x][y];
}
void setPos(int **carte,int x,int y,int n){
    carte[x][y] = n;
}

void rencontre(int **carte,Heros &h,bool &fin,Carte &c, bool &finNiv){
    if (getPos(carte,h.getX(),h.getY()) == 2){
        Ennemi e;
        creerEnnemi(e,c);
        combat(h,e);
        setPos(carte,h.getX(),h.getY(),4);
    }
    else if(getPos(carte,h.getX(),h.getY()) == 3){
        h.restorePv(10);
        setPos(carte,h.getX(),h.getY(),4);
    }
    else if(getPos(carte,h.getX(),h.getY()) == 5){
        cout << "Vous avez atteint la fin du niveau !!" << endl;
        finNiv = true;
        h.setX(4);
        h.setY(4);
    }
    else{
        setPos(carte,h.getX(),h.getY(),4);
    }
}

void creerEnnemi(Ennemi &e,Carte &c){
    e.setLvl(c.getLvl());
    if(e.getLvl() == 1){
        int minPv = 8;
        int maxPv = 15;
        int minPa = 8;
        int maxPa = 15;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distPv(minPv,maxPv);
        std::uniform_int_distribution<int> distPa(minPa,maxPa);
        e.setPv(distPv(gen));
        e.setPa(distPa(gen));
    }
    if(e.getLvl() == 2){
        int minPv = 15;
        int maxPv = 20;
        int minPa = 10;
        int maxPa = 20;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distPv(minPv,maxPv);
        std::uniform_int_distribution<int> distPa(minPa,maxPa);
        e.setPv(distPv(gen));
        e.setPa(distPa(gen));
    }
    if(e.getLvl() == 3){
        int minPv = 20;
        int maxPv = 25;
        int minPa = 15;
        int maxPa = 25;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distPv(minPv,maxPv);
        std::uniform_int_distribution<int> distPa(minPa,maxPa);
        e.setPv(distPv(gen));
        e.setPa(distPa(gen));
    }
}