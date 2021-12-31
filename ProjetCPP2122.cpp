// ProjetCPP2122.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Menu.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "../ProjetCPP2122/Card.h"
#include "../ProjetCPP2122/Game.h"
#include "Hand.h"
#include <windows.h>
#include <string>
#include <fstream>
#include "../ProjetCPP2122/sqlite3.h"
#include "DB_Controller.h"
#pragma execution_character_set( "utf-8" )
using namespace std;



int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(65001);
	Menu m;
	m.getChoice();
	
}


