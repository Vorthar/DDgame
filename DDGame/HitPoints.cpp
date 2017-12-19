#include "stdafx.h"
#include "HitPoints.h"


HitPoints::HitPoints(){
}
HitPoints::~HitPoints(){
}

int HitPoints::getHPmax(){
	return hpMax;
}
void HitPoints::setHPmax(int value) {
	hpMax = value;
}

int HitPoints::getHP(){
	return hp;
}
void HitPoints::setHP(int value){
	hp = value;
}

void HitPoints::setHDie(int number,int value){
	HDieAmt.push_back(number);
	HDieSize.push_back(value);
}
void HitPoints::setcHDie(int value){
	cHDie.push_back(value);
}


void HitPoints::addHitDice(string name,int conScore){
	bool notDone = true;
	int number = 1;
	string response;
	while (notDone) {
		constructHitDie(name,number);
		number++;
		cout << "\nDoes " << name << " have another set of hit dice (Y: Yes N: No)? ";
		cin >> response;
		while (response != "Y" && response != "N") {
			cout << "Please input only Y or N: ";
			cin >> response;
			while (cin.fail()) {
				cout << "Please use a valid input: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> response;
			}
		}
		if (response == "N") notDone = !notDone;
	}
	calcHPmax(conScore);
	setHP(getHPmax());
}
void HitPoints::constructHitDie(string name,int number){
	int hDie[2];
	cout << "\nFor Hit Die " << number << " please input the # of Hit Dice "<<name<<" has: ";
	cin >> hDie[0];
	while (cin.fail()) {
		cout << "Please use a valid input: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> hDie[0];
	}
	cout << "Please input the max value of this Hit Dice: ";
	cin >> hDie[1];
	while (cin.fail()) {
		cout << "Please use a valid input: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> hDie[1];
	}
	setHDie(hDie[0], hDie[1]);
	setcHDie(hDie[0]);
}
void HitPoints::calcHPmax(int conScore){
	int total=0;
	for (int i = 0; i < (int)(HDieSize.size()); i++) {
		total = total + ((int)(HDieAmt.at(i) * ((float)(HDieSize.at(i) / 2) + conScore)));
	}
	setHPmax(total);
}


