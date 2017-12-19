#include "stdafx.h"
#include "Vision.h"


Vision::Vision(){
}
Vision::~Vision()
{
}

bool Vision::hasVis(){
	return state;
}
void Vision::alterVis(bool value){
	state = value;
}

int Vision::getRange(){
	return range;
}
void Vision::setRange(int value){
	range = value;
}

void Vision::setVis(bool hasVis, int range) {
	alterVis(hasVis);
	setRange(range);
}