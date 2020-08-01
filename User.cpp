#include "User.h"

void User::setUsername(string str)
{
	this->_username = str;
}

void User::setPassword(string str)
{
	this->_password = str;
}

string User::getUserName()
{
	return this->_username;
}

string User::getPassword()
{
	return this->_password;
}
void loadUser(string filename, User*& aUsers, int& n) {

	ifstream fin(filename);

	if (fin.is_open() == false)
	{
		cout << "Cant open " << filename;
		return;
	}

	fin >> n;
	aUsers = new User[n];
	string ignore = "";
	getline(fin, ignore, '\n');

	for (int i = 0; i < n; i++)
	{
		getline(fin, ignore, '\n');

		ignore = "";
		getline(fin, ignore, '\n');
		aUsers[i].setUsername(ignore);

		ignore = "";
		getline(fin, ignore, '\n');
		aUsers[i].setPassword(ignore);
	}

	fin.close();
}

void writeUser(string filename, User* aUsers, const int n) {
	ofstream fout;
	fout.open(filename);
	if (!fout.is_open())
	{
		cout << "Can not open " << filename << endl;
		return;
	}

	fout << n << endl;

	string temp;
	for (int i = 0; i < n; i++) {
		fout << endl;

		fout << aUsers[i].getUserName() << endl;
		fout << aUsers[i].getPassword() << endl;
	}

	fout.close();
}

void editUser(string filename)
{
	User* aUsers;
	int n;

	loadUser(filename, aUsers, n);

	string temp;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ")";
		temp = aUsers[i].getUserName();
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
	aUsers[choice - 1].setUsername(temp);

	cout << "New password: ";
	cin >> temp;
	aUsers[choice - 1].setPassword(temp);

	writeUser(filename, aUsers, n);

	delete[]aUsers;
}
