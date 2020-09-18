#include "SupportFunction.h"

Random::Random()
{
	srand(time(NULL));
}

int Random::next()
{
	return rand();
}

int Random::next(int num)
{
	if (num < 2)
		return -1;
	return rand() % num;
}

bool checkDigitString(string digitString)
{
	for (int i = 0; i < digitString.size(); i++)
		if (!isdigit(digitString[i]))
			return false;

	return true;
}

void randomChoice(char choices[4])
{
	Random random;
	int check(0);
	char ran_char;
	for (int i = 0; i < 4; i++)
	{
		do
		{
			check = 0;
			ran_char = 65 + random.next(4);
			for (int i = 0; i < 3; i++)
				if (ran_char == choices[i])
					check++;
		} while (check != 0);
		choices[i] = ran_char;
	}
}

void loadTopicList(string FilePath, vector<string>& TopicList)
{
	ifstream fin(FilePath);

	if (!fin.is_open())
		return;
	while (!fin.eof())
	{
		string topic;
		fin >> topic;
		TopicList.push_back(topic);
	}

	fin.close();
}

void saveTopicList(string FilePath, vector<string> TopicList)
{
	ofstream fout(FilePath);

	if (!fout.is_open())
		return;
	for (int i = 0; i < TopicList.size(); i++)
		fout << TopicList[i] << endl;

	fout.close();
}



