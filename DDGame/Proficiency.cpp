#include "stdafx.h"
#include "Proficiency.h"

bool Proficiency::isProf(){
	return hasProf;
}

void Proficiency::setProf(bool value){
	hasProf = value;
}

int Proficiency::getBonus(){
	return bonus;
}

void Proficiency::setBonus(int value){
	bonus = value;
}

int Proficiency::getProfBonus(int level){
	int prof = 0;
	if (level < 5) prof = 2;
	else if (level < 9) prof = 3;
	else if (level < 13) prof = 4;
	else if (level < 17) prof = 5;
	else prof = 6;

	if (isProf()) return getBonus()+prof;
	else return getBonus();
}
