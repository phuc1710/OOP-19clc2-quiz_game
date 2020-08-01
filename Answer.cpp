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

void Answer::print()
{
	cout << this->_choice << ". " << this->_answer;
}

bool saveListAnswer(string FilePath, Answer answer[4])
{
	ofstream fout(FilePath);

	if (!fout.is_open())
		return false;
	for (int i = 0; i < 4; ++i)
	{
		fout << answer[i]._answer << endl;
		fout << answer[i]._status << endl;
	}

	fout.close();
	return true;

}

bool loadListAnswer(string FilePath, Answer answer[4])
{
	ifstream fin(FilePath);

	if (!fin.is_open())
		return false;
	char choices[4];
	randomChoice(choices);
	for (int i = 0; i < 4; i++)
	{
		fin >> answer[i]._answer;
		answer[i]._choice = choices[i];
		fin >> answer[i]._status;
	}

	fin.close();
	return true;
}

void editListAnswer(string FilePath, Answer answer[4])
{
	Answer answers[4];
	loadListAnswer(FilePath, answers);
	for (int i = 0; i < 4; i++)
	{
		bool choice;
		cout << "Answer " << i + 1 << ": " << answers[i]._answer << endl
			<< "Do you want to edit this answer?(0/1)" << endl;
		cin >> choice;
		if (!choice)
			continue;
		string new_answer;
		cout << "Enter new answer: ";
		cin.ignore();
		getline(cin, new_answer, '\n');
		answers[i]._answer = new_answer;
	}
	int pos;
	cout << "The right answer is answer number: "; 
	cin >> pos;
	for (int i = 0; i < 4; i++)
	{
		if (i == pos - 1)
			answers[i]._status = 1;
		answers[i]._status = 0;
	}
	saveListAnswer(FilePath, answers);
}


