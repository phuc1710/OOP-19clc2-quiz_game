#include "Player.h"

Player::Player() { }

Player::Player(string username, string password, int score)
{
	this->_username = username;
	this->_password = password;
	this->_score = score;
}

void Player::setUserName(string str)
{
	this->_username = str;
}

void Player::setPassword(string str)
{
	this->_password = str;
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

void loadPlayerList(string filename, Player*& plrs, int& n)
{
	ifstream fin(filename);

	if (fin.is_open() == false)
	{
		cout << "Cannot open file!" << filename;
		return;
	}

	fin >> n;

	plrs = new Player[n];
	string ignore = "";
	getline(fin, ignore, '\n');

	for (int i = 0; i < n; i++)
	{
		getline(fin, ignore, '\n');

		ignore = "";
		getline(fin, ignore, '\n');
		plrs[i].setUserName(ignore);

		ignore = "";
		getline(fin, ignore, '\n');
		plrs[i].setPassword(ignore);

		ignore = "";
		getline(fin, ignore, '\n');
		plrs[i].getScore();
	}

	fin.close();
}

void savePlayerList(string filename, Player*& plrs, const int n)
{
	ofstream fout(filename);

	if (!fout.is_open())
	{
		cout << "Cannot open file!" << filename;
		return;
	}

	fout << n << endl;

	string temp;

	for (int i = 0; i < n; i++) {
		fout << endl;
		fout << plrs[i].getUserName() << endl;
		fout << plrs[i].getPassword() << endl;
		fout << plrs[i].getScore() << endl;
	}

	fout.close();
}

void Player::editPlayerSelf(string filename, Player*& plrs, int& n)
{
	loadPlayerList(filename, plrs, n);

	for (int i = 0; i < n; i++)
	{
		if (plrs[i]._username == this->_username && plrs[i]._password == this->_password)
		{
			
			string n_username, n_password;
			cout << "Please enter new username: ";
			cin >> n_username;
			this->setUserName(n_username);

			cout << "Please enter new password: ";
			cin >> n_password;
			this->setPassword(n_password);
		}
	}

	savePlayerList(filename, plrs, n);
}

void Player::createPlayer(string filename, Player*& plrs, int& n)
{
	loadPlayerList(filename, plrs, n);

	Player n_player;
	string n_username, n_password;
	cout << "Please enter new username: ";
	cin >> n_username;
	n_player.setUserName(n_username);

	cout << "Please enter new password: ";
	cin >> n_password;
	n_player.setPassword(n_password);
	n_player._score = 0;

	plrs[n] = n_player;

	n += 1;

	savePlayerList(filename, plrs, n);
}