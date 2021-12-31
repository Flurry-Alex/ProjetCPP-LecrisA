#pragma once
#include "Deck.h"
#include <string>
//Classe qui repr�sente une main d'un joueur
class Hand : public Deck
{
	bool isPlayer;//Repr�sente si c'est un joueur ou un bot
	string username;//Repr�sente le nom d'utilisateur du joueur
	int playerNumber;//repr�sente le num�ro du Joueur
	int credit;//repr�sente la cagnotte
public:

	Hand(int nbCard);//constructeur
	Hand(int playerNb, int credit, bool isBot,string name);//constructeur
	int getPlayerNumber();//Permet d'obtenir le num�ro du joueur
	int getCredit();//Permet d'obtenir la cagnotte du joueur
	void setStart(CardL* card);//Permet de d�finir la premi�re carte du paquet.
	int giveToBank();//Permet de donn� de l'argent a la banque
	string getUsername();//Permet d'obtenir le nom d'utilisateur
	bool getIsPlayer();//Permet de savoir si la main est la main d'un bot ou d'un joueur

};
