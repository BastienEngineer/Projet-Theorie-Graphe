#include "Station.h"

Station::Station(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    ///On récupère l'ordre du graphe
    ifs >> m_ordre;
    if (ifs.fail())
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int num;
    std::string lieu;
    int altitude;
    for (int i=0; i<m_ordre; ++i)
    {
        ifs>>num>>lieu>>altitude;
        m_points.push_back( new Point{i,lieu,altitude} );
    }
    int transport;
    std::string piste;
    double facteur;
    int proport,tpsfixe,s1,s2,capacite,flot;
    double coeff;
    ///On récupère les informations complémentaires du graphe
    ifs>>transport;
    if (ifs.fail())
        throw std::runtime_error("Probleme lecture transport");
    for(int i=0; i<transport; ++i)
    {
        ifs>>piste>>facteur>>proport>>tpsfixe>>s1>>s2>>capacite;
        if(ifs.fail())
            throw std::runtime_error("Probleme piste facteur proport tps fixe s1 s2 et capacite");
        coeff=(facteur/proport);
        m_types.push_back(std::make_pair(piste,std::make_pair(coeff,tpsfixe)));
        m_capacite.push_back(std::make_pair(piste,capacite));
    }
    ///On récupère la taille du graphe
    ifs>>m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int numT,num1,num2,c;
    double denivele,duree;
    std::string trajet,type;
    for (int i=0; i<m_taille; ++i)
    {
        ifs>>numT>>trajet>>type>>num1>>num2>>denivele;
        if (ifs.fail())
            throw std::runtime_error("Probleme lecture arc");
        for(auto e : m_types)
        {
            flot=0;
            if( e.first == type)
            {
                duree = (e.second.first*denivele) + e.second.second;    ///calcul de la durée
                break;
            }
            else
            {
                ///Rien à faire
            }

        }
        for(auto a : m_capacite)
        {
            if(a.first == type)
            {
                c=a.second;
            }
        }
        m_trajets.push_back( new Trajet(numT,trajet,type,m_points[num1-1],m_points[num2-1],duree,c,flot));
        m_points[num1-1]->ajouterSucc(m_points[num2-1],duree,c);
    }
}

Station::~Station()
{
    for (auto p : m_points)
        delete p;
}

