#define _CRT_SECURE_NO_WARNINGS
#ifndef _SUPPORT_FUNCTION_H_
#define _SUPPORT_FUNCTION_H_
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> //check memory leak library

#define QUESTION_PATH_DATA "data/QuestionList.txt"
#define PLAYER_PATH_DATA "data/PlayerList.bin"
#define ADMINISTRATOR_PATH_DATA "data/AdministratorList.bin"
#define TOPIC_PATH_DATA "data/TopicList.txt"

using namespace std;

class Random
{
public:
	Random();
	int next();
	int next(int num);
};

void randomChoice(char choices[4]);
void loadTopicList(string FilePath, vector <string>& TopicList);
void saveTopicList(string FilePath, vector <string> TopicList);

#endif // !_SUPPORTFUNCTION_H_



