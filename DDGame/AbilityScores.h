#pragma once
class AbilityScores{
	public:
		AbilityScores();
		~AbilityScores();

		int getAScore(int index);
		void setAScore(int index, int value);

		int getAMod(int index);
	private:
		int aScores[6];

};

