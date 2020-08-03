#include "Administrator.h"

void editPlayer(string filename)
{
	Player* plrs;
	int n;

	loadPlayer(filename, plrs, n);

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

	writePlayer(filename, plrs, n);

	delete[]plrs;
}