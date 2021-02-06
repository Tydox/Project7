#pragma once
#include "Instruction.h"

class GetTicket:public Instruction
{
private:

protected:
	//Medthod for virtual abstract class
	virtual void print() { cout << "Slot [" << index << "]:" << endl << "Instruction Card:" << name << endl; }
public:
	GetTicket(int type, string& sN, int sI):Instruction(type, sN, sI){}
	
};

