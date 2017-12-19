#include "stdafx.h"
#include "Utilities.h"



Utilities::Utilities(){
}
Utilities::~Utilities(){
}

void Utilities::checkNumericUserInput(int &value, int lBound){
	while (value < lBound || cin.fail()) {
		cout << "Please choose only a valid number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> value;
	}
}
void Utilities::checkNumericUserInput(int &value, int lBound, int uBound){
	while (value < lBound || value>uBound || cin.fail()) {
		cout << "Please choose only a valid number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> value;
	}
}
void Utilities::checkYNUserInput(string value){
	while (value != "Y" && value != "N") {
		cout << "\nPlease input only Y or N: ";
		cin >> value;
	}
}

void Utilities::clearScreen(){
	cout << string(50,'\n');
}
