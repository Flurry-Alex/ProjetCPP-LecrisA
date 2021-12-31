#pragma once
#include "../ProjetCPP2122/cardColorEnum.h"
#include "../ProjetCPP2122/cardValueEnum.h"
#include <string>


class Card {
protected:
	cardValueEnum cardValue;//represente la valeur de la carte
	cardColorEnum cardColor;//represente la couleur de la carte

public:

	Card();//Constructeur
	Card(cardColorEnum cardColor, cardValueEnum cardValue);//Constructeur
	cardColorEnum* getColor();//permet d'obtenir la couleur de la carte
	cardValueEnum* getValue();//permet d'obtenir la valeur de la carte

	void setColor(cardColorEnum cardColor);//Permet de définir la couleur de la carte
	void setValue(cardValueEnum cardValue);//Permet de définir la valeur de la carte
	void showCard();//Permet d'afficher la carte
};