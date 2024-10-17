#ifndef SKIEUR_H_INCLUDED
#define SKIEUR_H_INCLUDED
#include "bib.h"


class Skieur
{
private:
    ///Attributs
    std::string m_nom;
    std::string m_mdp;
    ///vecteur qui contient les paramètres personnels du skieur
    std::vector<std::string> m_para;
public:
    ///Constructeur
    Skieur(std::string nom,std::string mdp);
    ///Methode
    void afficher();
    void ajouterParametre(std::string pa);
    ///Getters
    std::string getNom();
    std::string getMdp();
    std::vector<std::string> getParametre();
};

#endif // SKIEUR_H_INCLUDED
