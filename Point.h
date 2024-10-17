#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include "bib.h"


class Point /// Sommet
{
private:
    ///Attributs
    int m_num;
    std::string m_lieu;
    int m_altitude;
    std::vector<std::pair<Point*,std::pair<double,int>>> m_sucesseurs;
    Point * m_predecesseurs;
    /// Definir "l'infini" pour la distance
    /// std::numeric_limits<int>::max()
    double m_dist=INT_MAX;
    int m_flot=0;
    int m_capacite;
    bool m_marquage;
public:
    ///Constructeur
    Point(int num,std::string lieu,int altitude);
    ///Methode
    void afficher();
    void ajouterSucc(Point*p,double d,int c);
    void supprSucc(int num);
    ///Getters
    int getNum();
    int getAltitude();
    int getCapacite();
    int getFlot();
    double getdistance();
    std::string getLieu();
    Point *getPredecesseurs(){return m_predecesseurs;}
    bool getMarquage();
    ///Accesseur : pour la liste des successeurs
    std::vector<std::pair<Point*,std::pair<double,int>>>& getSucesseurs() {return m_sucesseurs;}
    ///Setters
    void setPredecesseurs(Point*s);
    void setDuree(double p);
    void setMarquage(bool marquage);
    void setFlot(int f);

};

#endif // POINT_H_INCLUDED
