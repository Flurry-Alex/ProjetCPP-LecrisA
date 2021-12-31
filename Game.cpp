#include "Game.h"
#include "Hand.h";
#pragma execution_character_set( "utf-8" )
using namespace std;



Game::Game(int nbPlayer,int nbCard, int swipDifficulty) {

	this->nbPlayer = nbPlayer;
	this->nbCard = nbCard;
	this->swipDiffuculty = swipDifficulty;
	initiliazePile();
	initiliazeHand();
}
#pragma region MooveToPile

void Game::mooveCardInPileBehind(CardL* card)
{
	colorPile[0]->addToDeck(card);
}

void Game::mooveCardInPileBefore(CardL* card)
{
	colorPile[0]->setFirstCard(card);
}
void Game::PlayCard(CardL* card)
{
	for (int i = 0; i < 4; i++)
	{
		if (colorPile[i]->getColor() == *card->getColor())
		{
			if (checkBlank(i)) {
					if (CheckValueIfBlank(card))
						colorPile[i]->addToDeck(card);
		
			}
			else {
				if (CheckValueIfBlankIsNot(card, i)) {
					if (isBehind(card, i)) {
						colorPile[i]->addToDeck(card);
					}
					else {
						colorPile[i]->setFirstCard(card);
					}

				}
			}
		}
	}

}
#pragma endregion

#pragma region Show
void Game::showDeck()
{
	deck->showDeck();
}
void Game::showHand(int y)
{
	handPlayer[y]->showDeckWNumber();
	
}
void Game::showTable(int y)
{

	cout << "Jackpot = " << jackPot << endl;
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0:cout << "-----------------Pile ♠-----------------" << endl;
			break;
		case 1:cout << "-----------------Pile ♥-----------------" << endl;
			break;
		case 2:cout << "-----------------Pile ♣-----------------" << endl;
			break;
		case 3:cout << "-----------------Pile ♦-----------------" << endl;
			break;

		}
		if(colorPile[i]->start != nullptr)
			colorPile[i]->showDeck();
		cout << endl;
	}
	cout << endl;
	
		cout << "-----------------" << handPlayer[y]->getUsername() << "----------------- Money = " << handPlayer[y]->getCredit() << endl;
		if (handPlayer[y]->start != nullptr)
			handPlayer[y]->showDeck();
		else {
			cout << "Paquet Vide" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	
}
void Game::showWinner(int i)
{
	cout << "============================== Le gagnant est " << handPlayer[i % nbPlayer]->getUsername() << " !!! ========================" << endl;
}
#pragma endregion

#pragma region CheckingPossibilty

bool Game::checkBlank(int x) {
	if (colorPile[x]->start != nullptr)
		colorPile[x]->blank = false;
	return colorPile[x]->blank;
}
bool Game::playerChoise(int i)
{
	char temp;
	cout << "Le joueur " << i << " est-il un joueur? (y ou n) :" ;
	cin >> temp;
	switch (temp) {
	case 'y':
	case 'Y':
		return true;
		break;
	case 'n':
	case 'N':
		return false;
		break;
	default:
		return playerChoise(i);
		break;
	}
}
void Game::initiliazeHand()
{
	system("cls");
	string Username;
	int cagnotte;
	bool isBot;
	for (int i = 0; i < nbPlayer; i++) {
		isBot = playerChoise(i);
		Username = getUsername(isBot, i);
		if (!isBot){
			handPlayer[i] = new Hand(i, 100, isBot, Username);
		}
		else {
			handPlayer[i] = new Hand(DB.getID(Username), DB.getCagnotte(Username), isBot, Username);
		}
		
	}
}
void Game::initiliazePile()
{
	for (int i = 0; i <= 3; i++) {
		switch (i) {
		case 0:
			colorPile[i] = new Pile((cardColorEnum)pic);
			break;
		case 1:
			colorPile[i] = new Pile((cardColorEnum)hearth);
			break;
		case 2:
			colorPile[i] = new Pile((cardColorEnum)clubs);
			break;
		case 3:
			colorPile[i] = new Pile((cardColorEnum)squares);
			break;
		}
	}
}
bool Game::checkPossibility(CardL* card) {
	for (int i = 0; i <4; i++)
	{
		if (colorPile[i]->getColor() == *card->getColor())
		{
			if (checkBlank(i)){		
			return CheckValueIfBlank(card);
			}
			else {
			return CheckValueIfBlankIsNot(card,i);
			}
		}
	}
	return false;
}


