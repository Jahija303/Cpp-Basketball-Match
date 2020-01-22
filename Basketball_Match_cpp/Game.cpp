#include "Game.h"
#include <iostream>
#include "Club.h"
#include <ctime>
#include <stdlib.h>
#include <iomanip>
using std::cin;
using std::cout;

int Game::pointsHome = 0;
int Game::pointsAway = 0;

Game::Game()
{
}

void Game::setDate()
{
	cout << "\n";
	cout << "\t=========================================================\n";
	cout << "\tEnter the Date of the game > ";
	cin.getline(this->date, 12);
}

void Game::setHome()
{
	cout << "\tSet the Home Club > ";
	cin >> this->home;
}

void Game::setAway()
{
	cout << "\tSet the Guest Club > ";
	cin >> this->away;
}

char* Game::getDate()
{
	return this->date;
}

Club& Game::getHome()
{
	return this->home;
}

Club& Game::getAway()
{
	return this->away;
}

void Game::operator++()
{
	srand(time(NULL));
	int x;
	x = rand() % 4;
	if (x == 0) {
		//cout << "---------------------------\n";
		cout << "\t" << this->getHome().getClubname() << " " <<
			Game::pointsHome << ":" << Game::pointsAway << " " <<
			this->getAway().getClubname() << "\n";
		cout << "\tLost Ball - " << this->getHome().getClubname() << "\n";
		cout << "\t------------------------------------------------------\n";
	}
	else {
		Game::pointsHome += x;
		//cout << "---------------------------\n";
		cout << "\t" << this->getHome().getClubname() << " " <<
			Game::pointsHome << ":" << Game::pointsAway << " " <<
			this->getAway().getClubname() << "\n";
		int y = rand() % 5;
		this->getHome().getPlayers()[y].setPoints(x);
		cout << "\t" << this->getHome().getPlayers()[y].getName() << " "
			<< this->getHome().getPlayers()[y].getLastname() << " "
			<< x << "p\n";
		cout << "\t------------------------------------------------------\n";
	}
}

void Game::operator++(int)
{
	srand(time(NULL));
	int x;
	x = rand() % 4;
	if (x == 0) {
		//cout << "---------------------------\n";
		cout << "\t" << this->getHome().getClubname() << " " <<
			Game::pointsHome << ":" << Game::pointsAway << " " <<
			this->getAway().getClubname() << "\n";
		cout << "\tLost Ball - " << this->getAway().getClubname() << "\n";
		cout << "\t------------------------------------------------------\n";
	}
	else {
		Game::pointsAway += x;
		cout << "\t" << this->getHome().getClubname() << " " <<
			Game::pointsHome << ":" << Game::pointsAway << " " <<
			this->getAway().getClubname() << "\n";
		int y = rand() % 5;
		this->getAway().getPlayers()[y].setPoints(x);
		cout << "\t" << this->getAway().getPlayers()[y].getName() << " "
			<< this->getAway().getPlayers()[y].getLastname() << " "
			<< x << "p\n";
		cout << "\t------------------------------------------------------\n";
	}
}

void Game::operator!()
{
	int max = 0;
	int index;
	int time = 0;
	for (int i = 0; i < this->getHome().getPlayers().size(); i++) {
		if (this->getHome().getPlayers()[i].getPoints() > max) {
			max = this->getHome().getPlayers()[i].getPoints();
			index = i;
			time = 0;
		}
	}
	for (int i = 0; i < this->getAway().getPlayers().size(); i++) {
		if (this->getAway().getPlayers()[i].getPoints() > max) {
			max = this->getAway().getPlayers()[i].getPoints();
			index = i;
			time = 1;
		}
	}
	cout << "\t";
	system("pause");
	system("cls");
	if (Game::pointsAway > Game::pointsHome) {
		cout << "\tTHE WINNERS ARE " << this->getAway().getClubname() << "\n";
		cout << "\n";
	}
	else if (Game::pointsAway < Game::pointsHome) {
		cout << "\tTHE WINNERS ARE " << this->getHome().getClubname() << "\n";
		cout << "\n";
	}
	else {
		cout << "\tTHE MATCH IS A DRAW\n";
		cout << "\n";
	}

	if (time == 0) {
		cout << "\tMVP of the game is > " << this->getHome().getPlayers()[index];
		cout << "\n";
	}
	else {
		cout << "\tMVP of the game is > " << this->getAway().getPlayers()[index];
		cout << "\n";
	}

}

std::istream& operator>>(std::istream& stream, Game& game)
{
	game.setDate();
	game.setHome();
	char a;
	do {
		system("cls");
		cout << "\n";
		cout << "\t------------------------------------------------------\n";
		cout << "\tWould you like to manually enter the Away team \n";
		cout << "\t[Y] - Yes\n\t[N] - No\n\tChoice > ";
		cin >> a;
		if (a == 'Y' || a == 'y') {
			game.setAway();
			cout << "\t------------------------------------------------------\n";
			cout << "\n";
			break;
		}
		else if (a == 'N' || a == 'n') {
			game.getAway().setDefault();
			cout << "\t------------------------------------------------------\n";
			cout << "\n";
			break;
		}
		else {
			cout << "[ERROR] Incorrect Entry!\n";
			cout << "\t------------------------------------------------------\n";
			cout << "\n";
		}
	} while (a != 'N' || a != 'n' || a != 'Y' || a != 'y');
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Game& game)
{
	stream << "\n";
	stream << "\t" << game.getHome().getClubname() << " " <<
		Game::pointsHome << ":" << Game::pointsAway << " " <<
		game.getAway().getClubname() << "\n";
	stream << "\t===============================================================================================\n";
	for (unsigned int i = 0; i < game.getHome().getPlayers().size(); i++) {
		stream << "\t" << game.getHome().getPlayers()[i] << "\t\t" << game.getAway().getPlayers()[i] << "\n";
	}
	cout << "\n";
	return stream;
}



Game::~Game()
{
}
