#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
class Size{
	public:
		Size();
		~Size();

		int getSize();
		void setSize(string name);

	private:
		int size;

		void setSize(int value);
};

