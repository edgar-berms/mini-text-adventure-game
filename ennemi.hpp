#ifndef __ENNEMI__
#define __ENNEMI__
#include "entite.hpp"

class Ennemi : public Entite{
    private:
        int pv;
        int pa;
    public:
        Ennemi();
        Ennemi(const Ennemi &);
        int getPv();
        int getPa();
        bool mort();
        void setPv(int);
        void setPa(int);
        void afficher();
};

#endif