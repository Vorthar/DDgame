#include "stdafx.h"
#include "HitPoints.h"


HitPoints::HitPoints(){
}
HitPoints::~HitPoints(){
}

int HitPoints::getHPmax(){
	return hpMax;
}
void HitPoints::setHPmax(int value){
	hpMax = value;
}

int HitPoints::getHP(){
	return hp;
}
void HitPoints::setHP(int value){
	hp = value;
}
