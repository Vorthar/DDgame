#include "stdafx.h"
#include "Speed.h"


Speed::Speed(){
}
Speed::~Speed(){
}

int Speed::getSpeed(){
	return spd;
}
void Speed::setSpeed(unsigned int value)
{
	spd = value;
}
