#include "Club.h"
#include <iostream>
using std::cin;
using std::cout;

Club::Club()
{
}

void Club::setClubname()
{
	cout << "\tClub name: ";
	cin.getline(this->clubname, 25);
	cout << "\n";
}

void Club::setPlayer()
{
	Player p;
	cin >> p;
	this->players.push_back(p);
}

void Club::setDefault()
{
	strcpy_s(this->clubname, "Zenica Bulls");
	Player temp;
	temp.setDef("Loren", "Quack", PG, 0);
	this->players.push_back(temp);
	temp.setDef("Farris", "Walker", SG, 0);
	this->players.push_back(temp);
	temp.setDef("Nick", "Back", F, 0);
	this->players.push_back(temp);
	temp.setDef("April", "Class", SF, 0);
	this->players.push_back(temp);
	temp.setDef("Rose", "Knight", C, 0);
	this->players.push_back(temp);

}

char* Club::getClubname()
{
	return this->clubname;
}

vector<Player>& Club::getPlayers()
{
	return this->players;
}

Club::~Club()
{
}

std::istream& operator>>(std::istream& stream, Club& club)
{
	club.setClubname();
	for (unsigned int i = 0; i < 5; i++) {
		cout << "\n";
		cout << "\tEnter Player " << i + 1 << " > \n";
		club.setPlayer();
	}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Club& club)
{
	stream << "-----------------\n";
	stream << "Club Name: " << club.getClubname() << "\n";
	stream << "Players: \n";
	for (unsigned int i = 0; club.getPlayers().size(); i++) {
		stream << i + 1 << ". " << club.getPlayers()[i] << "\n";
	}
	return stream;
}
