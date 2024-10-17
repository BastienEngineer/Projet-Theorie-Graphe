#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED
#include "bib.h"

class Point;

class Trajet /// Arete
{
private:
    ///Attributs
    int m_num;
    std::string m_trajet;
    std::string m_type;
    Point *m_depart;
    Point *m_arrive;
    double m_temps;
    int m_capacite;
    int m_flot;

public:
    ///Constructeur
    Trajet(int num,std::string trajet,std::string type,Point *depart,Point *arrive,double temps,int capacite,int flot);
    ///Getters
    int getNum();
    double getTemps();
    int getFlot();
    int getCapacite();
    std::string getTrajet();
    std::string getType();
    Point *getDepart();
    Point *getArrive();
    ///Methode
    void afficher();
};

#endif // TRAJET_H_INCLUDED
