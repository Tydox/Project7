#pragma once
#include "Slot.h"

class Instruction: public Slot
{
private:
	int type;//0 start,1 jail, 2 get Ticket
protected:

public:
	Instruction(int Type,string& sN,int sI):Slot(sN, sI),type(Type){}
	int getType()const {return type;}
	
};

