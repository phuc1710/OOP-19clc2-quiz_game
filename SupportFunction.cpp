#include "SupportFunction.h"

char random(char choices[4])
{
	srand(time(NULL));
	int check(0);
	char ran_char;
	do
	{
		check = 0;
		ran_char = 65 + rand() % 4;
		for (int i = 0; i < 3; i++)
			if (ran_char == choices[i])
				check++;
	} while (check != 0);
	return ran_char;
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

