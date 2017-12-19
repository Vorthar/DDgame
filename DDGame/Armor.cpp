#include "stdafx.h"
#include "Armor.h"


Armor::Armor(){
}
Armor::~Armor(){
}
Armor::Armor(string Name, string Desc, float Weight, float Cost, int BaseAC, int Type, int Str, bool Stealthy){
	setName(Name);
	setDesc(Desc);
	setWeight(Weight);
	setAMT(0);
	setCost(Cost);
	setBaseAC(BaseAC);
	setType(0);
	switch (getType()) {
	case 0:
		setMaxDexBonus(5);
		break;
	case 1:
		setMaxDexBonus(2);
		break;
	case 2:
		setMaxDexBonus(0);
		break;
	case 3:
		setMaxDexBonus(0);
		break;
	default:
		setMaxDexBonus(5);
	}
	setShield(false);
	setStrRqrmnt(Str);
	setStealthiness(Stealthy);
}
Armor::Armor(string Name,string Desc,float Weight,float Cost, int BaseAC, int Type, int Str, bool Stealthy, bool is_Shield){
	setName(Name);
	setDesc(Desc);
	setWeight(Weight);
	setAMT(0);
	setCost(Cost);
	setBaseAC(BaseAC);
	setType(0);
	switch (getType()) {
		case 0:
			setMaxDexBonus(5);
			break;
		case 1:
			setMaxDexBonus(2);
			break;
		case 2:
			setMaxDexBonus(0);
			break;
		case 3:
			setMaxDexBonus(0);
			break;
		default:
			setMaxDexBonus(5);
	}
	setStrRqrmnt(Str);
	setShield(is_Shield);
	setStealthiness(Stealthy);
}

int Armor::getBaseAC(){
	return baseAC;
}
void Armor::setBaseAC(int value){
	baseAC = value;
}

int Armor::getMaxDexBonus(){
	return maxDexBonus;
}
void Armor::setMaxDexBonus(int value){
	maxDexBonus = value;
}

int Armor::getType(){
	return type;
}
void Armor::setType(int value) {
	type = value;
}

int Armor::getStrRqrmnt(){
	return strRqrmnt;
}
void Armor::setStrRqrmnt(int value) {
	strRqrmnt = value;
}

bool Armor::is_Stealthy(){
	return stealthy;
}
void Armor::setStealthiness(bool value) {
	stealthy = value;
}


bool Armor::is_Shield() {
	return isShield;
}
void Armor::setShield(bool value) {
	isShield = value;
}

bool Armor::isArmor(){
	return true;
}
bool Armor::isWeapon(){
	return false;
}

void Armor::Equip(ArmorClass AC, int dexScore, int strScore){
	setEquipped(true);
	AC.update(this, dexScore);
}





