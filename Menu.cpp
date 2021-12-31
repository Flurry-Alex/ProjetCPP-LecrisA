#include "Menu.h"

using namespace std;
int Menu::getSetting(int& nbCard, int& difficulty)
{
	ifstream files("Settings.txt");
	string useless;
	files >> useless >> nbCard >> useless >> difficulty;
	files.close();
	return 0;
}

void Menu::getChoice()
{
	cout << "Faites votre choix : \n\n";
	cout << "1. Demarrer une partie \n";
	cout << "2. Afficher les joueurs en cours \n";
	cout << "3. Afficher les statistiques d'un joueur \n";
	cout << "4. Ajouter un joueur \n";
	cout << "5. Remettre les compteurs a zero\n\n";
	getChoiceResults();
}

void Menu::getChoiceResults()
{
	cout << "Votre Choix : ";
	char temp;
	cin >> temp;
	switch (temp) {
	case '1':
		startGame();
		break;
	case '2':
		showDBPlayer();
		break;
	case '3':
		getHistory();
		break;
	case '4':
		addPlayerInDB();
		break;
	case '5':
		resetgame();
		break;
	default:
		system("cls");
		getChoice();
		break;
	}
}

void Menu::startGame()
{
	int nbCard, difficulty = 0;
	getSetting(nbCard, difficulty);
	Game* game = new Game(getNbPlayer(), nbCard, difficulty);
	game->initializeGame();
}

void Menu::showDBPlayer()
{
	system("cls");
	DB.showAllDataPlayer();
	system("pause");
	system("cls");
	getChoice();
}

void Menu::getHistory()
{
	system("cls");
	DB.showAllDataPlayer();
	cout << "\nEntrer l'id du joueur dont vous voulez voir l'historique : ";
	int currentID;
	cin >> currentID;
	DB.showHistoryJackpot(currentID);
	system("pause");
	system("cls");
	getChoice();
}

void Menu::addPlayerInDB()
{
	system("cls");
	cout << "Entrer le nom d'un nouveau joueur : ";
	string data;
	cin >> data;
	DB.insertDataInPlayer(data);
	DB.insertDataInJackpot(0, DB.getID(data), DB.getCagnotte(data));
	system("pause");
	system("cls");
	getChoice();
}

void Menu::resetgame()
{
	DB.dropPlayer();
	DB.dropJackpot();
	DB.createTablePlayer();
	DB.createTableJackpot();
	DB.insertDataInPlayer("Bank");
	DB.updateCagnotte(0, "Bank");
	DB.insertDataInJackpot(0, 1, 0);
	system("pause");
	system("cls");
	getChoice();
}

int	Menu::getNbPlayer() {
	system("cls");
	int nbPlayer;
	cout << "Entrer le nombre de joueur : ";
	cin >> nbPlayer;
	cout << endl;
	if (nbPlayer <= 6 && nbPlayer >= 4)
		return nbPlayer;
	else {
		cout << "Entre 4 joueurs minimum et 6 joueurs maximum !\n";
		system("pause");
		system("cls");
		nbPlayer = getNbPlayer();
		return nbPlayer;
	}
}