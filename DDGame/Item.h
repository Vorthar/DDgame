#pragma once
#include <string>
#include "ArmorClass.h"
using std::string;

class Item{
	public:
		Item();
		virtual ~Item()=default;

		int getAMT();
		void raiseAMT(int delta);

		float getCost();
		float getWeight();
		string getDesc();
		string getName();

		bool isEquipped();
		void setEquipped(bool Value);

		virtual void Equip(ArmorClass AC, int dexScore, int strScore)=0;

		bool isEquippable();
		virtual bool isArmor() = 0;
		virtual bool isWeapon() = 0;
		
	private:
		string name;
		string description;
		int amt;
		float cost;
		float weight;
		bool equipped=false;

	protected:
		void setAMT(int Amt);
		void setCost(float Cost);
		void setWeight(float Weight);
		void setDesc(string Desc);
		void setName(string Name);
		
		
};

