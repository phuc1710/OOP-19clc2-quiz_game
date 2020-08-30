#ifndef _QUIZ_H_
#define _QUIZ_H_
#include "Administrator.h"
#include "Player.h"

int checkIdentity(string username, string password, Player*& plrs, int NumPlayer, int& pos);
void login();

#endif // !_QUIZ_H_



