#pragma once
#include "Instruction.h"

class Start: public Instruction{
protected:
	virtual void print()const{cout << "Instruction Card: " << name << endl;}	//Medthod for virtual abstract class
public:
	Start(int type, string& sN, int sI):Instruction(type, sN, sI){}
	virtual ~Start() = default;
};

