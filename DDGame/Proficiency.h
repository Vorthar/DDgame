#pragma once
struct Proficiency{
	public:
		bool isProf();
		void setProf(bool value);
		int getBonus();
		void setBonus(int value);
	private:
		bool hasProf;
		int bonus;

};

