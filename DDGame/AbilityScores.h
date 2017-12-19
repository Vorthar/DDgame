#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;
class AbilityScores{
	public:
		AbilityScores();
		~AbilityScores();
		AbilityScores(int theScores[6], int size);

		int getAScore(int index);
		int getAMod(int index);

		void setStuff(string name, int size);
		
		string getScoreName(int index);
		float getCarryCapacity();
		float* getEncumberance();
		
	private:
		int aScores[6];
		float carryCapacity;
		float encumb[2];

		void setAScore(int index, int value);
		void setAScores(string name);
		void setEncumberance(int size);
		void setCarryCapacity(int size);

};

