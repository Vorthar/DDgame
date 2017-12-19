#pragma once
class Speed{
	public:
		Speed();
		~Speed();

		int getBaseSPD();
		int getSpeed();

		void updateSpeed(float encumb[2], float cWeight);
	private:
		int basespd;
		int spd;

		void setBaseSPD(int value);
		void setSpeed(int value);
};

