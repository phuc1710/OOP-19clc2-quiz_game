#ifndef _USER_H_
#define _USER_H_

#include "Question.h"

class User
{
private:
	string _username;
	string _password;
public:
	void setUsername(string str);
	void setPassword(string str);
	string getUserName();
	string getPassword();
};

void loadUser(string filename, User*& aUsers, int& n);
void writeUser(string filename, User* aUsers, const int n);
void editUser(string filename);

#endif // !_USER_H_