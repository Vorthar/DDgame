#include "stdafx.h"
#include "AbilityScores.h"


AbilityScores::AbilityScores(){
	for (int i = 0; i < 6; i++) setAScore(i, 8);
}
AbilityScores::~AbilityScores(){
}

int AbilityScores::getAScore(int index){
	return aScores[index];
}
void AbilityScores::setAScore(int index, int value){
	aScores[index] = value;
}

int AbilityScores::getAMod(int index){
	return (getAScore(index)-10)/2;
}
