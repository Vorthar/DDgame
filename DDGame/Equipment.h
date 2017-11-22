#pragma once
#include <vector>
#include "Item.h"

using std::vector;
class Equipment
{
public:
	Equipment();
	~Equipment();
private:
	vector<Item> equipment;
};

