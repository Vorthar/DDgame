#pragma once
#include <string>
using std::string;

class Item{
public:
	Item();
	~Item();
private:
	string name;
	string description;
	unsigned int weight;
	unsigned int cost;
};

