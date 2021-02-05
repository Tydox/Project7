#pragma once
#include <iostream>

using namespace std;

class Slot
{
private:
	std::string name;
	int index;
	
protected:
		//Medthod for virtual abstract class
	virtual void print()=0;
public:
	
	Slot(string& sN,int sI):name(sN),index(sI){}

	//TODO - CHECK IF I NEED VIRTUAL DESTROCTOR
	virtual ~Slot()=default;
	
	string getName() { return name; }
	int getIndex() { return index; }
};

