#pragma once
#include "Deck.h"
#include <string>
//Classe qui représente une main d'un joueur
class Hand : public Deck
{
	bool isPlayer;//Représente si c'est un joueur ou un bot
	string username;//Représente le nom d'utilisateur du joueur
	int playerNumber;//représente le numéro du Joueur
	int credit;//représente la cagnotte
public:

	Hand(int nbCard);//constructeur
	Hand(int playerNb, int credit, bool isBot,string name);//constructeur
	int getPlayerNumber();//Permet d'obtenir le numéro du joueur
	int getCredit();//Permet d'obtenir la cagnotte du joueur
	void setStart(CardL* card);//Permet de définir la première carte du paquet.
	int giveToBank();//Permet de donné de l'argent a la banque
	string getUsername();//Permet d'obtenir le nom d'utilisateur
	bool getIsPlayer();//Permet de savoir si la main est la main d'un bot ou d'un joueur

};
