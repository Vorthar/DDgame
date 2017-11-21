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
