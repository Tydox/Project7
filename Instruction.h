#pragma once
#include "Slot.h"

class Instruction: public Slot
{
private:
	int type;//0 start,1 jail, 2 get Ticket
protected:

public:
	Instruction(int Type,string& sN,int sI):Slot(sN, sI),type(Type){}
	virtual void print() {
		switch (type)
		{
		case 0: {cout << "Instruction Card: Start";
			break; }
		case 1: {cout << "Instruction Card: Jail";
			break; }
		case 2: {cout << "Instruction Card: Get Ticket";
			break; }	
		}
	}
	int getType(){return type;}
	
};

