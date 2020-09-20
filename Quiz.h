#ifndef _QUIZ_H_
#define _QUIZ_H_
#include "Administrator.h"
#include "Player.h"

int checkIdentity(string username, string password, vector<Player> players, vector<Administrator> admins, int& pos);
void login();
void showAdministratorMenu(Administrator admin);
void showPlayerMenu(Player player);
vector<string> loadTopicList(string fileName);
void showTopicMenu(vector<string> topic);
void showHelp();
void startGame(Player player);
void showLeaderboard();

#endif // !_QUIZ_H_