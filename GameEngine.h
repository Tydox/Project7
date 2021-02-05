#pragma once
#include "GameBoard.h"
#include "Player.h"
#include "Deck.h"
#include <string>
#include <iostream>

#include <vector>

#define START_MONEY 350


using namespace std;

class GameEngine
{
private:
	GameBoard board;
	vector<Player*> players;
	Deck deck;
protected:
	
public:
	//constructor
	GameEngine();
	void play();
	bool turn(int playerIndex);
	void initPlayers();
};

