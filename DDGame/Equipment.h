#pragma once
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "AbilityScores.h"
#include "Item.h"
#include     "Armor.h"
#include     "Weapon.h"
#include "Speed.h"
#include "Utilities.h"

using std::cin;
using std::cout;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::vector;
class Equipment{
public:
	Equipment();
	~Equipment();

	void setEquipment(string name, AbilityScores theScores, ArmorClass AC, Speed& Spd);
	float getTotalWeight();
private:
	vector<Item*> equipment;
	float TotalWeight;
	Utilities Util;

	bool compare(Item* item1, Item* item2);
	bool isOverweight(float weight, float capacity);
	bool hasItem(Item* theItem);

	void addItem(Item* theitem, string name, AbilityScores theScores, ArmorClass AC, Speed& spd);
	void removeItem(string name, AbilityScores theScores, Speed& Spd, bool isReq);
	void updateTotalWeight(string name, AbilityScores theScores, Speed& Spd);
	void promptEquip(int index, int dexScore, int strScore, string YN, ArmorClass AC);
};

