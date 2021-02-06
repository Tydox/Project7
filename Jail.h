#pragma once
#include "Instruction.h"

class Jail: public Instruction
{
private:
	
protected:
	
	//Medthod for virtual abstract class
	virtual void print()const { cout <<"Slot ["<< index <<"]:"<<endl << "Instruction Card:" << name << endl; }
public:
	Jail(int type, string& sN, int sI):Instruction(type,sN, sI){}

	
};

