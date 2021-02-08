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
	virtual ~Slot()=default;
	virtual void print()const =0;	//Medthod for virtual abstract class
	Slot(string& sN,int sI):name(sN),index(sI){}
	string getName()const { return name; }
	int getIndex() const { return index; }
};

