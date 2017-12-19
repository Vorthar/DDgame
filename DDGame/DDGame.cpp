// DDGame.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Creature.h"
#include "Utilities.h"
#include <iostream>
#include <string>

void displayMenu() {
	cout << "\nWhat would you like to do? "
		 << "\n    0) Close Program"
		 << "\n    1) Create a New Character"
		 << "\n    2) Edit an Existing Character"
		 << "\nSelect an Option: ";
}

using std::string;
using std::cin;
using std::cout;
int main(){
	bool exitProgram = false;
	int response;
	Utilities Util;
	cout << "Welcome to DnD Game!\n";
	while (!exitProgram) {
		displayMenu();
		cin >> response;
		Util.checkNumericUserInput(response, 0, 2);
		if (response == 0) {
			exitProgram = true;
		}
		else if (response == 1) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			Creature theCreature = Creature();
		}
		else {

		}
		
	}
    return 0;
}