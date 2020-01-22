#pragma once
#include <iostream>

enum Position { PG = 1, SG, SF, F, C };

class Player
{
private:
	char name[20];
	char lastname[20];
	int points;
	Position position;
public:
	Player();
	Player(char* n, char* l, int p, Position pos);
	void setName();
	void setLastname();
	void setPoints(int points);
	void setPosition();
	void setDef(const char* n, const char* l, Position posit, int p);
	char* getName();
	char* getLastname();
	int getPoints();
	Position getPosition();
	friend std::istream& operator>>(std::istream& stream, Player& player);
	friend std::ostream& operator<<(std::ostream& stream, Player& player);
	~Player();
};


