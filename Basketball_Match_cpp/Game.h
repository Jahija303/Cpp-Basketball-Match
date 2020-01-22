#pragma once
#include "Club.h"

class Game
{
private:
	char date[12];
	Club home;
	Club away;
	static int pointsHome;
	static int pointsAway;
public:
	Game();
	void setDate();
	void setHome();
	void setAway();
	char* getDate();
	Club& getHome();
	Club& getAway();
	friend std::istream& operator>>(std::istream& stream, Game& game);
	friend std::ostream& operator<<(std::ostream& stream, Game& game);
	void operator++();
	void operator++(int);
	void operator!();
	~Game();
};

