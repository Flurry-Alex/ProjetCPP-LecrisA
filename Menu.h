#pragma once

#include <iostream>
#include "DB_Controller.h"
#include <fstream>
#include "Game.h"
//Cette classe permet d'afficher un menu qui permet de gerer la Base de donnée et de lancer une partie
class Menu {
	DB_Controller DB;
	int getSetting(int& nbCard, int& difficulty);//Permet de récuperer le nombre de cartes et la difficulté de mélange dans le fichier Settings.txt
	
public:
	void getChoice();//Affiche le menu
	void getHistory();//Affiche l'evolution de la cagnotte du joueur que l'on souhaite
	void getChoiceResults();//Permet de choisir l'option du menu qu'on souhaite
	void addPlayerInDB();//Permet d'ajouter des Joueurs dans la db
	void showDBPlayer();//Permet d'afficher tout les joueurs dans la DB
	void startGame();//Permet de lancer la DB
	void resetgame();//Permet de reinitialiser la DB
	int getNbPlayer();//Permet d'obtenir le nombre de joueur qui va jouer
	
};

