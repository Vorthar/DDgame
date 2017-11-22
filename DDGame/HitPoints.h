#pragma once
class HitPoints{
	public:
		HitPoints();
		~HitPoints();
		int getHPmax();
		void setHPmax(int value);
		int getHP();
		void setHP(int value);
	private:
		int hpMax;
		int hp;
};

