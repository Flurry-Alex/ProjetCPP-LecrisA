#pragma once

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;
//Cette classe permet de gérer la DB
class DB_Controller {
	sqlite3* DB;
	char* err;
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);//Permet de récuperer les resultat d'une requete SQL
	static int callHistory(void* NotUsed, int argc, char** argv, char** azColName);//Permet de récuperer les resultat d'une requete SQL
public:
	void createDB(); //créer la Base de donnée
	void createTablePlayer();//créer la table Joueur
	void insertDataInPlayer(string data);//Insere des donnée dans la table Joueur
	void showAllDataPlayer();//Montre tout les joueurs présents dans la table
	void dropPlayer();//Supprime la table Joueur
	int getCagnotte(string data);//Recois la cagnotte d'un joueur souhaité
	int getID(string data);//Recois l'ID d'un joueur souhaité
	void dropJackpot();//supprimer la table Jackpot
	void updateCagnotte(int cagnotte,string name);//Actualise la cagnotte d'un joueur souhaité
	void createTableJackpot();//créer la table Jackpot
	void showHistoryJackpot(int IDplayerCurrent);//Montre l'evolution de la cagnotte d'un joueur souhaité
	void insertDataInJackpot(int gameID, int IDJoueur, int Cagnotte);//insert des données dans la table Jackpot
	int getNumberOfGame();//Retourne le nombre de game effectué
	bool CheckName(string data);//Verifie si le nom d'un joueur se trouve bien dans la table Joueur
};