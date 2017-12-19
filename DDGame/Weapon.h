#pragma once
#include "Item.h"
class Weapon : public Item{
	public:
		Weapon();
		~Weapon();
		Weapon(string Name, string Desc, float Weight, float Cost, int DMGDieAmt, int DMGDieSize, int DMGType, int Range, bool* Prop);

		int getDMGDieAmt();
		int getdmgDieSize();
		int getDMGType();
		bool getProperty(int index);
		int getRange(int index);

		bool isWeapon();
		bool isArmor();

		void Equip(ArmorClass AC, int dexScore, int strScore);

	private:
		int dmgDieAmt;
		int dmgDieSize;
		int dmgType;
		int range;
		bool properties[12]; /*Ammunition, Finesse,    Heavy,      Light,    Loading, Thrown,
							   Two-Handed, Versatile,  Improvised, Silvered, Lance,   Net*/

	protected:
		void setDMGDieAmt(int value);
		void setDMGDieSize(int value);
		void setDMGType(int value); //0: None 1: Bludgeoning 2: Piercing 3: Slashing
		void setProperty(int index, bool value);
		void setRange(int value);

};

