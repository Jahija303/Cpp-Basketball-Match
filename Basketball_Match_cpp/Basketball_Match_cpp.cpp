#include <iostream>
#include "Game.h"
#include <ctime>
#include <stdlib.h>
#include "Windows.h"
using std::cout;
using std::cin;

int main()
{
	Game g;
	cin >> g;
	int x, firstOffense;
	srand(time(NULL));
	x = rand() % 2;
	firstOffense = x;
	cout << "\t";
	system("pause");
	system("cls");
	cout << "\tFIRST QUARTER > \n";
	cout << "\n";
	for (unsigned int i = 0; i < 20; i++) {
		if (x == 0) {
			++g;
			x++;
			Sleep(1000);
		}
		else {
			g++;
			x--;
			Sleep(1000);
		}
	}
	cout << g;
	cout << "\t";
	system("pause");
	system("cls");

	x = (firstOffense + 1) % 2;
	cout << "\tSECOND QUARTER > \n";
	cout << "\n";
	for (unsigned int i = 0; i < 20; i++) {
		if (x == 0) {
			++g;
			x++;
			Sleep(1000);
		}
		else {
			g++;
			x--;
			Sleep(1000);
		}
	}
	cout << g;
	cout << "\t";
	system("pause");
	system("cls");

	x = (firstOffense + 1) % 2;
	cout << "\tTHIRD QUARTER > \n";
	cout << "\n";
	for (unsigned int i = 0; i < 20; i++) {
		if (x == 0) {
			++g;
			x++;
			Sleep(1000);
		}
		else {
			g++;
			x--;
			Sleep(1000);
		}
	}
	cout << g;
	cout << "\t";
	system("pause");
	system("cls");

	x = firstOffense;
	cout << "\tFINAL QUARTER > \n";
	cout << "\n";
	for (unsigned int i = 0; i < 20; i++) {
		if (x == 0) {
			++g;
			x++;
			Sleep(1000);
		}
		else {
			g++;
			x--;
			Sleep(1000);
		}
	}
	cout << g;
	!g;
	cout << "\t";
	system("pause");
	system("cls");

	return 0;
}
