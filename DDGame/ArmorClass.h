#pragma once
#include"Armor.h"
class ArmorClass{
	public:
		ArmorClass();
		~ArmorClass();

		int getAC();
		void update(Armor* theItem, int dexScore);
		//stuff to do
	private:
		int ac;
		void setAC(int value);
};

