#pragma once
#include "Instruction.h"

class GetTicket:public Instruction
{
protected:
	//Medthod for virtual abstract class
	virtual void print()const { cout << "Slot [" << index << "]:" << endl << "Instruction Card:" << name << endl; }
public:
	GetTicket(int type, string& sN, int sI):Instruction(type, sN, sI){}
};

