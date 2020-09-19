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
	int pos, check;
	vector<Player> players;
	vector<Administrator> admins;
	char choice = 0;

	system("cls");
	cout << "-------------LOG IN--------------" << endl;
	cout << "---------------------------------" << endl;
	cout << "| 1. Log in\t\t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "| 2. Create new account\t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "| 3. Exit\t\t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "SELECT YOUR OPTION" << endl;
	while (choice < '1' || choice > '3')
		if (_kbhit())
		{
			choice = _getch();
			switch(choice)
			{
			case '1':
				cout << "Username: ";
				cin.ignore(0);
				getline(cin, username);
				cout << "Password: ";
				getline(cin, password);
				loadPlayerList(PLAYER_PATH_DATA, players);

				loadAdministratorList(ADMINISTRATOR_PATH_DATA, admins);

				check = checkIdentity(username, password, players, admins, pos);
				switch (check)
				{
				case -1:
					showAdministratorMenu(admins[pos]);
					break;
				case 1:
					showPlayerMenu(players[pos]);
					break;
				case 0:
					cout << "Wrong username or password" << endl;
					system("pause");
					login();
					break;
				}
				break;
			case '2':
				Player::createPlayer(PLAYER_PATH_DATA);
			case '3':
				return;
			}
		}
}

void showAdministratorMenu(Administrator admin)
{
	char choice = '0';
	vector<Question> a;

	system("cls");
	cout << "-------ADMINISTRATOR MENU--------" << endl;
	cout << "---------------------------------" << endl;
	cout << "| 1. Change password\t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "| 2. Edit user's info\t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "| 3. Edit question list\t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "| 4. Exit\t\t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "SELECT YOUR OPTION" << endl;

	while (choice < '1' || choice > '4')
		if (_kbhit())
		{
			choice = _getch();

			switch (choice)
			{
			case '1':
				admin.edit(ADMINISTRATOR_PATH_DATA);
				Sleep(1000);
				showAdministratorMenu(admin);
				break;
			case '2':
				editPlayer(PLAYER_PATH_DATA);
				Sleep(1000);
				showAdministratorMenu(admin);
				break;
			case '3':
				editQuestionList(a);
				Sleep(1000);
				showAdministratorMenu(admin);
				break;
			case '4':
				login();
				break;
			}
		}
}

void showPlayerMenu(Player player)
{
	char choice = '0';
	vector<Question> a;

	system("cls");
	cout << " -----------PLAYER MENU----------" << endl;
	cout << " --------------------------------" << endl;
	cout << "| 1. Start game\t\t\t|" << endl;
	cout << " --------------------------------" << endl;
	cout << "| 2. Change password\t\t|" << endl;
	cout << " --------------------------------" << endl;
	cout << "| 3. Leaderboard\t\t|" << endl;
	cout << " --------------------------------" << endl;
	cout << "| 4. Help & info\t\t|" << endl;
	cout << " --------------------------------" << endl;
	cout << "| 5. Exit\t\t\t|" << endl;
	cout << " --------------------------------" << endl;
	cout << "SELECT YOUR OPTION" << endl;

	while (choice < '1' || choice > '5')
		if (_kbhit())
		{
			choice = _getch();

			switch (choice)
			{
			case '1':
				startGame(player);
				break;
			case '2':
				player.editPlayer(PLAYER_PATH_DATA);
				Sleep(1000);
				showPlayerMenu(player);
				break;
			case '3':
				showLeaderboard();
				showPlayerMenu(player);
				break;
			case '4':
				showHelp();
				showPlayerMenu(player);
				break;
			case '5':
				login();
				break;
			}
		}
}

vector<string> loadTopicList(string fileName)
{
	ifstream fin(fileName);
	vector<string> topics;
	string topic;
	if (fin.is_open() == false)
	{
		cout << "Cannot open file! " << fileName;
		return topics;
	}

	while (!fin.eof())
	{
		getline(fin, topic);
		topics.push_back(topic);
	}

	fin.close();

	return topics;
}

void showTopicMenu(vector<string> topic)
{
	system("cls");
	cout << "---------------TOPIC-------------" << endl;
	cout << "---------------------------------" << endl;
	
	for (int i = 0; i < topic.size(); i++)
	{
		cout << "| " << i + 1 << ". " << left << setw(27) << topic[i] <<  "|" << endl;
		cout << "---------------------------------" << endl;
	}

	cout << "SELECT YOUR TOPIC AND PRESS ENTER" << endl;
}

void startGame(Player player)
{
	vector<Question> question;
	vector<string> topics = loadTopicList(TOPIC_PATH_DATA);
	string choiceString;
	char answer = '0', diff = '1';
	int topic = 0, point = 0;

	for (diff; diff <= '3'; diff++)
	{
		question.clear();
		showTopicMenu(topics);

		while (topic == 0)
		{
			cin >> choiceString;
			if (checkDigitString(choiceString))
				topic = stoi(choiceString);
			cout << "Please select again!" << endl;
		}

		loadQuestionListWithTopicAndDifficulty(QUESTION_PATH_DATA, question, topics[topic - 1.0], diff);

		for (int i = 0; i < question.size(); i++)
		{
			system("cls");
			question[i].print();
			cout << "Your answer is: ";
			while (answer < 'a' || answer > 'd')
				if (_kbhit())
				{
					answer = _getch();
					cout << (char)(answer - 32) << endl;
					break;
				}
			if (question[i].checkAnswer(answer))
			{
				cout << "Congrats. You are correct!" << endl;
				question[i].addPoint(point);
			}
			else
			{
				cout << "You are wrong :(" << endl;
				cout << "The correct answer is: " << question[i].correctAnswer() << endl;
				Sleep(500);
				cout << "GAME OVER. Your score is: " << point << endl;
				player.saveScore(point);
				login();
			}
			answer = '0';
			cin.clear();
			Sleep(1000);
		}
	}
	cout << "CONGRATULATION! YOU HAVE WON THE GAME" << endl;
	cout << "Your score is: " << point << endl;
	player.saveScore(point);
	login();
}

void showHelp()
{
	cout << "-----------INSTRUCTIONS----------" << endl;
	cout << "---------------------------------" << endl;
	cout << "- When playing the game, just press the corresponding key on the keyboard" << endl
		<< "to choose the option you want. However, there is an only exception, which " << endl
		<< "is the topic, you have to type in the number of the topic and then press Enter" << endl;
	cout << "- After finishing the game, whether you win or lost, your score will be automatically saved." << endl;
	system("pause");
}

void showLeaderboard()
{
	vector<Player> player;

	loadPlayerList(PLAYER_PATH_DATA, player);

	for (int i = 0; i < player.size() - 1; i++)
		for (int j = i; j < player.size(); j++)
			if (player[i].getScore() < player[j].getScore())
				swap(player[i], player[j]);

	system("cls");
	cout << "-----------LEADERBOARD-----------" << endl;
	cout << "---------------------------------" << endl;

	for (int i = 0; i < player.size(); i++)
	{
		cout << "| " << i + 1 << ". " << left << setw(21) << player[i].getUserName() << " | " << right << setw(3) << player[i].getScore() << "|" << endl;
		cout << "---------------------------------" << endl;
	}
	system("pause");
}