#ifndef __POINT__
#define __POINT__

class Entite{
    private:
        int x;
        int y;
        int lvl;
    public:
        Entite();
        Entite(int,int,int);
        Entite(const Entite &);
        int getX();
        void setX(int);
        int getY();
        void setY(int);
        void afficher();
        void setLvl(int);
        int getLvl();
};

#endif