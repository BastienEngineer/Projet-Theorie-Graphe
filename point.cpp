#include "Point.h"

Point::Point(int num,std::string lieu,int altitude):m_num(num),m_lieu(lieu),m_altitude(altitude)
{
    ///Rien à faire
}

int Point::getNum()
{
    return m_num;
}

int Point::getAltitude()
{
    return m_altitude;
}

int Point::getCapacite()
{
    return m_capacite;
}

int Point::getFlot()
{
    return m_flot;
}

std::string Point::getLieu()
{
    return m_lieu;
}

void Point::ajouterSucc(Point*p,double d,int c)
{
    m_sucesseurs.push_back(std::make_pair(p,std::make_pair(d,c)));
}

void Point::afficher()
{
    std::cout<<"    point "<<m_num+1<<" : " << "[Lieu " << getLieu() << " Altitude " << getAltitude() << "] ";
    for(auto s : m_sucesseurs)
    {
        std::cout<<s.first->getNum()+1<<"("<<s.second.first<<")" << "{"<<s.second.second<<"} ";
    }
}

void Point::setPredecesseurs(Point *s)
{
    m_predecesseurs=s;
}

double Point::getdistance()
{
    return m_dist;
}

void Point::setDuree(double p)
{
    m_dist=p;
}

bool Point::getMarquage()
{
    return m_marquage;
}

void Point::setMarquage(bool marquage)
{
    m_marquage=marquage;
}

void Point::setFlot(int f)
{
    m_flot=f;
}


///Méthode qui supprime un sucesseur du vecteur de sucesseur en saisissant son numéro
void Point::supprSucc(int num)
{
    for(int i=0;i<getSucesseurs().size();i++)
    {
        if(getSucesseurs()[i].first->getNum()==num)
        {
            getSucesseurs().erase(getSucesseurs().begin()+i);
        }
    }
}


