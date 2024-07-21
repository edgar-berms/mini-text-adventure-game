#include <iostream>
#include "entite.hpp"
#include "heros.hpp"
#include "ennemi.hpp"
#include "carte.hpp"
#include "utile.hpp"

using namespace std;

int main(){

    Heros nain;
    Carte c(1);
    Carte crt(2);
    Carte map(3);
    bool fin = false;
    bool finNiv = false;
    int niveau = 1;

    int **carte = new int *[c.getLong()];
        for (int i = 0; i < c.getLarg(); i++) {
            carte[i] = new int[c.getLong()];
        }

    int **t = new int *[crt.getLong()];
        for (int i = 0; i < crt.getLarg(); i++) {
            t[i] = new int[crt.getLong()];
        }

    int **tab = new int *[map.getLong()];
        for (int i = 0; i < map.getLarg(); i++) {
            tab[i] = new int[map.getLong()];
        }

    c.creerCarte(carte);
    crt.creerCarte(t);
    map.creerCarte(tab);

    while(fin == false){
        if(niveau == 1){
            while(nain.mort() && finNiv == false){
                deplacement(carte,nain);
                rencontre(carte,nain,fin,c,finNiv);
                c.parcour(carte);
            }
            finNiv = false;
            niveau = niveau + 1;
        }
        else if(niveau == 2){
            while(nain.mort() && finNiv == false){
                deplacement(t,nain);
                rencontre(t,nain,fin,crt,finNiv);
                c.parcour(t);
            }
            finNiv = false;
            niveau = niveau + 1;
        }
        else if(niveau == 3){
            while(nain.mort() && finNiv == false){
                deplacement(tab,nain);
                rencontre(tab,nain,fin,map,finNiv);
                c.parcour(tab);
            }
            finNiv = false;
            niveau = niveau + 1;
            fin = true;
            cout << "Félicitation, vous avez atteint la fin du dongeon !!" << endl;
        }
    }

    c.desalloue(carte);
    crt.desalloue(t);
    map.desalloue(tab);

    cout << "Merci d'avoir joué !!" << endl;

    return 0;

}