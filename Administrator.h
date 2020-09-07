#ifndef _ADMINISTRATOR_H_
#define _ADMINISTRATOR_H_
#include "Player.h"
class Administrator : public Player
{
public:
	
};
void editPlayer(string filename);
void saveAdministratorList(string filename, vector<Administrator> admins);
void loadAdministratorList(string filename, vector<Administrator>& admins);

#endif // !_ADMINISTRATOR_H_
