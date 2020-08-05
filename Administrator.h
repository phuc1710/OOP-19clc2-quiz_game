#ifndef _ADMINISTRATOR_H_
#define _ADMINISTRATOR_H_
#include "Player.h"
class Administrator : public Player
{
public:
	
};
void editPlayer(string filename);
void saveAdministratorList(string filename, Administrator*& admins, const int n);
void loadAdministratorList(string filename, Administrator*& admins, int& n);

#endif // !_ADMINISTRATOR_H_
