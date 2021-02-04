#pragma once
#include "Slot.h"
#include "Asset.h"
#include "Instruction.h"
#include "Jail.h"
#include "Start.h"
#include "GetTicket.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
class GameBoard
{
private:
	vector<Slot*> slot;
	int boardSize;
	
protected:

public:
	GameBoard();
	
	
};

