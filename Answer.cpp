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
		fout << answer[i]._choice << endl;
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

	for (int i = 0; i < 4; i++)
	{
		fin >> answer[i]._answer;
		fin >> answer[i]._choice;
		fin >> answer[i]._status;
	}

	fin.close();
	return true;
}


