#include "Deck.h"
#pragma region constructor

Deck::Deck()
{
}

Deck::Deck(int nbCard) {
    int temp = 0;
    for (int y = Ace; y >= Two; y--)
    {
        if (temp == nbCard)
            break;
        for (int i = pic; i <= squares; i++)
        {
            CardL* tempCard = new CardL(cardColorEnum(i), cardValueEnum(y));
            addToDeck(tempCard);
            temp++;
            if (temp == nbCard) {
                break;
            }
        }
    }
}




void Deck::addToDeck(CardL* Card)
{
    CardL* temp;
    if (this->start == nullptr)
    {
        this->start = Card;
    }
    else
    {
        temp = this->start;
        while (temp->getNext() != nullptr)
        {
            temp = (temp->getNext());
        }
        temp->setNext(Card);

    }
}

void Deck::showDeck()
{
    CardL* temp = start;
    temp->showCard();
    while (temp->getNext() != nullptr)
    {
        temp = (temp->getNext());
        temp->showCard();
    }

}
void Deck::showDeckWNumber()
{
    CardL* temp = start;
    int nb = 0;
    cout << nb << " : ";
    temp->showCard();
    cout << "  ";
    while (temp->getNext() != nullptr)
    {
        nb++;
        temp = (temp->getNext());
        cout << nb << " : ";
        temp->showCard();
        cout << "  ";
    }
    cout << "\n777 : Passer son tour et payer." << endl;
}
CardL* Deck::getLastCard()
{
    CardL* temp = start;
    while (temp->getNext() != nullptr)
    {
        temp = (temp->getNext());
    }
    return temp;
}
void Deck::setFirstCard(CardL *card)
{
    card->setNext(start);
    this->start = card;
}

int Deck::GetLength()
{
    CardL* temp = start;
    if (start == nullptr) return 0;
    int i = 1;
    while (temp->getNext() != nullptr)
    {
        temp = (temp->getNext());
        i++;
    }
    return i;
}

#pragma region Bibliothéque
void Deck::putBehind(CardL* card)
{
    CardL* temp = start;
    if (start == nullptr) {
        start = card;
    }
    else {
        while (temp->getNext() != nullptr)
        {
            temp = (temp->getNext());
        }
        temp->setNext(card);
    }
}


CardL* Deck::getCardInDeck(int x)
{
    CardL* temp = start;
    CardL* frontCard = start;
    if (temp->getNext() == nullptr)
    {
        start = nullptr;
        return temp;
    }
    if (x == 0) {
        start = temp->getNext();
    }
    else if (x <= this->GetLength()-1) {
    for (int i = 0; i <= x; i++)
    {
        temp = (temp->getNext());
        if (i == this->GetLength()-1)
             return temp;
        if (i == x - 1)
             frontCard = temp;
        }
    frontCard->setNext(temp->getNext());
    }
    temp->setNext(nullptr);
    return temp;
    
}
void Deck::randomMix(int x,int nbcard)
{
    srand(time(NULL));
    for (int i = 0; i <= x; i++)
    {
        this->putBehind(this->getCardInDeck(rand() % nbcard));

    }
    cout << "melange termine" << endl;
}
#pragma endregion
