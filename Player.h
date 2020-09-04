#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Question.h"
class Player
{
private:
	string _username;
	string _password;
	int _score;
public:
	Player();
	Player(string username, string password, int score);
	void setUserName(string str);
	void setPassword(string str);
	string getUserName();
	string getPassword();
	int getScore();
	void editPlayerSelf(string filename, Player*& plrs, int& n);
	void createPlayer(string filename, Player*& plrs, int& n);
};


void loadPlayerList(string filename, Player*& plrs, int& n);
void savePlayerList(string filename, Player*& plrs, const int n);

#endif // !_PLAYER_H_



