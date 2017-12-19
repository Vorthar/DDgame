#include "stdafx.h"
#include "AbilityScores.h"


AbilityScores::AbilityScores(){
	for (int i = 0; i < 6; i++) setAScore(i, 8);
}
AbilityScores::~AbilityScores(){
}
AbilityScores::AbilityScores(int theScores[6], int size){
	for (int i = 0; i < 6; i++) setAScore(i, theScores[i]);
	setEncumberance(size);
	setCarryCapacity(size);
}

int AbilityScores::getAScore(int index){
	return aScores[index];
}
void AbilityScores::setAScore(int index, int value){
	aScores[index] = value;
}

float AbilityScores::getCarryCapacity(){
	return carryCapacity;
}
void AbilityScores::setCarryCapacity(int size) {
	if (size >= 0) carryCapacity = float(getAScore(0) * 15 * pow(2, size));
	else if (size == -1) carryCapacity = float(getAScore(0) * 15);
	else if (size == -2) carryCapacity = float(getAScore(0) * 15 / 2);
	else {
		cout << "<Warning: Invalid size>";
		carryCapacity = 0;
	}
}

float * AbilityScores::getEncumberance(){
	return encumb;
}
void AbilityScores::setEncumberance(int size) {
	encumb[0] = float(getAScore(0) * 5);
	if (getAScore(0) * 10 > getCarryCapacity()) encumb[1] = getCarryCapacity();
	else encumb[1] = float(getAScore(0) * 10);
}

int AbilityScores::getAMod(int index){
	return (getAScore(index)-10)/2;
}

void AbilityScores::setStuff(string name, int size){
	setAScores(name);
	setEncumberance(size);
	setCarryCapacity(size);
}
void AbilityScores::setAScores(string name) {
	int value;
	cout << "\n";
	for (int i = 0; i < 6; i++) {
		cout << "Please input " << name << "'s " << getScoreName(i) << ": ";
		cin >> value;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "An integer is required: ";
			cin >> value;
		}
		setAScore(i, value);
	}
}
string AbilityScores::getScoreName(int index) {
	switch (index) {
	case 0:
		return "Strength";
		break;
	case 1:
		return "Dexterity";
		break;
	case 2:
		return "Constitution";
		break;
	case 3:
		return "Intelligence";
		break;
	case 4:
		return "Wisdom";
		break;
	case 5:
		return "Charisma";
		break;
	default:
		return "<Warning: Incorrect Input>";
		break;
	}
}
