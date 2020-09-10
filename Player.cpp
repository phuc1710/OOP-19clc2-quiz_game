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

Player Player::createPlayer(string filename)
{
	vector<Player> players;
	loadPlayerList(filename, players);

	Player n_player;

	cout << "Please input player name: ";
	cin >> n_player._username;
	cout << "Please input player password: ";
	cin >> n_player._password;
	n_player._score = 0;


	players.push_back(n_player);

	savePlayerList(filename, players);
	return *this;
}

Player Player::editPlayer(string filename)
{
	vector<Player> players;
	loadPlayerList(filename, players);

	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getUserName() == this->getUserName())
		{
			string str1, str2;

			cout << "Please input new username: ";
			cin >> str1;
			this->_username = str1;
			cout << "Please input new password: ";
			cin >> str2;
			this->_password = str2;

			players[i] = *this;
		}
	}
	savePlayerList(filename, players);
	return *this;
}