#include <iostream>;
#include "CardL.h"

CardL::CardL()
{
}
CardL::CardL(cardColorEnum cardColor, cardValueEnum cardValue) : Card(cardColor, cardValue) {
    this->cardColor = cardColor;
    this->cardValue = cardValue;

}

void CardL::setNext(CardL* NextCard)
{
    this->NextCard = NextCard;
}

CardL* CardL::getNext(void)
{
     return this->NextCard;
}