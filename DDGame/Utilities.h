#pragma once
#include <iostream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::numeric_limits;
using std::streamsize;
using std::string;
class Utilities
{
public:
	Utilities();
	~Utilities();
	void checkNumericUserInput(int &value, int lBound);
	void checkNumericUserInput(int &value, int lBound, int uBound);
	void checkYNUserInput(string value);
	void clearScreen();
};

