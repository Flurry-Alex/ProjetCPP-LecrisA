#pragma once
#include <vector>
#include "CardL.h";

#include <iostream>
using namespace std;
//classe qui r�presente le paquet initial
class Deck
{
	
public:
	CardL* start;//Repr�sente la carte de d�but du paquet
	Deck();//Constructeur
	Deck(int nbCard);//Constructeur
	void putBehind(CardL* card);//Permet de mettre une carte � l'arri�re du paquet
	CardL* getCardInDeck(int x);//Permet d'obtenir une carte dans le paquet
	void randomMix(int x,int NbPlayer);//Permet de m�langer le paquet
	void addToDeck(CardL* Card);//Permet de mettre une carte dans le paquet
	void showDeck();//Permet d'afficher le paquet
	void showDeckWNumber();//Permet d'afficher le paquet avec une �num�ration des cartes suppl�mentaire
	CardL* getLastCard();//Obtenir la derni�re carte du paquet
	void setFirstCard(CardL *card);//Permet de d�finir la premi�re carte du paquet
	int GetLength();//Permet d'obtenir le nombre de carte dans un paquet
	

	


	
};

