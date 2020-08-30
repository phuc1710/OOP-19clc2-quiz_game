#ifndef _QUESTION_H_
#define _QUESTION_H_

#include "Answer.h"
class Question
{
private:
	char _diff;
	string _topic;
	int _point; // diff = 1(1 - 3), diff = 2(4 - 6), diff = 3(7 - 9)
	string _ques;
	Answer _answers[4];
public:
	void print();
	Question& create(string topic = "", char diff = ' ');
	friend void loadQuestionList(string FilePath, vector <Question>& QuestionList);
	friend void loadQuestionListWithTopicAndDifficulty(string FilePath, vector <Question>& QuestionList, string topic, char diff);
	friend void saveQuestionList(string FilePath, vector <Question> QuestionList);
	friend void editQuestionList(vector <Question>& QuestionList);
};

void createTopic();

#endif // !_QUESTION_H_

