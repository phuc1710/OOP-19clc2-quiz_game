#define _CRT_SECURE_NO_WARNINGS
#ifndef _SUPPORT_FUNCTION_H_
#define _SUPPORT_FUNCTION_H_
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> //check memory leak library

#define PATH_DATA "C:/Users/David/Documents/GitHub/OOP-19clc2-quiz_game/data/"

using namespace std;

class Random
{
public:
	Random();
	int next();
	int next(int num);
};

void randomChoice(char choices[4]);
string convertIntToString(int num);
string creatDirectoryToAnswerFile(int QuesNum, string topic, int difficulty);

#endif // !_SUPPORTFUNCTION_H_



