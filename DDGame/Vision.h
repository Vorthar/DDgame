#pragma once
class Vision{
public:
	Vision();
	~Vision();

	bool hasVis();
	void alterVis();
	int getRange();
	void setRange(int value);
private:
	bool state;
	int range;
};