void Station::afficher()
{
    std::cout << "Graphe ";
    std::cout << "Ordre = " << m_points.size() << std::endl << "  ";
    std::cout << "Listes d'adjacence :" << std::endl;
    for(auto p : m_points)
    {
        p->afficher();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Taille = " << m_trajets.size() << std::endl;
    std::cout << "Liste des trajets : " << std::endl;
    for(auto a : m_trajets)
    {
        a->afficher();
    }
}

///Méthode qui permet de saisir un numéro de trajet et de connaitre son point de départ et d'arrivée
void Station::AlgoT(int t)
{
    for(auto a : m_trajets)
    {
        if(a->getNum() == t)
        {
            std::cout << "Point Depart " << a->getDepart()->getNum()+1 << " Point Arrive " << a->getArrive()->getNum()+1 << std::endl;
        }
    }
}

///Méthode qui permet de saisir un numéro de point et de connaitre les trajets qui arrivent à ce
///à cpoint et les trajets qui partent de ce point
void Station::AlgoP(int p)
{
    Point *a=m_points[p];
    for(auto i : m_trajets)
    {
        if(i->getDepart() == a || i->getArrive() == a)
            i->afficher();
    }
}

///Méthode de parcours BFS à partir d'un point de départ
///On prend en paramètre le numéro du premier point et une file pour stocker les numéros des points
///visités et pouvoir faire l'arborescence du parcours
void Station::parcoursBFS(int n0,std::queue<int>& arborescence)
{
    /// Initialisation (travaille sur ces points)
    Point *p=m_points[n0]; ///point départ que l'on traite

    ///On déclare une file d'attente
    std::queue<Point*> file;
    for(auto i : m_points)
    {
        i->setMarquage(0);
    }
    ///On enfile et on marque le point de départ n0
    file.push(p);
    p->setMarquage(1);

    ///On déclare un entier pour récupérer le numéro du premier élément de la file
    int num=0;

    if(p->getSucesseurs().empty())
    {
        std::cout << "Le point de depart est isole" << std::endl;
    }

    ///Boucle de parcours
    do
    {
        ///On récupère le numéro du prochain point de la file et on le retire de la file
        num=file.front()->getNum();
        file.pop();
        arborescence.push(num+1);
        ///Parcourir les successeurs du point défilé
        p=m_points[num];
        for(auto a : p->getSucesseurs())
        {
            if(a.first->getMarquage()==0)
            {
                a.first->setMarquage(1);
                file.push(a.first);
                a.first->setPredecesseurs(p);
            }
        }
    }
    while(!file.empty()); ///on effectue ces étapes tant que la file n'est pas vide

    std::cout << "Ordre de decouverte des points avec parcours BFS a partir du point " << n0+1 << std::endl;
    std::cout << n0+1;     ///on effectue ceci pour des contraintes graphiques
    arborescence.pop();             ///liés à l'affichage de l'arborescence du parcours
    ///On affiche l'arborescence de la recherche BFS
    while(!arborescence.empty())
    {
        std::cout << " --> " << arborescence.front();
        arborescence.pop();
    }

}
///Méthode de parcours BFS entre 2 points
///On prend en paramètre le numéro du premier point et une file pour stocker les numéros des points
///visités et pouvoir faire l'arborescence du parcours
void Station::parcoursBFS2(int n0,int nS,std::queue<int>& arborescence)
{
    /// Initialisation (travaille sur ces points)
    Point *p=m_points[n0]; ///point départ que l'on traite
    Point *actuel=m_points[nS]; /// point arrivé -> utile pour l'affichage
    bool sortie=false;

    ///On déclare une file d'attente
    std::queue<Point*> file;
    for(auto i : m_points)
    {
        i->setMarquage(0);
    }
    ///On enfile et on marque le point de départ n0
    file.push(p);
    p->setMarquage(1);

    ///On déclare un entier pour récupérer le numéro du premier élément de la file
    int num=0;

    ///Boucle de parcours
    do
    {
        ///On récupère le numéro du prochain point de la file et on le retire de la file
        num=file.front()->getNum();
        file.pop();
        arborescence.push(num+1);
        ///Parcourir les successeurs du point défilé
        p=m_points[num];
        if(p->getNum()==nS)
        {
            sortie=true;
        }
        else
        {

        }

        if(p->getSucesseurs().empty() && p->getNum()!=nS)
        {

        }
        else
        {
            for(auto a : p->getSucesseurs())
            {
                if(a.first->getMarquage()==0)
                {
                    a.first->setMarquage(1);
                    file.push(a.first);
                    a.first->setPredecesseurs(p);
                }
            }
        }
    }while(!file.empty()); ///on effectue ces étapes tant que la file n'est pas vide

    if(sortie==true)
    {
        std::cout<<"Le plus court chemin en arc est : "<<std::endl;
        while(actuel!=m_points[n0]) /// Parcours des numéros des points (predecesseurs)
        {
            std::cout<<actuel->getNum()+1;
            actuel=actuel->getPredecesseurs();
            std::cout<<" <- ";
        }
        std::cout<<m_points[n0]->getNum()+1<<std::endl;
    }
    else
    {
        std::cout << "Erreur absence de chemin" << std::endl;
    }
}

/// Algo de Dijkstra entre 2 points
typedef std::pair<Point*,double>p; /// attribue p au std::pair existant
void Station::Dijkstra(int num_s0,int num_s)
{
    /// Initialisation (travaille sur ces points)
    Point *s=m_points[num_s0]; ///point départ que l'on traite
    Point *actuel=m_points[num_s]; /// point arrivé -> utile pour l'affichage

    bool sortie=false;
    ///Crée une file de priorité
    std::priority_queue<p,std::vector<p>,std::greater<p>>file;  /// std::greater est utilisé comme objet de la fonction comparateur pour la file d'attente
    /// cela trie dans l'ordre croissant

    file.push(std::make_pair(m_points[num_s0],0)); /// Initialise la file d'attente prioritaire avec le numéro du point de depart
    s->setDuree(0); /// point de départ à une distance nulle (initialisation)

    /// Boucle de recherche
        while(!file.empty()) /// Tant que la file n'est pas vide
        {
            s=file.top().first; /// obtient le numéro du point le plus proche
            file.pop();
            if(s->getNum()==num_s)
            {
                sortie=true;
            }
            else
            {

            }
            if(s->getSucesseurs().empty() && s->getNum()!=num_s)
            {

            }
            else
            {
                for (auto i : s->getSucesseurs())
                {
                    double dist;
                    dist=s->getdistance()+i.second.first;
                    if(dist<i.first->getdistance()) /// Si la distance entre le point de départ et le nouveau point est inférieure à la distance actuelle
                    {
                        i.first->setDuree(dist); /// Modifie la nouvelle distance (longueur)
                        i.first->setPredecesseurs(s);
                        file.push(std::make_pair(i.first,dist));
                    }
                }
            }

        }
    /// Affichage du chemin de l'arrivé au point de départ
    if(sortie==true)
    {
        std::cout<<"Le trajet parcouru est : "<<std::endl;
        while(actuel!=m_points[num_s0]) /// Parcours des numéros des points (predecesseurs)
        {
            std::cout<<actuel->getNum()+1;
            actuel=actuel->getPredecesseurs();
            std::cout<<" <- ";
        }
        std::cout<<m_points[num_s0]->getNum()+1<<std::endl;
        std::cout<<"\nLa duree la plus courte (en min) est : ";
        std::cout<<m_points[num_s]->getdistance() << std::endl;
    }
    else
    {
        std::cout << "Pas de chemin trouve" << std::endl;
    }


}

/// Algo de Dijkstra2 à partir d'un point de départ
typedef std::pair<Point*,double>p; /// attribue p au std::pair existant
void Station::Dijkstra2(int num_s0)
{
    /// Initialisation (travaille sur ces points)
    Point *s=m_points[num_s0]; ///point départ que l'on traite

    ///Crée une file de priorité
    std::priority_queue<p,std::vector<p>,std::greater<p>>file;  /// std::greater est utilisé comme objet de la fonction comparateur pour la file d'attente
    /// cela trie dans l'ordre croissant

    file.push(std::make_pair(m_points[num_s0],0)); /// Initialise la file d'attente prioritaire avec le numéro du point de depart
    s->setDuree(0); /// point de départ à une distance nulle (initialisation)

    if(s->getSucesseurs().empty())
    {
        std::cout << "Le point de depart est isole" << std::endl;
    }

    /// Boucle de recherche
        while(!file.empty()) /// Tant que la file n'est pas vide
        {
            s=file.top().first; /// obtient le numéro du point le plus proche
            file.pop();
            for (auto i : s->getSucesseurs())
            {
                    double dist;
                    dist=s->getdistance()+i.second.first;
                    if(dist<i.first->getdistance()) /// Si la distance entre le point de départ et le nouveau point est inférieure à la distance actuelle
                    {
                        i.first->setDuree(dist); /// Modifie la nouvelle distance (longueur)
                        i.first->setPredecesseurs(s);
                        file.push(std::make_pair(i.first,dist));
                    }
            }
        }
    /// Affichage
        for(auto a : m_points)
            std::cout<<m_points[num_s0]->getNum()+1<<" - "<< a->getNum()+1 << " duree : " << a->getdistance() <<std::endl;
}

///Méthode qui supprime les trajets et les sucesseurs du point de départ des trajets
///Elle est utilisée lors de la suppression des trajets en fonction des paramètres du skieur
///Le vecteur passé en paramètre de la méthode est le vecteur de paramètres du skieur
///Les paramètres représentent le type (attribut de la classe trajet, ex : TC (télcabine))
void Station::supprTrajets(std::vector<std::string>ch)
{
    for(int i=0;i<ch.size();i++)
    {
        for(int j=0;j<m_trajets.size();j++)
        {
            if(m_trajets[j]->getType()==ch[i])
            {
                ///On supprime le sucesseur du point de départ (car il n'y a plus de trajet)
                m_trajets[j]->getDepart()->supprSucc(m_trajets[j]->getArrive()->getNum());
                m_trajets.erase(m_trajets.begin()+j);   ///Suppression du trajet
            }
        }
    }
}

///Création d'un nouveau skieur et enregistrement dans le fichier
Skieur* Station::creationSkieur(std::ofstream& fichier2)
{
    std::string pseudo,mdp;
    std::cout<<"CREATION D UN SKIEUR"<<std::endl;
    std::cout<<"Entrez votre nom : "<<std::endl;
    std::cin >> pseudo;
    std::cout<<"Entrez un mot de passe pour la creation d un compte : "<<std::endl;
    std::cin >> mdp;
    Skieur *s=new Skieur(pseudo,mdp);
    m_s=s;
    if(!fichier2.is_open())
    {
        std::cout << "Erreur d ouverture du fichier" << std::endl;
    }
    else
    {
        fichier2 << m_s->getNom() << " " << m_s->getMdp() << " ";
    }
    system("cls");
    return m_s;
}

void Station::ajoutParam(std::string pa)
{
    m_s->ajouterParametre(pa);
}

///Chargement d'un skieur enregistré
Skieur* Station::rechercheSkieur()
{
    bool trouver=false;
    while(trouver==false)
    {
        std::ifstream ifs("sauvegarde.txt");
        if (!ifs)
            throw std::runtime_error( "Impossible d'ouvrir en lecture ");
        std::string nom,mdp,mdp2,pseudo,p1;
        std::cout << "Saisir votre nom du skieur" << std::endl;
        std::cin >> pseudo;
        std::cout << "Saisir votre mdp" << std::endl;
        std::cin >> mdp2;
        while(!ifs.eof())
        {
            ifs>>nom>>mdp;
            if(nom==pseudo && mdp==mdp2)
            {
                trouver=true;
                Skieur *s1=new Skieur(nom,mdp);
                m_s=s1;
                for(int i=0;i<14;i++)
                {
                    ifs>>p1;
                    if(p1=="0")
                    {
                        break;
                    }
                    else
                    {
                        ajoutParam(p1);
                    }
                }
            }
            else
            {

            }
        }
        if(trouver==false)
        {
            std::cout << "Skieur non trouve" << std::endl;
        }
        ifs.close();
        system("pause");
        system("cls");
    }
    return m_s;
}

void Station::afficherSkieur()
{
    m_s->afficher();
}

Skieur* Station::getms()
{
    return m_s;
}

bool Station::BFS3(int n0,int nS,std::queue<int>& arborescence, std::vector<int>& pred)
{
    /// Initialisation (travaille sur ces points)
    Point *p=m_points[n0]; ///point départ que l'on traite

    ///On déclare une file d'attente
    std::queue<Point*> file;
    for(auto i : m_points)
    {
        i->setMarquage(false);
    }
    ///On enfile et on marque le point de départ n0
    file.push(p);
    p->setMarquage(true);

    ///On déclare un entier pour récupérer le numéro du premier élément de la file
    int num=0;

    ///Boucle de parcours
    do
    {
        ///On récupère le numéro du prochain point de la file et on le retire de la file
        num=file.front()->getNum();
        file.pop();
        arborescence.push(num+1);
        ///Parcourir les successeurs du point défilé
        p=m_points[num];
            for(auto a : p->getSucesseurs())
            {
                int c=a.second.second-a.first->getFlot();
                if(a.first->getMarquage()==false && c > 0)
                {
                    a.first->setMarquage(true);
                    file.push(a.first);
                    a.first->setPredecesseurs(p);
                    //pred[a.first->getNum()]=num;
                }
            }
    }while(!file.empty()); ///on effectue ces étapes tant que la file n'est pas vide
    if(m_points[nS]->getMarquage()==true) /// Si les points sont marques (visite)
    {
        return true;
    }
    else
    {
        return false; /// retourne un booleen pour  FordFulkerson
    }
}
void Station::FordFulkerson(int source, int puit,std::queue<int>& arborescence, std::vector<int>& pred)
{
    Point *s=m_points[source]; ///point source
    Point *p=m_points[puit]; ///point puit
    //s->setFlot(0);
    int maxf=0; /// MaxFlux
    int u,v;
    while(BFS3(s->getNum(),p->getNum(),arborescence,pred))
    {
        for(auto a : s->getSucesseurs())
        {
            int fl=a.second.second-a.first->getFlot();
            int c=INT_MAX; /// Capacite Max
            v=puit;
            //for(w=a.first->getNum(); w!=a.first->getNum(); a.first->setPredecesseurs(p))
            while(v!=source)
            {
                a.first->setPredecesseurs(s);
                c=std::min(fl,c); /// return le minimum entre l'infini ou la diff entre la capacite et le flux
                a.first->setPredecesseurs(p);
                //v=pred[a.first->getNum()];
            }
            v=puit;
            while(v!=source)
            {
                a.first->setPredecesseurs(s);
                fl-=c;
                fl+=c;
                a.first->setPredecesseurs(p);
                //v=pred[a.first->getNum()];
                //a.first->setFlot(a.first->getFlot()+c);
            }
            maxf+=fl;
        }
    }
    /// Affiche le flot (flux) maximimum
    std::cout << " Le flot max est " << maxf << std::endl;
}
