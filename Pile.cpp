#include "Pile.h"

Pile::Pile(int nbCard):Deck(nbCard){}

Pile::Pile(cardColorEnum colorValue)
{
	this->colorValue = colorValue;
	this->start = nullptr;
}

cardColorEnum Pile::getColor()
{
	return colorValue;
}

