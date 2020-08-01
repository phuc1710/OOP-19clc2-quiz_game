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
	
	friend bool saveListAnswer(string FilePath, Answer answer[4]);
	friend bool loadListAnswer(string FilePath, Answer answer[4]);
	friend void editListAnswer(string FilePath, Answer answer[4]);
};

#endif // !_ANSWER_H_