bool Game::CheckValueIfBlankIsNot(CardL* card,int i) {
	cardValueEnum cardValue = *card->getValue();
	if (cardValue + 1 == *colorPile[i]->start->getValue()) {
		return true;
	}
	if (cardValue- 1 == *colorPile[i]->getLastCard()->getValue() ) {
		return true;
	}
	return false;
}

bool Game::isBehind(CardL* card,int i)
{
	cardValueEnum cardValue = *card->getValue();
	if (cardValue - 1 == *colorPile[i]->getLastCard()->getValue())
		return true;
	return false;
}


bool Game::CheckValueIfBlank(CardL* card) {
	if (*card->getValue() == 7)
		return true;
	return false;
}

#pragma endregion


#pragma region InitializeGame
void Game::randomMix()
{
		deck->randomMix((swipDiffuculty*100),nbCard);

}

void Game::initializeDeck()
{
	deck = new Deck(nbCard);
}

string Game::getUsername(bool isBot,int i)
{
	string temp;
	if (isBot) {
		cout << "Entrer le pseudo du joueur : ";
		cin >> temp;
		if (DB.CheckName(temp)){
			return temp;
		}
		else {
			return getUsername(isBot,i);
		}
	}
	else
	{
		temp = "BOT";
		temp += to_string(i);
		return temp;
	}
	
	cout << "Le pseudo du joueur: " << nbPlayer << " sera " << handPlayer[nbPlayer]->getUsername();
	cout << endl;
}


#pragma region SharingCardBetweenPlayer

void Game::shareDeck() {
	this->ShareFirstCard();
	for (int i = 0; i <= (nbCard - (nbPlayer + 1)); i++) {
		handPlayer[i % nbPlayer]->addToDeck(deck->getCardInDeck(0));
	}
}

void Game::ShareFirstCard() {
	for (int i = 0; i < nbPlayer; i++) {
		handPlayer[i]->setStart(deck->getCardInDeck(0));
	}

}
#pragma endregion

#pragma endregion

void Game::initializeGame() {

	this->initializeDeck();
	this->randomMix();
	this->shareDeck();
	this->start();
}

void Game::tryPutCard(int y)
{
	CardL* temp;
	int tempLength = handPlayer[y]->GetLength();
	int i = 0;
	bool havePlayed = false;
	
	
	for (i = 0; i < tempLength; i++) {
			temp = handPlayer[y]->getCardInDeck(0);
			if (checkPossibility(temp)) {
				cout << handPlayer[y]->getUsername() << " a joue ";
				temp->showCard();
				cout << endl;
				this->PlayCard(temp);
				havePlayed = true;
				break;
			}
			else {

				handPlayer[y]->putBehind(temp);
			}
			
	}
	if(!havePlayed)
		jackPot += handPlayer[y]->giveToBank();
	
}

void Game::verifyCard(int y)
{
	CardL* temp;
	int tempLength = handPlayer[y]->GetLength();
	cout << "Possibilite de jeux : ";
	int i = 0;
		for (i = 0; i < tempLength; i++) {
			temp = handPlayer[y]->getCardInDeck(0);
			if (checkPossibility(temp)) {
				temp->showCard();
			}

			handPlayer[y]->putBehind(temp);

		}
	cout << endl;
	cout << endl;
}

