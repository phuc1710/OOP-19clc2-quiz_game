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
	Answer _answers[4];
	friend bool loadQuestionList(string FilePath, Question*& ques);
	friend bool saveQuestionList(string FilePath, Question*& ques, int n);
	friend void editQuestionList(string FilePath, Question*& ques, int n);
};

#endif // !_QUESTION_H_