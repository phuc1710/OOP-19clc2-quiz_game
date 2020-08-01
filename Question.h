#ifndef _QUESTION_H_
#define _QUESTION_H_

#include "Answer.h"

using namespace std;

class Question
{
private:
	char _diff;
	string _topic;
	string _ques;
	vector<Answer> _answers;
};

void loadQuestion(string FilePath, Question*& ques);

#endif // !_QUESTION_H_