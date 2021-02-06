#pragma once
#include "Instruction.h"

#define GIVE_MONEY 350
class Start: public Instruction
{
private:
	int giveMoney;
protected:
	//Medthod for virtual abstract class
	virtual void print() { cout << "Slot [" << index << "]:" << endl << "Instruction Card:" << name << endl; }
public:
	Start(int type, string& sN, int sI):Instruction(type, sN, sI),giveMoney(GIVE_MONEY){}
	
};

