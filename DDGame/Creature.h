#pragma once
#include "Proficiency.h"
#include "Vision.h"
#include "AbilityScores.h"
#include "ArmorClass.h"
#include "Speed.h"
#include "HitPoints.h"
#include "Equipment.h"
#include <string>

class Creature{
public:
	Creature();
	~Creature();
private:

	string name;
	HitPoints hp;
	AbilityScores aScores;
	ArmorClass ac;
	Speed spd;
	Vision vis[7]; /*Blinded, Normal, Darkvision, Superior, Truesight, Devil's*/

	Proficiency armorProf[3];
	Proficiency weaponProf[37];
	Proficiency saveProf[6]; //42 languages
	Proficiency skills[17]; /*Acrobatics Arcana  Athletics       Deception
							  History    Insight Intimidation    Investigation
							  Medicene   Nature  Perception      Performance 
							  Persuasion Religon Sleight of Hand Stealth 
							  Survival*/
	Proficiency toolProf[39];

	Equipment eqp;

	
	
};

