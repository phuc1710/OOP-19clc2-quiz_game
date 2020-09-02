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
	Player setUserName(string str);
	Player setPassword(string str);
	Player setScore(int score);
	string getUserName();
	string getPassword();
	int getScore();
};

void loadPlayerList(string filename, vector<Player>& players);
void savePlayerList(string filename, vector<Player> players);

#endif // !_PLAYER_H_



