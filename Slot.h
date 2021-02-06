#pragma once
#include <iostream>

using namespace std;

class Slot
{
private:
	
	
protected:
		//Medthod for virtual abstract class
	std::string name;
	int index;
public:
	virtual void print()const =0;
	Slot(string& sN,int sI):name(sN),index(sI){}

	//TODO - CHECK IF I NEED VIRTUAL DESTROCTOR
	virtual ~Slot()=default;
	
	string getName()const { return name; }
	int getIndex() const { return index; }
};

