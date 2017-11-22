#pragma once
class ArmorClass{
	public:
		ArmorClass();
		~ArmorClass();

		int getAC();
		void setAC(int value);
	private:
		unsigned int ac;
};

