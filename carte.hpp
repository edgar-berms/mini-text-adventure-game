#ifndef __CARTE__
#define __CARTE__

/*

0 : case vide
1 : mur
2 : Ennemi
3 : item
4 : Heros
5 : sortie

*/

class Carte{
    private:
        int tailleLarg;
        int tailleLong;
        int lvl;
    public:
        Carte();
        Carte(int);
        Carte(const Carte &);
        ~Carte();
        int getLong();
        int getLarg();
        int getLvl();
        void setLvl(int);
        void creerCarte(int **);
        void parcour(int **);
        void desalloue(int **);
};

#endif