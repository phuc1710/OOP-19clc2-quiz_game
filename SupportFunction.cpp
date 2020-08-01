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

string convertIntToString(int num)
{
	char c[255];
	_itoa(num, c, 10);
	return string(c);
}

string creatDirectoryToAnswerFile(int QuesNum, string topic, int difficulty)
{
	string FilePath = PATH_DATA;
	string tail;
	string q_num = convertIntToString(QuesNum);
	string d_num = convertIntToString(difficulty);
	tail = "answers/ans-" + topic + "-" + d_num + "-ques" + q_num + ".bin";
	return FilePath += tail;
}

