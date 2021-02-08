#pragma once
#include "Slot.h"
#include "Asset.h"
#include "Jail.h"
#include "Start.h"
#include "GetTicket.h"
#include <vector>
#include <fstream>

using namespace std;
class GameBoard{
private:
	vector<Slot*> slot;
	int boardSize;
public:
	GameBoard();//constructor
	~GameBoard();//destructor
	
	int getSize()const { return boardSize; }
	void printSlot(int pos)const;
	Slot* getSlot(int pos)const { return slot[pos]; }

	//block ctor, operator= 
	GameBoard(const GameBoard& gb) { *this = gb; }
	const GameBoard& operator=(const GameBoard&) { throw exception("COPYING GAMEBOARD DATA IS NOT ALLOWED!"); }

};

