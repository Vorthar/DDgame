#pragma once
class Creature{
public:
	Creature();
	~Creature();
private:
	int hp;
	int ac;
	int movement;
	int aScores[6];
	int skills[17]; /*Acrobatics Arcana  Athletics       Deception
                      History    Insight Intimidation    Investigation
					  Medicene   Nature  Perception      Performance 
					  Persuasion Religon Sleight of Hand Stealth 
					  Survival*/
};

