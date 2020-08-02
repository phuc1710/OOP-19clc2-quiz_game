#include "Player.h"

int Player::getScore()
{
	return this->_score;
}

int Player::getHelp(int choice)
{
	return this->_help[choice];
}

void loadPlayer(string filename, Player*& plrs, int& n)
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
		plrs[i].setUsername(ignore);

		ignore = "";
		getline(fin, ignore, '\n');
		plrs[i].setPassword(ignore);

		ignore = "";
		getline(fin, ignore, '\n');
		plrs[i].getScore();
	}

	fin.close();
}

void writePlayer(string filename, Player*& plrs, const int n)
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