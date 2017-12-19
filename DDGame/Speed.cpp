#include "stdafx.h"
#include "Speed.h"


Speed::Speed(){
}
Speed::~Speed(){
}

int Speed::getBaseSPD(){
	return basespd;
}
void Speed::setBaseSPD(int value){
	basespd = value;
}

int Speed::getSpeed(){
	return spd;
}
void Speed::setSpeed(int value){
	spd = value;
}

void Speed::updateSpeed(float encumb[2], float cWeight){
	if (cWeight>encumb[0]) {
		if (cWeight>encumb[1]) setSpeed(getBaseSPD() - 20);
		else setSpeed(getBaseSPD() - 10);
	}
	else setSpeed(getBaseSPD());
}


