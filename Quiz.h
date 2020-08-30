#ifndef _QUIZ_H_
#define _QUIZ_H_
#include "Administrator.h"
#include "Player.h"
#include "Question.h"
#include "Answer.h"

int checkIdentity(string username, string password, Player*& plrs, int NumPlayer, int& pos);
void login();

inline void showAdministratorMenu()
{
	int choice;

	cout << "ADMINISTRATOR MENU: " << endl;
	cout << "1. Change password" << endl;
	cout << "2. Edit user's info " << endl;
	cout << "3. Edit question list" << endl;


	cin >> choice;

	if (choice == 1)
	{
		editPlayer("Administrator.txt");
	}
	else if (choice == 2)
	{
		editPlayer("Users.txt");
	}
	else if (choice == 3)
	{
		editQuestionList("Question.txt");
	}
}

#endif // !_QUIZ_H_



