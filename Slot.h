#pragma once
#include <iostream>

using namespace std;

class Slot
{
private:
	std::string name;
	int index;
protected:
	
public:
	Slot(string& sN,int sI):name(sN),index(sI){}
	//virtual ~Slot();
	string getName() { return name; }
	int getIndex() { return index; }
};

