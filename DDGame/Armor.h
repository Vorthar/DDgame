#pragma once
#include "Item.h"
class Armor : public Item{
	public:
		Armor();
		~Armor();
		Armor(string Name, string Desc, float Weight, float Cost, int BaseAC, int Type, int Str, bool Stealthy);
		Armor(string Name,string Desc,float Weight,float Cost, int BaseAC, int Type, int Str, bool Stealthy, bool is_Shield); //0 Light 1 Medium 2 Heavy

		int getBaseAC();
		int getMaxDexBonus();
		int getType();
		int getStrRqrmnt();
		bool is_Stealthy();
		bool is_Shield();

		bool isArmor();
		bool isWeapon();
		void Equip(ArmorClass AC, int dexScore, int strScore);
	private:
		int baseAC;
		int maxDexBonus;
		int type;
		int strRqrmnt;
		bool isShield;
		bool stealthy;

		void setBaseAC(int value);
		void setMaxDexBonus(int value);
		void setType(int value);
		void setStrRqrmnt(int value);
		void setShield(bool value);
		void setStealthiness(bool value);
		
};

