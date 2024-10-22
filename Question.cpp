#include "Question.h"

bool Question::checkAnswer(char answer)
{
	for (int i = 0; i < 4; i++)
		if (this->_answers[i].check(answer))
			return true;

	return false;
}

char Question::correctAnswer()
{
	return correctChoice(_answers);
}

void loadQuestionList(string FilePath, vector <Question>& QuestionList)
{
	ifstream fin(FilePath);
	if (!fin.is_open())
		return;
	while (!fin.eof())
	{
		Question question;
		fin >> question._diff;
		fin.ignore();
		getline(fin, question._topic);
		fin >> question._point;
		fin.ignore();
		getline(fin, question._ques);
		loadAnswerList(fin, question._answers);
		QuestionList.push_back(question);
	}

	fin.close();
}

void loadQuestionListWithTopicAndDifficulty(string FilePath, vector<Question>& QuestionList, string topic, char diff)
{
	ifstream fin(FilePath);
	if (!fin.is_open())
		return;
	while (!fin.eof())
	{
		Question question;
		fin >> question._diff;
		fin.ignore();
		getline(fin, question._topic);
		fin >> question._point;
		fin.ignore();
		getline(fin, question._ques);
		loadAnswerList(fin, question._answers);
		if(question._topic == topic && question._diff == diff)
			QuestionList.push_back(question);
	}

	fin.close();
}

void saveQuestionList(string FilePath, vector <Question> QuestionList)
{
	ofstream fout(FilePath);
	if (!fout.is_open())
		return;

	for (int i = 0; i < QuestionList.size(); i++)
	{
		fout << QuestionList[i]._diff << endl;
		fout << QuestionList[i]._topic << endl;
		fout << QuestionList[i]._point << endl;
		fout << QuestionList[i]._ques << endl;
		saveAnswerList(fout, QuestionList[i]._answers);
	}

	fout.close();
}

void editQuestionList(vector <Question>& QuestionList)
{
	vector<Question> Topic;
	string topic;
	char diff;
	cout << "Enter the topic of the question you want to edit: ";
	getline(cin, topic);
	cout << "Enter the difficulty of the question you want to edit: ";
	cin >> diff;
	loadQuestionListWithTopicAndDifficulty(QUESTION_PATH_DATA, Topic, topic, diff);
	loadQuestionList(QUESTION_PATH_DATA, QuestionList);
	for (int i = 0; i < Topic.size(); i++)
		cout << "Question " << i + 1 << ": " << Topic[i]._ques << endl;

	bool choice;
	int pos;
	cout << "Enter the question you want to edit?" << endl;
	cin >> pos;

	if (pos < 1 || pos > QuestionList.size())
		return;

	for (int i = 0; i < QuestionList.size(); i++)
		if (QuestionList[i]._ques == Topic[pos]._ques)
			pos = i;

	cout << "Do you want to edit question?(0,1)" << endl;
	cin >> choice;
	if (choice)
	{
		string NewQuestion;
		cout << "Enter new question: ";
		cin.ignore();
		getline(cin, NewQuestion);
		QuestionList[pos - 1]._ques = NewQuestion;
	}

	cout << "Do you want to edit point?(0,1)" << endl;
	cin >> choice;
	if (choice)
	{
		int point;
		cout << "Enter new point: ";
		cin >> point;
		QuestionList[pos - 1]._point = point;
	}

	cout << "Do you want to edit answers?(0,1)" << endl;
	cin >> choice;
	if (choice)
		editAnswerList(QuestionList[pos - 1]._answers);

	saveQuestionList(QUESTION_PATH_DATA, QuestionList);

	cin.ignore();
}

void Question::addPoint(int& point)
{
	point += _point;
	cout << "You have add " << _point << "points" << endl;
}

void createTopic()
{
	string topic;
	vector<string> TopicList;
	vector<Question> QuestionList;
	int choice;

	cout << "Enter new topic: ";
	getline(cin, topic);

	loadTopicList(TOPIC_PATH_DATA, TopicList);
	if (TopicList.size() == 0)
		TopicList.push_back(topic);
	else
	{
		int n((int)TopicList.size());
		for (int i = 0; i < n; i++)
		{
			if (topic == TopicList[i])
			{
				cout << "This topic already exist." << endl;
				return;
			}
			if (topic != TopicList[TopicList.size() - 1])
				TopicList.push_back(topic);
		}
	}
	saveTopicList(TOPIC_PATH_DATA, TopicList);

	loadQuestionList(QUESTION_PATH_DATA, QuestionList);
	cout << "How many question do you want to create in difficulty 1?(at least 5)" << endl;
	cin >> choice;
	if (choice < 5)
		choice = 5;
	for (int i = 0; i < choice; i++)
	{
		Question NewQuestion;
		NewQuestion.create(topic, '1');
		QuestionList.push_back(NewQuestion);
	}
	system("cls");
	cout << "How many question do you want to create in difficulty 2?(at least 3)" << endl;
	cin >> choice;
	if (choice < 3)
		choice = 3;
	for (int i = 0; i < choice; i++)
	{
		Question NewQuestion;
		NewQuestion.create(topic, '2');
		QuestionList.push_back(NewQuestion);
	}
	system("cls");
	cout << "How many question do you want to create in difficulty 3?(at least 2)" << endl;
	cin >> choice;
	if (choice < 2)
		choice = 2;
	for (int i = 0; i < choice; i++)
	{
		Question NewQuestion;
		NewQuestion.create(topic, '3');
		QuestionList.push_back(NewQuestion);
	}
	saveQuestionList(QUESTION_PATH_DATA, QuestionList);
}

void Question::print()
{
	cout << "Topic: " << this->_topic << endl
		<< "Difficulty: " << this->_diff << endl
		<< "Point: " << this->_point << endl
		<< this->_ques << endl;
	cout << "\t" << left << setw(30) << this->_answers[0] << this->_answers[1] << endl;
	cout << "\t" << left << setw(30) << this->_answers[2] << this->_answers[3] << endl;
}

Question& Question::create(string topic, char diff)
{
	this->_topic = topic;
	this->_diff = diff;
	cout << "Enter new question: ";
	cin.ignore();
	getline(cin, this->_ques);
	cout << "Enter new point: ";
	cin >> this->_point;
	cin.ignore();
	createAnswerList(this->_answers);
	return *this;
}
