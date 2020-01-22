#include "Player.h"
using std::cin;
using std::cout;

Player::Player()
{
	strcpy_s(this->name, "Niko");
	strcpy_s(this->lastname, "Nikic");
	this->points = 0;
	this->position = PG;
}

Player::Player(char* n, char* l, int p, Position pos)
{
	strcpy_s(this->name, n);
	strcpy_s(this->lastname, l);
	this->points = p;
	this->position = pos;
}

void Player::setName()
{
	cout << "\tFirst name: ";
	cin.getline(this->name, 20);
}

void Player::setLastname()
{
	cout << "\tLastname: ";
	cin.getline(this->lastname, 20);
}

void Player::setPoints(int points)
{
	this->points += points;
}

void Player::setPosition()
{
	std::shared_ptr<int> x = std::make_shared<int>();
	do {
		cout << "\tPosition [ 1 - PG || 2 - SG || 3 - SF || 4 - F || 5 - C ] \n";
		cout << "\tChoice > ";
		cin >> *x;
		cin.ignore();
	} while (*x > 5 || *x < 1);
	this->position = Position(*x);
}

void Player::setDef(const char* n, const char* l, Position posit, int p)
{
	strcpy_s(this->name, n);
	strcpy_s(this->lastname, l);
	this->points = p;
	this->position = posit;
}

char* Player::getName()
{
	return this->name;
}

char* Player::getLastname()
{
	return this->lastname;
}

int Player::getPoints()
{
	return this->points;
}

Position Player::getPosition()
{
	return this->position;
}

std::istream& operator>>(std::istream& stream, Player& player)
{
	player.setName();
	player.setLastname();
	player.setPosition();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Player& player)
{
	stream << player.getName() << " " << player.getLastname() << " ";
	switch (player.getPosition()) {
	case SG:
		stream << "(SG)";
		break;
	case PG:
		stream << "(PG)";
		break;
	case SF:
		stream << "(SF)";
		break;
	case F:
		stream << "(F) ";
		break;
	case C:
		stream << "(C) ";
		break;
	}
	stream << " - " << player.getPoints() << " points";
	return stream;
}

Player::~Player()
{
}