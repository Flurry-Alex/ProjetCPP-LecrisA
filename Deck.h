#pragma once
#include <vector>
#include "CardL.h";

#include <iostream>
using namespace std;
//classe qui répresente le paquet initial
class Deck
{
	
public:
	CardL* start;//Représente la carte de début du paquet
	Deck();//Constructeur
	Deck(int nbCard);//Constructeur
	void putBehind(CardL* card);//Permet de mettre une carte à l'arrière du paquet
	CardL* getCardInDeck(int x);//Permet d'obtenir une carte dans le paquet
	void randomMix(int x,int NbPlayer);//Permet de mélanger le paquet
	void addToDeck(CardL* Card);//Permet de mettre une carte dans le paquet
	void showDeck();//Permet d'afficher le paquet
	void showDeckWNumber();//Permet d'afficher le paquet avec une énumération des cartes supplémentaire
	CardL* getLastCard();//Obtenir la dernière carte du paquet
	void setFirstCard(CardL *card);//Permet de définir la première carte du paquet
	int GetLength();//Permet d'obtenir le nombre de carte dans un paquet
	

	


	
};

