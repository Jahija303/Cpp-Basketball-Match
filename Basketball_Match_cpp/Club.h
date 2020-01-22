#pragma once
#include <vector>
#include "Player.h"
using std::vector;

class Club
{
private:
	char clubname[25];
	vector<Player> players;
public:
	Club();
	void setClubname();
	void setPlayer();
	void setDefault();
	char* getClubname();
	vector<Player>& getPlayers();
	friend std::istream& operator>>(std::istream& stream, Club& club);
	friend std::ostream& operator<<(std::ostream& stream, Club& club);
	~Club();
};

