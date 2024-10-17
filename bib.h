#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <random>

#include "Point.h"
#include "Trajet.h"
#include "Station.h"
#include "Skieur.h"

class Point;
class Trajet;
class Station;
class Skieur;

int choixMenu();
int RetourMenu();
int choixO();

void menu();
void Retour2Menu();

void AfficherGraphe();
void TrajetT();
void PointP();
void Itineraire();
void DureeP();
void BFS();
void BFS2();
void optimisation();
void optimisationMulti();
void FF();

#endif // BIB_H_INCLUDED
