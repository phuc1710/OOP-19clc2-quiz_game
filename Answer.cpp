#include "Answer.h"

Answer::Answer()
{
	this->_answer = "...";
	this->_choice = 'A';
	this->_status = 0;
}

Answer::Answer(string ans, char choice, bool status)
{
	this->_answer = ans;
	this->_choice = choice;
	this->_status = status;
}

Answer::Answer(const Answer& answer)
{
	this->_answer = answer._answer;
	this->_choice = answer._choice;
	this->_status = answer._status;
}

bool Answer::check(char answer)
{
	return answer - 32 == _choice && _status == true;
}

void saveAnswerList(ofstream& fout, Answer AnswerList[4])
{
	for (int i = 0; i < 4; ++i)
	{
		fout << AnswerList[i]._answer << endl;
		fout << AnswerList[i]._status << endl;
	}
}

void loadAnswerList(ifstream& fin, Answer AnswerList[4])
{
	int i = 0;
	char choices[4];
	randomChoice(choices);
	for (i; i < 4; i++)
	{
		getline(fin, AnswerList[i]._answer);
		AnswerList[i]._choice = choices[i];
		fin >> AnswerList[i]._status;
		if(i < 3)
			fin.ignore();
	}

	for (i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			if (AnswerList[i]._choice > AnswerList[j]._choice)
				swap(AnswerList[i], AnswerList[j]);
}

void editAnswerList(Answer AnswerList[4])
{
	for (int i = 0; i < 4; i++)
	{
		bool choice;
		cout << "Answer " << i + 1 << ": " << AnswerList[i]._answer << endl
			<< "Do you want to edit this answer?(0/1)" << endl;
		cin >> choice;
		if (!choice)
			continue;
		string new_answer;
		cout << "Enter new answer: ";
		cin.ignore();
		getline(cin, new_answer);
		AnswerList[i]._answer = new_answer;
	}
	int pos;
	cout << "The right answer is answer number: "; 
	for (int i = 0; i < 4; i++)
		if (AnswerList[i]._status)
			cout << AnswerList[i] << endl;
	cout << endl
		<< "Enter number of the new right number: ";
	cin >> pos;
	for (int i = 0; i < 4; i++)
	{
		if (i == pos - 1)
			AnswerList[i]._status = 1;
		else
			AnswerList[i]._status = 0;
	}
}

void createAnswerList(Answer AnswerList[4])
{
	for (int i = 0; i < 4; i++)
	{
		string new_answer;
		cout << "Enter answer " << i + 1 << ": ";
		getline(cin, new_answer);
		AnswerList[i]._answer = new_answer;
	}
	int pos;
	cout << endl
		<< "Enter number of the new right number: ";
	cin >> pos;
	for (int i = 0; i < 4; i++)
	{
		if (pos - 1 == i)
			AnswerList[i]._status = 1;
		else
			AnswerList[i]._status = 0;
	}
}

char correctChoice(Answer AnswerList[4])
{
	for (int i = 0; i < 4; i++)
		if (AnswerList[i]._status)
			return AnswerList[i]._choice;
}

ostream& operator<<(ostream& os, const Answer& answer)
{
	stringstream writer;
	writer << answer._choice << ". " << answer._answer;
	os << writer.str();
	return os;
}


