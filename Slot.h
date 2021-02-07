#pragma once
#include <iostream>
using namespace std;

class Slot
{
protected:
	std::string name; //slot name
	int index; //slot index on board
public:
	Slot() = default;
	//Medthod for virtual abstract class
	virtual void print()const =0;
	Slot(string& sN,int sI):name(sN),index(sI){}
	virtual ~Slot()=default;
	string getName()const { return name; }
	int getIndex() const { return index; }
};

