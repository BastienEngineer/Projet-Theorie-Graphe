#include "Trajet.h"

Trajet::Trajet(int num,std::string trajet,std::string type,Point *depart,Point *arrive,double temps,int capacite,int flot):m_num(num),m_trajet(trajet),m_type(type),m_depart(depart),m_arrive(arrive),m_temps(temps),m_capacite(capacite),m_flot(flot)
{
    ///Rien à faire
}

Point* Trajet::getDepart()
{
    return m_depart;
}

Point* Trajet::getArrive()
{
    return m_arrive;
}

int Trajet::getNum()
{
    return m_num;
}

double Trajet::getTemps()
{
    return m_temps;
}

int Trajet::getFlot()
{
    return m_flot;
}

int Trajet::getCapacite()
{
    return m_capacite;
}

std::string Trajet::getTrajet()
{
    return m_trajet;
}

std::string Trajet::getType()
{
    return m_type;
}

void Trajet::afficher()
{
    std::cout << "    trajet : " << getNum() << "   " << getTrajet() << " Type " << getType() << " Point Depart " << m_depart->getNum()+1 << " Point Arrive " << m_arrive->getNum()+1 << " Duree " << getTemps() << " Capacite " << getCapacite() << " Flot " << getFlot() <<std::endl;
}
