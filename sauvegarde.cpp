#include "bib.h"

/// 1ere version du ssp optimisation 
void optimisation()
{
    bool remontees = false, niveau = false, bus = false;
    std::string supprRemont={""},couleurPiste={""},busS={""};
    std::cout << " Avez vous peur des remontees mecaniques ? 0 pour non 1 pour oui " << std::endl;
    do{
        std::cin >> remontees;
    }while(remontees!=0 && remontees!=1);

    if(remontees == true)
    {
        std::cout << "De quels remontees mecaniques avez vous peur en particulier ? " << std::endl;
        std::cout << "Ecrivez ci dessous les remontees mecaniques a eviter (TPH pour telepherique, TC pour telecabine, TS pour telesiege, TSD pour telesiege debrayable et TK pour teleski)" << std::endl;
        std::cout << "Exemple si vous souhaitez supprimer les teleskis il faut ecrire : TK" << std::endl;
        do{
            std::cin >> supprRemont;
        }while(supprRemont!="TK" && supprRemont!="TPH" && supprRemont!="TC" && supprRemont!="TS" && supprRemont!="TSD");
    }
    else
    {
        ///Rien a faire
    }

    std::cout << "Souhaitez vous supprimer un niveau (couleur) de piste ? 0 pour non 1 pour oui " << std::endl;
    do{
        std::cin >> niveau;
    }while(niveau!=0 && niveau!=1);

    if(niveau == true)
    {
        std::cout << "Quelle(s) couleur(s) de piste voulez vous supprimer ? " << std::endl;
        std::cout << "Ecrivez ci dessous les couleurs de piste a eviter (V pour vert, B pour bleu, R pour rouge, N pour noir, SURF pour Snowpark, KL pour Piste de kilometre lance)" << std::endl;
        std::cout << "Exemple si vous souhaitez supprimer les pistes vertes il faut ecrire : V" << std::endl;
        do{
            std::cin >> couleurPiste;
        }while(couleurPiste!="V" && couleurPiste!="B" && couleurPiste!="R" && couleurPiste!="N" && couleurPiste!="KL" && couleurPiste!="SURF");
    }
    else
    {
        ///Rien a faire
    }

    std::cout << "Ne souhaitez vous pas prendre le BUS ? 0 pour non 1 pour oui " << std::endl;
    do{
        std::cin >> bus;
    }while(bus!=0 && bus!=1);

    if(bus == true)
    {
        std::cout << "Quel bus voulez vous ne pas prendre ? " << std::endl;
        std::cout << "Ecrivez ci dessous le bus a eviter (BUS pour le bus2000_1600/bus1600_2000 et BUS2 pour le bus1600_1800/bus1800_1600)" << std::endl;
        std::cout << "Exemple si vous souhaitez eviter le bus2000_1600 il faut ecrire : BUS" << std::endl;
        do{
            std::cin >> busS;
        }while(busS!="BUS" && busS!="BUS2");
    }
    else
    {
        ///Rien a faire
    }

    std::cout << std::endl;
    std::cout << "Liste du/des parametre(s) supprime(s)" << std::endl;
    if(supprRemont!="" || couleurPiste!="" || busS!="")
    {
        if(supprRemont!="")
        {
            std::cout << supprRemont << std::endl;
        }
        if(couleurPiste!="")
        {
            std::cout << couleurPiste << std::endl;
        }
        if(busS!="")
        {
            std::cout << busS << std::endl;
        }
    }
    else
    {
        std::cout << "Vous n avez rien supprime" << std::endl;
    }

}