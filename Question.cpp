#include "Question.h"

bool loadQuestionList(string FilePath, Question*& ques)
{
    ifstream fin(FilePath, ios::binary);
    int n;
	if (!fin.is_open())
		return false;
    fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> ques[i]._diff;
        fin >> ques[i]._topic;
        fin >> ques[i]._ques;
        loadListAnswer(FilePath, ques[i]._answers);
	}

	fin.close();
	return true;
}

bool saveQuestionList(string FilePath, Question*& ques, int n)
{
    ofstream fout(FilePath, ios::binary);
	if(!fout.is_open())
		return false;
	fout << n;
	for(int i =0; i < n; i++)
	{
		fout << ques[i]._diff;
		fout << ques[i]._topic;
		fout << ques[i]._ques;
		saveListAnswer(FilePath, ques[i]._answers);
	}
	
	fout.close();
	return true;
}

void editQuestionList(string FilePath, Question*& ques, int n)
{
	loadQuestionList(FilePath, ques);
	for (int i = 0; i < n; i++)
	{
		bool choice;
		cout << "Question " << i + 1 << ": " << ques[i]._ques << endl
			<< "Do you want to edit this question?(0/1)" << endl;
		cin >> choice;
		if (!choice)
			continue;
		string NewQuestion;
		cout << "Enter new question: ";
		cin.ignore();
		getline(cin, NewQuestion, '\n');
		ques[i]._ques = NewQuestion;
		cout << "Do you want to edit answers?(0,1)" << endl;
		cin >> choice;
		if(!choice)
			continue;
		editListAnswer(FilePath, ques[i]._answers);
	}
	saveQuestionList(FilePath, ques, n);
}