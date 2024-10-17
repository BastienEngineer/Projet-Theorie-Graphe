#include "bib.h"

void AfficherGraphe()
{
    Station s{"data_arcs.txt"};
    /// afficher le graphe
    s.afficher();
    std::cout << std::endl;
}

///Ce sous programme permet de saisir un numéro de trajet et de connaitre son point de départ et d'arrivée
void TrajetT()
{
    Station s{"data_arcs.txt"};
    int trajet1;
    std::cout << "Choisissez un num trajet " << std::endl;
    do{
        std::cin >> trajet1;
    }while(trajet1<1 || trajet1>97);
    s.AlgoT(trajet1);
    std::cout << std::endl;
}

///Ce sous programme permet de saisir un numéro de point et de connaitre les trajets qui arrivent
///à ce point et les trajets qui partent de ce point
void PointP()
{
    Station s{"data_arcs.txt"};
    int point1;
    std::cout << "Choisissez un num point " << std::endl;
    do{
        std::cin >> point1;
    }while(point1<1 || point1>37);
    int point2=point1-1;
    s.AlgoP(point2);
    std::cout << std::endl;
}

///Sous programme qui applique l'algo de Dijkstra entre 2 points 
void Itineraire()
{
    Station s{"data_arcs.txt"};
    ///saisie du numero du point initial et du point d'arrive
    int depart=0,arrive=0;
    std::cout << "Saisie du numero du point initial : " <<std::endl;
    do{
        std::cin >> depart;
    }while(depart<1 || depart>37);
    std::cout << "Saisie du numero du point d'arrive : " <<std::endl;
    do{
        std::cin >> arrive;
    }while(arrive<1 || arrive>37);
    std::cout << std::endl;
    int depart2=depart-1;
    int arrive2=arrive-1;
    /// Algo de Dijkstra
    s.Dijkstra(depart2,arrive2);
    std::cout << std::endl;
}

///Sous programme qui applique l'algo de Dijkstra à partir d'un sommet de départ
void DureeP()
{
    Station s{"data_arcs.txt"};
    int depart3=0;
    std::cout << "Saisie du numero du point initial : " <<std::endl;
    do{
        std::cin >> depart3;
    }while(depart3<1 || depart3>37);
    int depart4=depart3-1;
    s.Dijkstra2(depart4);
    std::cout << std::endl;
}

///Sous programme qui applique l'algo BFS à partir d'un point de départ
void BFS()
{
    Station s{"data_arcs.txt"};
    ///saisie du numero du point initial pour lancer un BFS
    int departBFS=0;
    std::queue<int> arbreBFS;
    std::cout << "Saisie du numero du point initial pour parcours BFS : " <<std::endl;
    do{
        std::cin >> departBFS;
    }while(departBFS<1 || departBFS>37);
    std::cout << std::endl;
    int departBFS2=departBFS-1;
    s.parcoursBFS(departBFS2,arbreBFS);
    std::cout << std::endl;
}

///Sous programme qui applique l'algo BFS entre 2 points
void BFS2()
{
    Station s{"data_arcs.txt"};
    ///saisie du numéro du point initial pour lancer un BFS
    int departBFS=0,arriveBFS=0;
    std::queue<int> arbreBFS;
    std::cout << "Saisie du numero du point initial pour parcours BFS : " <<std::endl;
    do{
        std::cin >> departBFS;
    }while(departBFS<1 || departBFS>37);
    std::cout << std::endl;
    std::cout <<std::endl<< "Saisie du numero du point arrive pour parcours BFS : " <<std::endl;
    do{
        std::cin >> arriveBFS;
    }while(arriveBFS<1 || arriveBFS>37);
    std::cout << std::endl;
    int departBFS2=departBFS-1;
    int arriveBFS2=arriveBFS-1;
    s.parcoursBFS2(departBFS2,arriveBFS2,arbreBFS);
    std::cout << std::endl;
}

