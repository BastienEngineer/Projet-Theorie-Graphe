#include "Skieur.h"

Skieur::Skieur(std::string nom,std::string mdp):m_nom(nom),m_mdp(mdp)
{

}

std::string Skieur::getNom()
{
    return m_nom;
}

std::string Skieur::getMdp()
{
    return m_mdp;
}

void Skieur::afficher()
{
    std::cout << "Skieur : " << getNom() << std::endl; 
}

std::vector<std::string>Skieur::getParametre()
{
    return m_para;
}

void Skieur::ajouterParametre(std::string pa)
{
    m_para.push_back(pa);
}