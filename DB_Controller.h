#pragma once

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;
//Cette classe permet de g�rer la DB
class DB_Controller {
	sqlite3* DB;
	char* err;
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);//Permet de r�cuperer les resultat d'une requete SQL
	static int callHistory(void* NotUsed, int argc, char** argv, char** azColName);//Permet de r�cuperer les resultat d'une requete SQL
public:
	void createDB(); //cr�er la Base de donn�e
	void createTablePlayer();//cr�er la table Joueur
	void insertDataInPlayer(string data);//Insere des donn�e dans la table Joueur
	void showAllDataPlayer();//Montre tout les joueurs pr�sents dans la table
	void dropPlayer();//Supprime la table Joueur
	int getCagnotte(string data);//Recois la cagnotte d'un joueur souhait�
	int getID(string data);//Recois l'ID d'un joueur souhait�
	void dropJackpot();//supprimer la table Jackpot
	void updateCagnotte(int cagnotte,string name);//Actualise la cagnotte d'un joueur souhait�
	void createTableJackpot();//cr�er la table Jackpot
	void showHistoryJackpot(int IDplayerCurrent);//Montre l'evolution de la cagnotte d'un joueur souhait�
	void insertDataInJackpot(int gameID, int IDJoueur, int Cagnotte);//insert des donn�es dans la table Jackpot
	int getNumberOfGame();//Retourne le nombre de game effectu�
	bool CheckName(string data);//Verifie si le nom d'un joueur se trouve bien dans la table Joueur
};