#include "DB_Controller.h"
using namespace std;

void DB_Controller::createDB()
{
    sqlite3* DB;

    int exit = 0;
    exit = sqlite3_open("dataBase.db", &DB);

    sqlite3_close(DB);
}

void DB_Controller::createTablePlayer()
{
    sqlite3* DB;
    char* messageError;

    string sql = "CREATE TABLE IF NOT EXISTS PLAYER("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NAME      TEXT UNIQUE NOT NULL,"
        "CAGNOTTE INTEGER NOT NULL);";

    
        int exit = 0;
        exit = sqlite3_open("dataBase.db", &DB);
        /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Error in createTable function." << endl;
            sqlite3_free(messageError);
        }
       
        sqlite3_close(DB);
 

    
    
}

void DB_Controller::insertDataInPlayer(string data)
{
    sqlite3* DB;
    char* messageError;

    string sql = "INSERT INTO PLAYER (NAME,CAGNOTTE) VALUES('";
    sql += data;
    sql += "',100);";

    int exit = sqlite3_open("dataBase.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in insertData function." << endl;
        sqlite3_free(messageError);
    }
    

    sqlite3_close(DB);
    
}

void DB_Controller::showAllDataPlayer()
{
    sqlite3* DB;
    char* messageError;

    string sql = "SELECT * FROM PLAYER;";

    int exit = sqlite3_open("dataBase.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error in selectData function." << endl;
        sqlite3_free(messageError);
    }
   sqlite3_close(DB);
   
}




void DB_Controller::dropPlayer()
{
    sqlite3* DB;
    char* messageError;

    string sql = "DROP TABLE PLAYER;";

    int exit = sqlite3_open("dataBase.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in deleteData function." << endl;
        sqlite3_free(messageError);
    }

    sqlite3_close(DB);
}

int DB_Controller::getCagnotte(string data)
{
    sqlite3* DB;
    sqlite3_stmt* stmt;
    char* messageError;
  
    string sql = "SELECT cagnotte FROM PLAYER WHERE NAME LIKE '";
    sql += data;
    sql += "'";


    int exit = sqlite3_open("dataBase.db", &DB);
    sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);
    int cagnotte;
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        cagnotte = sqlite3_column_int(stmt, 0);
    }
    sqlite3_close(DB);
    return cagnotte;
}

int DB_Controller::getID(string data)
{
    sqlite3* DB;
    sqlite3_stmt* stmt;
    char* messageError;

    string sql = "SELECT ID FROM PLAYER WHERE NAME LIKE '";
    sql += data;
    sql += "'";


    int exit = sqlite3_open("dataBase.db", &DB);
    sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);
    int ID;
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        ID = sqlite3_column_int(stmt, 0);
    }

    sqlite3_close(DB);

    return ID;
}

void DB_Controller::dropJackpot()
{
    sqlite3* DB;
    char* messageError;

    string sql = "DROP TABLE JACKPOT;";

    int exit = sqlite3_open("dataBase.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in deleteData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records deleted Successfully!" << endl;

    sqlite3_close(DB);
}

void DB_Controller::updateCagnotte(int cagnotte,string name)
{
    sqlite3* DB;
    sqlite3_stmt* stmt;
    char* messageError;

    string sql = "UPDATE PLAYER "
        "SET CAGNOTTE = ";
    sql += to_string(cagnotte);
    sql += " where NAME LIKE '";
    sql += name;
    sql += "'";
    cout << endl;
    int exit = 0;
    exit = sqlite3_open("dataBase.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in Update function." << endl;
        cout << sqlite3_errcode << " - " << sqlite3_errmsg << sqlite3_errmsg16 << endl;

        sqlite3_free(messageError);
    }
    sqlite3_close(DB);
}

void DB_Controller::createTableJackpot()
{
    sqlite3* DB;
    char* messageError;

    string sql = "CREATE TABLE JACKPOT("
        "GAMEID LONG NOT NULL, "
        "IDJoueur LONG NOT NULL,"
        "Cagnotte LONG NOT NULL);";

        int exit = 0;
        exit = sqlite3_open("dataBase.db", &DB);
        /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Error in createTable function." << endl;
            sqlite3_free(messageError);
        }
       
        sqlite3_close(DB);
}

void DB_Controller::showHistoryJackpot(int IDplayerCurrent)
{
    sqlite3* DB;
    char* messageError;

    string sql = "SELECT Cagnotte FROM JACKPOT WHERE IDJoueur LIKE ";
    sql += to_string(IDplayerCurrent);
 

    int exit = sqlite3_open("dataBase.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
    exit = sqlite3_exec(DB, sql.c_str(), callHistory, NULL, &messageError);
    cout << endl;
    if (exit != SQLITE_OK) {
        cerr << "Error in selectData function." << endl;
        sqlite3_free(messageError);
    }
    sqlite3_close(DB);
}

void DB_Controller::insertDataInJackpot(int gameID, int IDJoueur, int Cagnotte)
{
    sqlite3* DB;
    char* messageError;

    string sql = "INSERT INTO JACKPOT (GAMEID,IDJoueur,Cagnotte) VALUES(";
    sql += to_string(gameID);
    sql += ",";
    sql += to_string(IDJoueur);
    sql += ",";
    sql += to_string(Cagnotte);
    sql += ");";

    int exit = sqlite3_open("dataBase.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in insertData function." << endl;
        sqlite3_free(messageError);
    }
    sqlite3_close(DB);
}

int DB_Controller::getNumberOfGame()
{
    sqlite3* DB;
    sqlite3_stmt* stmt;
    char* messageError;
    string sql = "SELECT GAMEID FROM JACKPOT";
    int exit = sqlite3_open("dataBase.db", &DB);
    sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);
    int GAMEID;
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        GAMEID = sqlite3_column_int(stmt, 0);
    }
    sqlite3_close(DB);
    return GAMEID;
}

bool DB_Controller::CheckName(string data)
{
    sqlite3* DB;
    sqlite3_stmt* stmt;
    char* messageError;

    string sql = "SELECT name FROM PLAYER";
    


    int exit = sqlite3_open("dataBase.db", &DB);
    sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);
    bool etat = false;
      while (sqlite3_step(stmt) != SQLITE_DONE)
      {
        string name = string(reinterpret_cast<const char*>( sqlite3_column_text(stmt, 0)));
        if (name == data ) {
            cout << name << " est present dans le jeu\n\n";
            etat = true;
        }
      }
      sqlite3_close(DB);
      return etat;
}

int DB_Controller::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    for (int i = 0; i < argc; i++) {
        
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    return 0;
}

int DB_Controller::callHistory(void* NotUsed, int argc, char** argv, char** azColName)
{
    cout << "=>" << argv[argc-1] << "$";
    
    return 0;
}


