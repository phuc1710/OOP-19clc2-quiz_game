#ifndef _QUIZ_H_
#define _QUIZ_H_
#include "Administrator.h"
#include "Answer.h"
#include "Player.h"
#include "Question.h"

int checkIdentity(string username, string password, Player *&plrs,
				  int NumPlayer, int &pos);

void login();

inline void showAdministratorMenu()
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
		editPlayer("Administrators.txt");
	}
	else if (choice == 2)
	{
		editPlayer("Users.txt");
	}
	else if (choice == 3)
	{
		vector<Question> a;
		loadQuestionList("QuestionList.txt", a);
		editQuestionList(a);
	}
	else if (choice == 4)
	{
		login();
	}
}

#endif // !_QUIZ_H_
