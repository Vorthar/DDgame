#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(){
}
Weapon::~Weapon(){
}
Weapon::Weapon(string Name, string Desc, float Weight, float Cost, int DMGDieAmt, int DMGDieSize, int DMGType, int Range, bool* Prop){
	setName(Name);
	setDesc(Desc);
	setWeight(Weight);
	setAMT(0);
	setCost(Cost);
	setDMGDieAmt(DMGDieAmt);
	setDMGDieSize(DMGDieSize);
	setDMGType(DMGType);
	setRange(Range);
	for (int i = 0; i < 12; i++) setProperty(i, Prop[i]);
}

int Weapon::getDMGDieAmt(){
	return dmgDieAmt;
}
void Weapon::setDMGDieAmt(int value) {
	dmgDieAmt = value;
}

int Weapon::getdmgDieSize(){
	return dmgDieSize;
}
void Weapon::setDMGDieSize(int value) {
	dmgDieSize = value;
}

int Weapon::getDMGType(){
	return dmgType;
}
void Weapon::setDMGType(int value){
	dmgType = value;
}

bool Weapon::getProperty(int index) {
	return properties[index];
}
void Weapon::setProperty(int index, bool value){
	properties[index] = value;
}

int Weapon::getRange(int index) {
	return range;
}
void Weapon::setRange(int value){
	range = value;
}

bool Weapon::isWeapon() {
	return true;
}
bool Weapon::isArmor() {
	return false;
}

void Weapon::Equip(ArmorClass AC, int dexScore, int strScore)
{
}
