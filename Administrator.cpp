#include "Administrator.h"

Administrator Administrator::edit(string filename)
{
	vector<Administrator> admin;
	loadAdministratorList(filename, admin);
	for (int i = 0; i < admin.size(); i++)
	{
		if (admin[i]._username == this->_username)
		{
			string str1, str2;

			cout << "Please input new username: ";
			cin >> str1;
			this->_username = str1;
			cout << "Please input new password: ";
			cin >> str2;
			this->_password = str2;

			admin[i] = *this;
		}
	}
	saveAdministratorList(filename, admin);
	return *this;
}

void editPlayer(string filename)
{
	vector<Player> players;

	loadPlayerList(filename, players);

	string temp;
	for (int i = 0; i < players.size(); i++)
	{
		cout << i + 1 << ")";
		temp = players[i].getUserName();
		cout << temp << endl;
	}

	cout << endl;
	cout << "SELECT PLAYER YOU WANT TO CHANGE: ";
	int choice;
	cin >> choice;

	cout << "New username: ";
	cin >> temp;
	players[choice - 1.0].setUserName(temp);

	cout << "New password: ";
	cin >> temp;
	players[choice - 1.0].setPassword(temp);

	savePlayerList(filename, players);
}

void loadAdministratorList(string filename, vector<Administrator>& admins)
{
	ifstream fin(filename);

	if (fin.is_open() == false)
	{
		cout << "Cannot open file!" << filename;
		return;
	}
	while(!fin.eof())
	{
		Administrator admin;
		string username, password;
		getline(fin, username);
		admin.setUserName(username);
		getline(fin, password);
		admin.setPassword(password);
		admins.push_back(admin);
	}

	fin.close();
}

void saveAdministratorList(string filename, vector<Administrator> admins)
{
	ofstream fout(filename);

	if (!fout.is_open())
	{
		cout << "Cannot open file!" << filename;
		return;
	}
	for (int i = 0; i < admins.size(); i++)
	{
		fout << admins[i].getUserName() << endl;
		if (i == admins.size() - 1)
			fout << admins[i].getPassword();
		else
			fout << admins[i].getPassword() << endl;
	}

	fout.close();
}