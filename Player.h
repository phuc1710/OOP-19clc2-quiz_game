#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "User.h"
class Player : public User
{
private:
	int _score;
	int _help[4];
public:
	int getScore();
	int getHelp(int choice);
};

void loadPlayer(string filename, Player*& plrs, int& n);
void writePlayer(string filename, Player*& plrs, const int n);

#endif // !_PLAYER_H_



