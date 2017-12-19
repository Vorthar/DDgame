#include "stdafx.h"
#include "Creature.h"
#include <stdio.h>
#include <ctype.h>


Creature::Creature(){
	promptforStats();
}
Creature::Creature(string theName, HitPoints theHP, AbilityScores theScores, ArmorClass theAC, Speed theSPD, Vision theVision[7], Proficiency aProf[3], Proficiency wProf[37], Proficiency sProf[6], Proficiency theSkills[17], Proficiency tProf[39]){
	name = theName;
	hp = theHP;
	aScores = theScores;
	ac = theAC;
	spd = theSPD;
	for (int i = 0; i < 39; i++) {
		if (i < 3) armorProf[i] = aProf[i];
		if (i < 6) saveProf[i] = sProf[i];
		if (i < 7) vis[i] = theVision[i];
		if (i < 17) skills[i] = theSkills[i];
		if (i < 37) armorProf[i] = aProf[i];
		toolProf[i] = tProf[i];
	}
}
Creature::~Creature(){
}

string Creature::getName(){
	return name;
}
string Creature::getCreatureType(){
	return creaturetype;
}
string Creature::getAlignment(){
	return alignment;
}

void Creature::promptforStats(){
	setName();
	size.setSize(name);
	setCreatureType();
	setAlignment();
	aScores.setStuff(name,size.getSize());
	hp.addHitDice(name,aScores.getAScore(2));
	setVision();
	eqp.setEquipment(name,aScores,ac,spd);
}
void Creature::setName(){
	cout << "\nPlease input a name for the creature: ";
	std::getline(cin, name);
}
void Creature::setCreatureType(){
	cout << "\nPlease input " << name << "'s creature type: ";
	std::getline(cin, creaturetype);
}
void Creature::setAlignment(){
	cout << "\nPlease input " << name <<"'s alignment. It ought to be one of the following:\n"
		 << "\n   LG: Lawful Good   |  NG: Nuetral Good  |  CG: Chaotic Good"
		 << "\n   -------------------------------------------------------------"
		 << "\n   LN: Lawful Neutral|  N:  True Neutral  |  CN: Chaotic Neutral"
		 << "\n   -------------------------------------------------------------"
		 << "\n   LE: Lawful Evil   |  NE: Neutral Evil  |  CE: Chaotic Evil"
	   << "\n\nAlignment: ";
	cin >> creaturetype;
	while (creaturetype != "LG" && creaturetype != "NG" && creaturetype != "CG" && creaturetype != "LN" && creaturetype != "N" && creaturetype != "CN" && creaturetype != "LE" && creaturetype != "NE" && creaturetype != "CE") {
		cout << "Please select a valid alignment (The one to two letter indicator): ";
		cin >> creaturetype;
	}
	
}
void Creature::setVision(){
	bool hasDV=false;
	string response;
	string sight[6] = { "Normal Vision","Blindsight","Darkvision","Superior Darkvision","Truesight","Devil's Sight" };
	int range;
	for (int i = 0; i < 6; i++) {
		if ((i == 3 || i == 5) && !hasDV) {
			vis[i].setVis(false, 0);
		}
		else {
			cout << "\nDoes " << name << " have " << sight[i] << " (Y: Yes N: No)? ";
			cin >> response;
			while (response != "Y" && response != "N") {
				cout << "\nPlease input only Y or N: ";
				cin >> response;
			}
			if (response == "Y") {
				if (i == 1 || i==4) {
					cout << "\nWhat is the range of the creature's " << sight[i] << ": ";
					cin >> range;
					if (cin.fail()) {
						cout << "Input must be an integer. Try Again: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> range;
					}
				}
				else if (i == 0 || i == 2) {
					range = 60;
					if (i == 2) hasDV = true;
				}
				else range = 120;
				vis[i].setVis(true, range);
			}
			else vis[i].setVis(false, 0);
		}
	}
}