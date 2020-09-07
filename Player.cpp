#include "Player.h"

Player Player::setUserName(string str)
{
	this->_username = str;
	return *this;
}

Player Player::setPassword(string str)
{
	this->_password = str;
	return *this;
}
Player Player::setScore(int score)
{
	this->_score = score;
	return *this;
}

string Player::getUserName()
{
	return this->_username;
}

string Player::getPassword()
{
	return this->_password;
}

int Player::getScore()
{
	return this->_score;
}

void loadPlayerList(string filename, vector<Player>& players)
{
	ifstream fin(filename);

	if (fin.is_open() == false)
	{
		cout << "Cannot open file!" << filename;
		return;
	}
	while(!fin.eof())
	{
		Player player;
		string username, password, score;
		getline(fin, username);
		player.setUserName(username);
		getline(fin, password);
		player.setPassword(password);
		getline(fin, score);
		int NumScore = stoi(score);
		player.setScore(NumScore);
		players.push_back(player);
	}
	fin.close();
}

void savePlayerList(string filename, vector<Player> players)
{
	ofstream fout(filename);

	if (!fout.is_open())
	{
		cout << "Cannot open file!" << filename;
		return;
	}
	for (int i = 0; i < players.size(); i++)
	{
		fout << endl;
		fout << players[i].getUserName() << endl;
		fout << players[i].getPassword() << endl;
		if(i == players.size() - 1)
			fout << players[i].getScore();
		else
			fout << players[i].getScore() << endl;
	}

	fout.close();
}

