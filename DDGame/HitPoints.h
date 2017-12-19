#pragma once
#include "AbilityScores.h"
#include <string>
#include <vector>

using std::string;
using std::vector;
class HitPoints{
	public:
		HitPoints();
		~HitPoints();

		int getHPmax();
		void setHPmax(int value);

		int getHP();
		void setHP(int value);

		void setHDie(int number, int value);
		void setcHDie(int value);

		void addHitDice(string name,int conScore);
		void constructHitDie(string name,int number);
		void calcHPmax(int conScore);

	private:
		int hpMax;
		int hp;
		vector<int> HDieAmt;
		vector<int> HDieSize;
		vector<int> cHDie;

		
};

