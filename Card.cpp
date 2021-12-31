#include <vector>
#include <iostream>
#include "../ProjetCPP2122/Card.h"

using namespace std;
#pragma execution_character_set( "utf-8" )
#pragma region losConstructores
Card::Card() {}

Card::Card(cardColorEnum cardColor, cardValueEnum cardValue)
{
	this->cardColor = cardColor;
	this->cardValue = cardValue;
}
#pragma endregion
#pragma region getsetters
cardColorEnum* Card::getColor() {return &cardColor;}
cardValueEnum* Card::getValue() {return &cardValue;}

void Card::setColor(cardColorEnum cardColor) {
	this->cardColor= cardColor;
}
void Card::setValue(cardValueEnum cardValue) {
	this->cardValue=cardValue;
}

#pragma endregion
void Card::showCard()
{
	string card;
	switch (*this->getValue())
	{
	case Two:
		cout << "2";
		break;
	case Three:
		cout << "3";
		break;
	case Four:
		cout << "4";
		break;
	case Five:
		cout << "5";
		break;
	case Six:
		cout << "6";
		break;
	case Seven:
		cout << "7";
		break;
	case Eight:
		cout << "8";
		break;
	case Nine:
		cout << "9";
		break;
	case Ten:
		cout << "10";
		break;
	case Jack:
		cout << "J";
		break;
	case Queen:
		cout << "Q";
		break;
	case King:
		cout << "K";
		break;
	case Ace:
		cout << "A";
		break;
	}
	switch (*this->getColor()) {
	case pic:
		cout << "♠" << "  " ;
		break;
	case hearth:
		cout << "♥" << "  ";
		break;
	case clubs:
		cout << "♣" << "  ";
		break;
	case squares:
		cout << "♦" << "  ";
		break;

	}
}
