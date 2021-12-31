#pragma once

#include "../ProjetCPP2122/Card.h"
#include "../ProjetCPP2122/CardL.h"
#include "../ProjetCPP2122/cardColorEnum.h"
#include "../ProjetCPP2122/cardValueEnum.h"
#include "../ProjetCPP2122/Deck.h"
#include "../ProjetCPP2122/View.h"
#include "../ProjetCPP2122/Hand.h"
#include "../ProjetCPP2122/Pile.h"
#include "DB_Controller.h"
#include "Menu.h"

//Cette classe permet de gèrer une partie et gerer la gestion de joueur/Bot
class Game
{	
#pragma region Attribut
	
	int nbCard;
	int swipDiffuculty;
	int nbPlayer;
	Deck* deck;
	Hand* handPlayer[6];
	Pile* colorPile[4];
	int jackPot;
	DB_Controller DB;
#pragma endregion

#pragma region CheckPile

	bool checkPossibility(CardL* card);//Permet de verifier si une carte peut etre jouer dans les Piles
	bool checkBlank(int x);//Permet de regarder si une Pile est vide (si une carte se trouve dedans ou pas)
	bool CheckValueIfBlank(CardL* card);//Permet de comparer la valeurs d'un carte aux valeurs des cartes présente dans la pile=> dans la condition ou la pile serait vide
	bool CheckValueIfBlankIsNot(CardL* card, int i);//Permet de comparer la valeurs d'un carte aux valeurs des cartes présente dans la pile=> dans la condition ou la pile ne serait pas vide
	bool isBehind(CardL* card, int i);//Permet de verifier si la carte se trouve a la fin du paquet, de la main ou de la pile.
#pragma endregion

#pragma region Sharing
	void shareDeck();//Permet de séparer le deck en plusieur mains.
	void ShareFirstCard();//Permet de distribuer les premieres cartes des mains
#pragma endregion

#pragma region View
	void showDeck();//Permet d'afficher le paquet
	void showHand(int y);//Permet d'afficher une main avec une énumération de chaque carte ex: 1 : AsdeCoeur  2 : RoideTrefle
	void showTable(int y);//affiche le plateau en fonction du joueur.
	void showWinner(int i);//Permet d'afficher le nom du gagnant
#pragma endregion

#pragma region Play
	void mooveCardInPileBehind(CardL* card);//Permet de mettre une carte a l'arrière du paquet
	void mooveCardInPileBefore(CardL* card);//Permet de mettre une carte a l'avant du paquet
	void PlayCard(CardL* card);//Permet de joueur une carte dans la Pile
	void start();//Permet de lancer la partie
	int getNbOfGame();//Recupère de la DB le numéro de la partie
	void updateDB(int Winner);//Actualise tout les cagnotte des joueurs et de la Bank
	bool gameFinish();//Verifie si la partie est finit


#pragma endregion

#pragma region Initialiaze
	bool playerChoise(int i);//Permet a l'utilisateur de choisir si le joueur est un bot ou un joueur
	void initiliazeHand();//Permet d'initialiser les mains
	void initiliazePile();//Permet d'initialiser les piles
	void initializeDeck();//Permet d'initialiser le paquet de cartes
	void randomMix();//Permet de mélanger le paquet.
	string getUsername(bool isBot,int i);//Permet de récuperer le nom d'utilisateur d'un joueur dans la DB
#pragma endregion
	
#pragma region GameBot
	void gameBot(int i);//Permet de joueur en tant que robot
	void tryPutCard(int y);//Essaie de poser les cartes avec l'IA
	void verifyCard(int y);//Enumère les possibilité de jeux
#pragma endregion

#pragma region GamePlayer
	void gamePlayer(int i);//Permet de joueur en tant que Joueur
	void inputPlayer(int i);//Permet au joueur de choisir la carte qu'il va jouer
	bool checkIfOneCardCanPlay(int y);//Permet de verifier si le Joueur peut jouer ou pas.
#pragma endregion

public:
#pragma region public
	void initializeGame();//Permet d'initialiser les paramètre la partie
	Game(int nbPlayer, int nbCard, int swipDifficulty);//Contructeur
#pragma endregion

};
