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
	friend void saveAnswerList(ofstream& fout, Answer AnswerList[4]);
	friend void loadAnswerList(ifstream& fin, Answer AnswerList[4]);
	friend void editAnswerList(Answer AnswerList[4]);
	friend void createAnswerList(Answer AnswerList[4]);
	bool check(char answer);
	friend char correctChoice(Answer AnswerList[4]);
	friend ostream& operator<< (ostream& os, const Answer& answer);
};

#endif // !_ANSWER_H_