void Game::start()
{
	char var = 0;	
	int i = 0;
	do {
		cout << "tour numéro : " << i / nbPlayer << "             Joueur: " << handPlayer[i % nbPlayer]->getUsername() << endl;
		bool botState = handPlayer[i % nbPlayer]->getIsPlayer();
		if (!botState) {
			gameBot(i % nbPlayer);
		}
		else {
			gamePlayer( i % nbPlayer);
		}
		this->showTable(i % nbPlayer);
		i++;
		
	} while (!this->gameFinish());
	showWinner(i-1);
	updateDB(i-1);
	cout << "finis !" << endl;
	system("pause");
	system("cls");
	Menu menu;
	menu.getChoice();
}

void Game::gameBot(int i)
{
	this->verifyCard(i);
	this->tryPutCard(i);
}

void Game::gamePlayer(int i)
{
	verifyCard(i);
	//	ViewCardPossibility(i);
	inputPlayer(i);
}

bool Game::gameFinish()
{
	for (int i = 0; i < nbPlayer; i++) {
		if (handPlayer[i]->start == nullptr  || handPlayer[i]->getCredit() < 10 ) {
			return true;
		}

	}
	return false;
}

void Game::updateDB(int Winner)
{
	int nbOfGame = getNbOfGame() + 1;
	for (int i = 0; i < nbPlayer; i++) {
		if (handPlayer[i]->getIsPlayer()) {
			if((Winner%nbPlayer) == i){
				int WinnerCagnotte = handPlayer[i]->getCredit() + (jackPot * 0.9);
				DB.updateCagnotte(WinnerCagnotte, handPlayer[i]->getUsername());
				cout << "La cagnotte du joueur " << i << " a ete update !";
				DB.insertDataInJackpot(nbOfGame, handPlayer[i]->getPlayerNumber(), WinnerCagnotte);
			}
			else {
				DB.updateCagnotte(handPlayer[i]->getCredit(), handPlayer[i]->getUsername());
				cout << "La cagnotte du joueur " << i << "a ete update !";
				DB.insertDataInJackpot(nbOfGame, handPlayer[i]->getPlayerNumber(), handPlayer[i]->getCredit());
			}
		}
	}
	int BankCagnotte = DB.getCagnotte("Bank") + (jackPot * 0.1);
	DB.updateCagnotte(BankCagnotte, "Bank");
	DB.insertDataInJackpot(nbOfGame, 1, BankCagnotte);
}

int Game::getNbOfGame()
{
	return DB.getNumberOfGame();
}



void Game::inputPlayer(int i)
{
	if (checkIfOneCardCanPlay(i)) {
		showHand(i);
		cout << "\nEntrer le numero de la carte a jouer : ";
		int AnsPlayer;
		cin >> AnsPlayer;
		
		if (AnsPlayer == 777) {
			jackPot += handPlayer[i]->giveToBank();
			cout << handPlayer[i]->getUsername() << " ne peut pas jouer...";
			return;
		}
		else{
			CardL* temp;
			temp = handPlayer[i]->getCardInDeck(0);
			for (int y = 0; y < AnsPlayer; y++) {
				handPlayer[i]->putBehind(temp);
				temp = handPlayer[i]->getCardInDeck(0);
			}
			if (checkPossibility(temp)) {
				cout << handPlayer[i]->getUsername() << " a joue ";
				temp->showCard();
				cout << endl;
				this->PlayCard(temp);
				return;
			}
			else {
				handPlayer[i]->putBehind(temp);
				inputPlayer(i);
			}
		}
	}
	else {
		cout << handPlayer[i]->getUsername() << " ne peut pas jouer et donne 10$ a la banque.\n";
		jackPot += handPlayer[i]->giveToBank();
	}

}



bool Game::checkIfOneCardCanPlay(int y)
{
	CardL* temp;
	int tempLength = handPlayer[y]->GetLength();
	bool state = false;
	for (int i = 0; i < tempLength; i++) {
		temp = handPlayer[y]->getCardInDeck(0);
		if (checkPossibility(temp)) {
			state = true;
		}
		handPlayer[y]->putBehind(temp);
	}
	return state;
}