///Sous programme qui permet aux skieurs de saisir leurs propres paramètres afin de profiter au maximum
///de leurs vacances au ski
///Avec cette borne intéractive, ils peuvent choisir de supprimer des remontées mécaniques qu'ils
///n'apprécient pas, de décider s'ils ont envie de prendre le bus et de choisir les pistes qu'ils 
///souhaitent descendre en particulier
///Pour chaque skieur, celui ci à la possibilité de se connecter à son compte en entrant son nom et
///son mdp ainsi il peut récupérer ses paramètres personnels. S'il n'a pas de compte il peut en créer
///un et configurer ses paramètres
///Enfin une fois ses paramètres saisis, il peut choisir d'optimiser son séjour selon ses envies
void optimisationMulti()
{
    int nbPara=0;   ///Initialisation du nombre de paramètres sélectionnées
    Station s2{"data_arcs.txt"};
    std::ofstream fichier2("sauvegarde.txt",std::ios::app);
    bool compte=false;
    std::cout << "AVEZ VOUS UN COMPTE SKIEUR ? TAPPEZ 0 POUR EN CREER UN SINON TAPPEZ 1 POUR SE CONNECTER" << std::endl;
    do{
        std::cin >> compte;
    }while(compte!=0 && compte!=1);
    system("cls");
    ///Si le skieur n'a pas de compte il faut qu'il choisisse ses préférencesi
    if(compte==false)
    {
    s2.creationSkieur(fichier2);    ///On crée un compte et on le sauvegarde dans le txt
    s2.afficherSkieur();
    ///On initialise des booléens pour savoir si le skieur veut supprimer un certain type de paramètre
    bool remontees = false, niveau = false, bus = false;
    bool remontees2 = false, niveau2 = false, bus2 = false;
    bool choix;
    ///Chaines de caractères pour recevoir la sélection des paramètres
    std::string a,b,c;
    ///Vecteur contenant les différents paramètres sélectionnés
    std::vector <std::string> suppRemont;
    std::vector <std::string> couleurPiste;
    std::vector <std::string> busS;
    std::cout << "Avez vous peur des remontees mecaniques ? 0 pour non 1 pour oui " << std::endl;
    do{
        std::cin >> remontees;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(remontees!=0 && remontees!=1);

    if(remontees == true)
    {
        std::cout << "De quels remontees mecaniques avez vous peur en particulier ? " << std::endl;
        std::cout << "Ecrivez ci dessous les remontees mecaniques a eviter (TPH pour telepherique, TC pour telecabine, TS pour telesiege, TSD pour telesiege debrayable et TK pour teleski)" << std::endl;
        std::cout << "Exemple si vous souhaitez supprimer les teleskis il faut ecrire : TK" << std::endl;
        while(remontees2!=true)
        {
            do{
            std::cin >> a;
            }while(a!="TK" && a!="TPH" && a!="TC" && a!="TS" && a!="TSD");
            fichier2<<a<< " ";  ///On écrit dans le fichier le paramètre (sur la même ligne que le nom et mdp)
            suppRemont.push_back(a);
            nbPara++;
            std::cout << "Voulez continuez la suppression ? Tapez 0 pour non et 1 pour oui" << std::endl;
            do{
            std::cin >> choix;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }while(choix!=0 && choix!=1);
            if(choix==0)
            {
                remontees2=true;
            }
            else
            {
                std::cout << "Saisir la nouvelle suppression" << std::endl;
            }
        }
    }
    else
    {
        ///Rien à faire
    }

    std::cout << "Souhaitez vous supprimer un niveau (couleur) de piste ? 0 pour non 1 pour oui " << std::endl;
    do{
        std::cin >> niveau;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(niveau!=0 && niveau!=1);

    if(niveau == true)
    {
        std::cout << "Quelle(s) couleur(s) de piste voulez vous supprimer ? " << std::endl;
        std::cout << "Ecrivez ci dessous les couleurs de piste a eviter (V pour vert, B pour bleu, R pour rouge, N pour noir, SURF pour Snowpark, KL pour Piste de kilometre lance)" << std::endl;
        std::cout << "Exemple si vous souhaitez supprimer les pistes vertes il faut ecrire : V" << std::endl;
        while(niveau2!=true)
        {
            do{
            std::cin >> b;
            }while(b!="V" && b!="B" && b!="R" && b!="N" && b!="KL" && b!="SURF");
            fichier2<<b<< " ";
            couleurPiste.push_back(b);
            nbPara++;
            std::cout << "Voulez continuez la suppression ? Tapez 0 pour non et 1 pour oui" << std::endl;
            do{
            std::cin >> choix;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }while(choix!=0 && choix!=1);
            if(choix==0)
            {
                niveau2=true;
            }
            else
            {
                std::cout << "Saisir la nouvelle suppression" << std::endl;
            }
        }
    }
    else
    {
        ///Rien a faire
    }

    std::cout << "Ne souhaitez vous pas prendre le BUS ? 0 pour non 1 pour oui " << std::endl;
    do{
        std::cin >> bus;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(bus!=0 && bus!=1);

    if(bus == true)
    {
        std::cout << "Quel bus voulez vous ne pas prendre ? " << std::endl;
        std::cout << "Ecrivez ci dessous le bus a eviter (BUS26 pour le bus2000_1600, BUS62 pour le bus1600_2000, BUS68 pour le bus1600_1800 et BUS86 pour le bus1800_1600)" << std::endl;
        std::cout << "Exemple si vous souhaitez eviter le bus2000_1600 il faut ecrire : BUS26" << std::endl;
        while(bus2!=true)
        {
            do{
            std::cin >> c;
            }while(c!="BUS26" && c!="BUS62" && c!="BUS68" && c!="BUS86");
            fichier2<<c<< " ";
            busS.push_back(c);
            nbPara++;
            std::cout << "Voulez continuez la suppression ? Tapez 0 pour non et 1 pour oui" << std::endl;
            do{
            std::cin >> choix;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }while(choix!=0 && choix!=1);
            if(choix==0)
            {
                bus2=true;
            }
            else
            {
                std::cout << "Saisir la nouvelle suppression" << std::endl;
            }
        }
    }
    else
    {
        ///Rien a faire
    }
    ///On remplit la fin de la ligne dans le fichier avec des 0
    ///Cela permet de lire le fichier plus facilement lors du chargement (toutes les lignes ont le même nombre de chaines)
    for(int i=0;i<14-nbPara;i++)
    {
        fichier2<<"0"<< " ";
    }
    ///On saute une ligne dans le fichier pour passer à la personne suivante
    fichier2<<std::endl;
    fichier2.close();
    std::cout << std::endl;
    ///On affiche les paramètres sélectionnés
    std::cout << "Liste du/des parametre(s) supprime(s)" << std::endl;
    if(!suppRemont.empty() || !couleurPiste.empty() || !busS.empty())
    {
        if(!suppRemont.empty())
        {
            for(auto e : suppRemont)
            {
                std::cout << e << std::endl;
            }
        }
        if(!couleurPiste.empty())
        {
            for(auto e : couleurPiste)
            {
                std::cout << e << std::endl;
            }
        }
        if(!busS.empty())
        {
            for(auto e : busS)
            {
                std::cout << e << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Vous n avez rien supprime" << std::endl;
    }
    system("pause");
    system("cls");
    ///Enfin on appelle les méthodes de la classe station pour supprimer les trajets ainsi que les sucesseurs des points concernés
    s2.supprTrajets(suppRemont);
    s2.supprTrajets(couleurPiste);
    s2.supprTrajets(busS);
    s2.afficherSkieur();
    s2.afficher();
    std::cout << std::endl;
}
///Si le skieur a un compte 
else
{
    s2.rechercheSkieur();   ///on charge son compte et ses paramètres
    s2.supprTrajets(s2.getms()->getParametre());
    system("cls");
    s2.afficherSkieur();
    s2.afficher();
    std::cout << std::endl;
}
///Une fois le graphe modifié le skieur peut décider de connaitre le plus court chemin en temps entre 2
///points, le plus court chemin en correspondance entre 2 points, le plus court chemin en temps à
///partir d'un point initial et le plus court chemin en correspondance à partir d'un point initial
    int choix2=-1;
    do{choix2=choixO();}while(choix2<1 || choix2>4);   ///Menu
	switch (choix2)
	{
	    case 1:
        {
            ///saisie du numero du point initial et du point d'arrive
            int depart=0,arrive=0;
            std::cout << "Saisie du numero du point initial : " <<std::endl;
            do{
            std::cin >> depart;
            }while(depart<1 || depart>37);
            std::cout << "Saisie du numero du point d'arrive : " <<std::endl;
            do{
            std::cin >> arrive;
            }while(arrive<1 || arrive>37);
            std::cout << std::endl;
            int depart2=depart-1;
            int arrive2=arrive-1;
            /// Algo de Dijkstra
            s2.Dijkstra(depart2,arrive2);
            std::cout << std::endl;
		    break;
        }
        case 2:
        {
            int depart3=0;
            std::cout << "Saisie du numero du point initial : " <<std::endl;
            do{
            std::cin >> depart3;
            }while(depart3<1 || depart3>37);
            int depart4=depart3-1;
            s2.Dijkstra2(depart4);
            std::cout << std::endl;
            break;
        }
        case 3:
        {
            ///saisie du numero du point initial pour lancer un BFS
            int departBFS=0,arriveBFS=0;
            std::queue<int> arbreBFS;
            std::cout << "Saisie du numero du point initial pour parcours BFS : " <<std::endl;
            do{
                std::cin >> departBFS;
            }while(departBFS<1 || departBFS>37);
            std::cout << std::endl;
            std::cout <<std::endl<< "Saisie du numero du point arrive pour parcours BFS : " <<std::endl;
            do{
                std::cin >> arriveBFS;
            }while(arriveBFS<1 || arriveBFS>37);
            std::cout << std::endl;
            int departBFS2=departBFS-1;
            int arriveBFS2=arriveBFS-1;
            s2.parcoursBFS2(departBFS2,arriveBFS2,arbreBFS);
            std::cout << std::endl;
            break;
        }
        case 4:
        {
            ///saisie du numero du point initial pour lancer un BFS
            int departBFS=0;
            std::queue<int> arbreBFS;
            std::cout << "Saisie du numero du point initial pour parcours BFS : " <<std::endl;
            do{
                std::cin >> departBFS;
            }while(departBFS<1 || departBFS>37);
            std::cout << std::endl;
            int departBFS2=departBFS-1;
            s2.parcoursBFS(departBFS2,arbreBFS);
            std::cout << std::endl;
            break;
        }
    }
    Retour2Menu();
}

void FF()
{
    Station s{"data_arcs.txt"};
    ///saisie du numéro du point initial pour lancer un BFS
    int departBFS=0,arriveBFS=0;
    std::queue<int> arbreBFS;
    std::vector<int> pred1;
    std::cout << "Saisie du numero du point initial pour Ford Fulkerson : " <<std::endl;
    do{
        std::cin >> departBFS;
    }while(departBFS<1 || departBFS>37);
    std::cout << std::endl;
    std::cout <<std::endl<< "Saisie du numero du point arrive pour Ford Fulkerson : " <<std::endl;
    do{
        std::cin >> arriveBFS;
    }while(arriveBFS<1 || arriveBFS>37);
    std::cout << std::endl;
    int departBFS2=departBFS-1;
    int arriveBFS2=arriveBFS-1;
    /// Algo de FordFulkerson
    //s.FordFulkerson(departBFS2,arriveBFS2,arbreBFS,pred1);
    std::cout << std::endl;
}