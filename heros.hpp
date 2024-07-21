#ifndef __HEROS__
#define __HEROS__
#include "entite.hpp"

class Heros : public Entite{
    private:
        int pv;
        int pvMax;
        int pa;
        int xp;
        int lvl;
        int luck;
        //Entite *inventaire[];
    public:
        Heros();
        Heros(const Heros &);
        int getPv();
        int getPa();
        int getXp();
        int getLuck();
        int getLvl();
        void restorePv(int);
        void setPv(int);
        void setPa(int);
        void gagneXp(int);
        void lvlUp();
        void ajouteLuck(int);
        void afficher();
        bool mort();
};

#endif