#ifndef _ANSWER_H_
#define _ANSWER_H_

#include "SupportFunction.h"

class Answer
{
private:
	char _choice;
	string _answer;
	bool _status;
public:
	Answer();	
	Answer(string ans, char choice, bool status = 0);
	Answer(const Answer& answer);

	void print();
	
	friend bool saveAnswerList(string FilePath, Answer answer[4]);
	friend bool loadAnswerList(string FilePath, Answer answer[4]);
	friend void editAnswerList(string FilePath, Answer answer[4]);
};

#endif // !_ANSWER_H_