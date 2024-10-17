#include "bib.h"

///Sous programmes de navigation entre les menus
int choixMenu()
{
    int choix;
    std::cout << "OPTIMISATION D UNE STATION DE SKI" << std::endl;
    std::cout << std::endl;
    std::cout << "CHOISSISSEZ UNE OPTION DU MENU" << std::endl;
    std::cout << std::endl;
    std::cout<<"1 CHARGEMENT DU GRAPHE"<< std::endl;
    Sleep(50);
    std::cout<<"2 CHOISIR UN TRAJET POUR CONNAITRE LE POINT DE DEPART ET D ARRIVE"<< std::endl;
    Sleep(50);
    std::cout<<"3 CHOISIR UN POINT POUR CONNAITRE LES TRAJETS"<< std::endl;
    Sleep(50);
    std::cout<<"4 ITINERAIRE LE PLUS RAPIDE EN TEMPS ENTRE 2 POINTS (DIJKSTRA)"<<std::endl;
    Sleep(50);
    std::cout<<"5 AVOIR TOUTES LES DUREES DES AUTRES POINTS A PARTIR D UN POINT DE DEPART (DIJKSTRA)"<<std::endl;
    Sleep(50);
    std::cout<<"6 ITINERAIRE LE PLUS RAPIDE EN ARCS ENTRE 2 POINTS (BFS)"<<std::endl;
    Sleep(50);
    std::cout<<"7 AVOIR LES PLUS COURTS CHEMINS DES AUTRES POINTS A PARTIR D UN POINT DE DEPART (BFS)"<<std::endl;
    Sleep(50);
    std::cout<<"8 OPTIMISATION"<<std::endl;
    Sleep(50);
    std::cout<<"9 TROUVER LE FLOT MAX ENTRE 2 POINTS (FORD FULKERSON)"<<std::endl;
    Sleep(50);
    std::cout<<"10 QUITTER"<<std::endl;
    std::cin >> choix;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    system("cls");
    return choix;
}

int RetourMenu()
{
    int c;
    std::cout<<"1 RETOUR MENU"<< std::endl;
    std::cin >> c;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    system("cls");
    return c;
}

int choixO()
{
    int c2;
    std::cout << "MODULE D OPTIMISATION DES VACANCES AU SKI" << std::endl;
    Sleep(50);
    std::cout<<"1 ITINERAIRE LE PLUS RAPIDE EN TEMPS ENTRE 2 POINTS (DIJKSTRA)"<<std::endl;
    Sleep(50);
    std::cout<<"2 AVOIR TOUTES LES DUREES DES AUTRES POINTS A PARTIR D UN POINT DE DEPART (DIJKSTRA)"<<std::endl;
    Sleep(50);
    std::cout<<"3 ITINERAIRE LE PLUS RAPIDE EN ARCS ENTRE 2 POINTS (BFS)"<<std::endl;
    Sleep(50);
    std::cout<<"4 AVOIR LES PLUS COURTS CHEMINS DES AUTRES POINTS A PARTIR D UN POINT DE DEPART (BFS)"<<std::endl;
    Sleep(50);
    std::cin >> c2;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    system("cls");
    return c2;
}

void menu()
{
    int choix=-1;
	do{choix=choixMenu();}while(choix<1 || choix>10);   ///Menu
	switch (choix)
	{
	    case 1:
        {
            AfficherGraphe();
            Retour2Menu();
		    break;
        }
        case 2:
        {
            TrajetT();
            Retour2Menu();
            break;
        }
        case 3:
        {
            PointP();
            Retour2Menu();
            break;
        }
        case 4:
        {
            Itineraire();
            Retour2Menu();
            break;
        }
        case 5:
        {
            DureeP();
            Retour2Menu();
            break;
        }
        case 6:
        {
            BFS2();
            Retour2Menu();
            break;
        }
        case 7:
        {
            BFS();
            Retour2Menu();
            break;
        }
        case 8:
            optimisationMulti();
            break;

        case 9:
        {
            FF();
            Retour2Menu();
            break;
        }
        case 10:
        {
            system("exit");
            break;
        }
        default: menu();
    }
}

void Retour2Menu()
{
    int c=0;
    system("pause");
    system("cls");
    do{c=RetourMenu();}while(c<1 || c>1);   ///Menu
	switch (c)
	{
	    case 1:
        {
            menu();
		    break;
        }
    }
}
