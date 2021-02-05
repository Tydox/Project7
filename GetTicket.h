#pragma once
#include "Instruction.h"

class GetTicket:public Instruction
{
private:

protected:
	//Medthod for virtual abstract class
	virtual void print() {}
public:
	GetTicket(int type, string& sN, int sI):Instruction(type, sN, sI){}
	
};

