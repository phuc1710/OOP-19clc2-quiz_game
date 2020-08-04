#include "Quiz.h"

int checkIdentity(string username, string password, Player*& plrs, int NumPlayer, int& pos)
{
	for (int i = 0; i < NumPlayer; i++)
	{
		if (plrs[i].getUserName() == username && plrs[i].getPassword() == password)
		{
			pos = i;
			return 1;
		}
	}
	return 0;
}

void login()
{
	string username, password;
	int NumPlayer, pos;
	Player* plrs;
	bool choice;

	cout << "\t\t*_*Welcome to Quiz Game*_*" << endl
		<< "Enter 1 to login." << endl
		<< "Enter 0 to create new account." << endl;
	cin >> choice;
	if(choice == 1)
	cout << "Username: ";
	cin.ignore();
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	loadPlayerList("C:/Users/David/Documents/GitHub/OOP-19clc2-quiz_game/data/test.bin", plrs, NumPlayer);
	int check = checkIdentity(username, password, plrs, NumPlayer, pos);
	cout << check << endl;
}
