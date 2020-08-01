#define _CRT_SECURE_NO_WARNINGS
#ifndef _SUPPORT_FUNCTION_H_
#define _SUPPORT_FUNCTION_H_
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <vector>

#define PATH_DATA "C:/Users/David/source/repos/Quiz/data/"

using namespace std;

char random(char choices[4]);
string convertIntToString(int num);
string creatDirectoryToAnswerFile(int QuesNum, string topic, int difficulty);
#endif // !_SUPPORTFUNCTION_H_



