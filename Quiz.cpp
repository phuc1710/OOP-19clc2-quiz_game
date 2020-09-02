#include "Quiz.h"

int checkIdentity(string username, string password, vector<Player> players, vector<Administrator> admins, int& pos)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getUserName() == username && players[i].getPassword() == password)
		{
			pos = i;
			return 1;
		}
	}
	for (int i = 0; i < admins.size(); i++)
	{
		if (admins[i].getUserName() == username && admins[i].getPassword() == password)
		{
			pos = i;
			return -1;
		}
	}
	return 0;
}

void login()
{
	string username, password;
	int pos;
	vector<Player> players;
	vector<Administrator> admins;
	bool choice;

	cout << " -------------LOG IN------------- " << endl;
	cout << " -------------------------------- " << endl;
	cout << "| 1. Log in\t\t\t|" << endl;
	cout << " -------------------------------- " << endl;
	cout << "| 2. Create new account\t\t|" << endl;
	cout << " -------------------------------- " << endl;
	cout << "| 3. Exit\t\t\t|" << endl;
	cout << " -------------------------------- " << endl;
	cout << "SELECT YOUR OPTION" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Username: ";
		cin.ignore();
		getline(cin, username);
		cout << "Password: ";
		getline(cin, password);
		loadPlayerList(PLAYER_PATH_DATA, players);

		loadAdministratorList(ADMINISTRATOR_PATH_DATA, admins);

		int check = checkIdentity(username, password, players, admins, pos);
		cout << check << endl;
	}
}

void showAdministratorMenu()
{
	int choice = 0;

	cout << " -------ADMINISTRATOR MENU------- " << endl;
	cout << " -------------------------------- " << endl;
	cout << "| 1. Change password\t\t|" << endl;
	cout << " -------------------------------- " << endl;
	cout << "| 2. Edit user's info\t\t|" << endl;
	cout << " -------------------------------- " << endl;
	cout << "| 3. Edit question list\t\t|" << endl;
	cout << " -------------------------------- " << endl;
	cout << "| 4. Exit\t\t\t|" << endl;
	cout << " -------------------------------- " << endl;
	cout << "SELECT YOUR OPTION" << endl;

	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		cin >> choice;

	if (choice == 1)
	{
		editPlayer(ADMINISTRATOR_PATH_DATA);
	}
	else if (choice == 2)
	{
		editPlayer(PLAYER_PATH_DATA);
	}
	else if (choice == 3)
	{
		vector<Question> a;
		editQuestionList(a);
	}
	else if (choice == 4)
	{
		login();
	}
}