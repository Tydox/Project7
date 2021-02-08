#pragma once
#include "Instruction.h"

class Jail: public Instruction{
protected:
	virtual void print()const{cout <<"Instruction Card: " << name << endl;}//Medthod for virtual abstract class
public:
	Jail(int type, string& sN, int sI):Instruction(type,sN, sI){}
	virtual ~Jail() = default;
};

