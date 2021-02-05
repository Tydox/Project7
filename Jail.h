#pragma once
#include "Instruction.h"

class Jail: public Instruction
{
private:
	
protected:
	
	//Medthod for virtual abstract class
	virtual void print() {}
public:
	Jail(int type, string& sN, int sI):Instruction(type,sN, sI){}

	
};

