#pragma once
#include "Instruction.h"

class GetTicket:public Instruction
{
private:

protected:

public:
	GetTicket(int type, string& sN, int sI):Instruction(type, sN, sI){}
	
};

