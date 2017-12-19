#pragma once
#include "AbilityScores.h"
#include "ArmorClass.h"
#include "Equipment.h"
#include "HitPoints.h"
#include "Size.h"
#include "Speed.h"
#include "Proficiency.h"
#include "Vision.h"

#include <iostream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::numeric_limits;
using std::streamsize;
class Creature{
public:
	Creature();
	Creature(string theName, HitPoints theHP, AbilityScores theScores, ArmorClass theAC, Speed theSPD, Vision theVision[7], Proficiency aProf[3], Proficiency wProf[37], Proficiency sProf[6], Proficiency theSkills[17], Proficiency tProf[39]);
	~Creature();

	string getName();
	string getCreatureType();
	string getAlignment();
private:

	AbilityScores aScores;
	ArmorClass ac; //need to wait til eqp implemented
	Equipment eqp;
	HitPoints hp;
	Proficiency armorProf[3];
	Proficiency weaponProf[37];
	Proficiency saveProf[6]; //42 languages
	Proficiency skills[17]; /*Acrobatics Arcana  Athletics       Deception
							History    Insight Intimidation    Investigation
							Medicene   Nature  Perception      Performance
							Persuasion Religon Sleight of Hand Stealth
							Survival*/
	Proficiency toolProf[39];
	Size size;
	Speed spd; 
	string name;
	string creaturetype;
	string alignment;
	Vision vis[6]; /*Blindsight, Normal, Darkvision, Superior, Truesight, Devil's*/

	void promptforStats();
	void setName();
	void setCreatureType();
	void setAlignment();
	void setVision();
	
};

