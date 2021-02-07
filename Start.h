#pragma once
#include "Instruction.h"

class Start: public Instruction
{
private:
protected:
	//Medthod for virtual abstract class
	virtual void print()const
	{
		cout << "Instruction Card: " << name << endl;
		//cout << "Slot [" << index << "]:" << endl << "Instruction Card:" << name << endl;
	}
public:
	Start(int type, string& sN, int sI):Instruction(type, sN, sI){}
	
};

