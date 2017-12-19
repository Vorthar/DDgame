#include "stdafx.h"
#include "ArmorClass.h"


ArmorClass::ArmorClass(){
}
ArmorClass::~ArmorClass(){
}

int ArmorClass::getAC(){
	return ac;
}
void ArmorClass::setAC(int value){
	ac = value;
}

void ArmorClass::update(Armor* theArmor, int dexScore){
	int bonus;
	if (theArmor->getMaxDexBonus() <= dexScore) bonus = theArmor->getMaxDexBonus();
	else bonus = dexScore;
	if (theArmor->getName() == "Shield"/*&&theEquipment does not include an already equipped shield*/) setAC(getAC() + 2);
	else setAC(theArmor->getBaseAC() + bonus);
}
