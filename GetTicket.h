#pragma once
#include "Instruction.h"

class GetTicket:public Instruction{
protected:
	virtual void print()const {	cout << "Instruction Card: " << name << endl;}//Medthod for virtual abstract class
public:
	GetTicket(int type, string& sN, int sI):Instruction(type, sN, sI){}
};

