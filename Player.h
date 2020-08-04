#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Question.h"
class Player
{
private:
	string _username;
	string _password;
	int _score;
	int _help[4] = { 1,2,3,4 };
public:
	void setUserName(string str);
	void setPassword(string str);
	string getUserName();
	string getPassword();
	int getScore();
	int getHelp(int choice);
};

void loadPlayerList(string filename, Player*& plrs, int& n);
void savePlayerList(string filename, Player*& plrs, const int n);

#endif // !_PLAYER_H_



