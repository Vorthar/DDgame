#include "stdafx.h"
#include "Item.h"


Item::Item(){
}

int Item::getAMT()
{
	return amt;
}
void Item::setAMT(int Amt) {
	amt = Amt;
}
void Item::raiseAMT(int delta) {
	setAMT(getAMT() + delta);
}

float Item::getCost() {
	return cost;
}
void Item::setCost(float Cost) {
	cost = Cost;
}

float Item::getWeight()
{
	return weight;
}
void Item::setWeight(float Weight) {
	weight = Weight;
}

string Item::getName(){
	return name;
}
void Item::setName(string Name) {
	name = Name;
}

string Item::getDesc() {
	return description;
}
void Item::setDesc(string Desc) {
	description = Desc;
}

bool Item::isEquipped()
{
	return equipped;
}
void Item::setEquipped(bool Value) {
	equipped = Value;
}

bool Item::isEquippable() {
	return isArmor() || isWeapon();
}







