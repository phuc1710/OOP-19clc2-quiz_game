#include "Administrator.h"

void editPlayer(string filename)
{
	Player* plrs;
	int n;

	loadPlayerList(filename, plrs, n);

	string temp;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ")";
		temp = plrs[i].getUserName();
		cout << temp << endl;

		/*temp = aUsers[i].getPassword();
		cout << " " << temp << endl;*/
	}

	cout << endl;
	cout << "SELECT USER YOU WANT TO CHANGE: ";
	int choice;
	cin >> choice;

	cout << "New username: ";
	cin >> temp;
	plrs[choice - 1].setUserName(temp);

	cout << "New password: ";
	cin >> temp;
	plrs[choice - 1].setPassword(temp);

	savePlayerList(filename, plrs, n);

	delete[]plrs;
}

void loadAdministratorList(string filename, Administrator*& admins, int& n)
{
	ifstream fin(filename);

	if (fin.is_open() == false)
	{
		cout << "Cannot open file!" << filename;
		return;
	}

	fin >> n;

	admins = new Administrator[n];
	string ignore = "";
	getline(fin, ignore, '\n');

	for (int i = 0; i < n; i++)
	{
		getline(fin, ignore, '\n');

		ignore = "";
		getline(fin, ignore, '\n');
		admins[i].setUserName(ignore);

		ignore = "";
		getline(fin, ignore, '\n');
		admins[i].setPassword(ignore);

		ignore = "";
		getline(fin, ignore, '\n');
		admins[i].getScore();
	}

	fin.close();
}

void saveAdministratorList(string filename, Administrator*& admins, const int n)
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
		fout << admins[i].getUserName() << endl;
		fout << admins[i].getPassword() << endl;
		fout << admins[i].getScore() << endl;
	}

	fout.close();
}