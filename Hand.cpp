#include "Hand.h"

Hand::Hand(int nbCard) : Deck(nbCard) { }

Hand::Hand(int playerNb, int credit,bool isBot,string name) {
	this->isPlayer = isBot;
	this->playerNumber = playerNb;
	this->credit = credit;
	this->username = name;
}

int Hand::getPlayerNumber()
{
	return playerNumber;
}

int Hand::getCredit()
{
	return credit;
}

void Hand::setStart(CardL* card)
{
	this->start = card;
}

int Hand::giveToBank()
{
	this->credit -= 10;
	return 10;
}


string Hand::getUsername()
{
	return this->username;
}

bool Hand::getIsPlayer()
{
	return isPlayer;
}
