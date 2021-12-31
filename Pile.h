#pragma once
#include "Deck.h"
#include "cardColorEnum.h"
//Classe qui sert a faire les piles présente sur le plateaux
class Pile : public Deck
{
	cardColorEnum colorValue;//représente la couleur de la pile
public:
	Pile(int nbCard);//constructeur
	Pile(cardColorEnum colorValue);//costructeur
	bool blank = true;//Permet de savoir si la pile est vide.
	cardColorEnum getColor();//Permte de savoir la couleur de la Pile
	
};

