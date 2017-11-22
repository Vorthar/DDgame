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
void Vision::alterVis(){
	state = !state;
}

int Vision::getRange(){
	return range;
}
void Vision::setRange(int value){
	range = value;
}