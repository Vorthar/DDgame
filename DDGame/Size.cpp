#include "stdafx.h"
#include "Size.h"


Size::Size(){
}
Size::~Size(){
}

int Size::getSize(){
	return size;
}
void Size::setSize(string name){
	string response;
	cout << "\nPlease input " << name << "'s size (T: Tiny S: Small M: Medium L: Large H: Huge G: Gargantuan): ";
	getline(cin, response);
	while (response != "T"&&response != "S"&&response != "M"&&response != "L"&&response != "H"&&response != "G") {
		cout << "Please select a valid size (The one letter indicator): ";
		getline(cin, response);
	}
	if (response == "T") setSize(-2);
	else if (response == "S") setSize(-1);
	else if (response == "M") setSize(0);
	else if (response == "L") setSize(1);
	else if (response == "H") setSize(2);
	else setSize(3);
}
void Size::setSize(int value){
	size = value;
}
