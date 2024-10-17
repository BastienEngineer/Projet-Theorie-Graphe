#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED
#include "bib.h"

class Point;
class Trajet;
class Skieur;

class Station /// Graphe
{
private:
    ///Attributs
    std::vector<Point*> m_points;   ///liste des points
    std::vector<Trajet*> m_trajets; ///liste des trajets
    std::vector<std::pair<std::string,std::pair<double,double>>> m_types;
    std::vector<std::pair<std::string,int>> m_capacite;
    int m_ordre;
    int m_taille;
    Skieur *m_s;

public:
    /// Constructeur
    Station(std::string nomFichier);
    ///Destructeur
    ~Station();
    ///Methodes
    void afficher();
    void AlgoT(int t);
    void AlgoP(int p);
    void parcoursBFS(int n0,std::queue<int>& arborescence);
    void parcoursBFS2(int n0,int nS,std::queue<int>& arborescence);
    void Dijkstra(int num_s0,int num_s);
    void Dijkstra2(int num_s0);
    void supprTrajets(std::vector<std::string>ch);
    void afficherSkieur();
    Skieur* creationSkieur(std::ofstream& fichier2);
    void ajoutParam(std::string pa);
    Skieur* rechercheSkieur();
    Skieur* getms();
    bool BFS3(int n0,int nS,std::queue<int>& arborescence, std::vector<int>& pred);
    void FordFulkerson(int source, int puit,std::queue<int>& arborescence, std::vector<int>& pred);
};

#endif // STATION_H_INCLUDED
