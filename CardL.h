#pragma once
#include "cardColorEnum.h"
#include "cardValueEnum.h"
#include <cstdio>
#include "Card.h"
//Sert a faire une liste chain� avec les cartes
class CardL : public Card
{
    CardL* NextCard;//Represente la carte suivante
public:
    CardL(); //constructeur
    CardL(cardColorEnum color, cardValueEnum value);//constructeur
    void setNext(CardL* NextCard);//Permet de d�finir la carte suivante
    CardL* getNext(void);//Permet d'obtenir la carte suivante


};