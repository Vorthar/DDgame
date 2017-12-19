#pragma once
class Vision{
public:
	Vision();
	~Vision();
	
	bool hasVis();
	int getRange();

	void setVis(bool hasVis, int range);
private:
	bool state;
	int range;

	void alterVis(bool value);
	void setRange(int value);
};

