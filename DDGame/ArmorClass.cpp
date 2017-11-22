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
