#ifndef _QUIZ_H_
#define _QUIZ_H_
#include "Administrator.h"
#include "Player.h"

int checkIdentity(string username, string password, vector<Player> players, vector<Administrator> admins, int& pos);
void login();
void showAdministratorMenu();

#endif // !_QUIZ_H_



