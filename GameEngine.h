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
	int playerIndex;
	int boardSize;
	int newRoundMoney;
protected:
	
public:
	//constructor
	GameEngine();
	void play();
	bool preTurn();
	bool turn();
	void initPlayers();

	int rollDice(); //return a value 1-6
	void printPlayerPos(int& oldpose, int& dice,int& newpose)const;//print player position on board
	void playerForfeit();
	void instaPrint(int& oba, int pay);
	GameEngine(const GameEngine& ge) { *this = ge; }
	const GameEngine& operator=(const GameEngine&) { throw exception("COPYING GAME ENGINE DATA IS NOT ALLOWED!"); }

	
};

