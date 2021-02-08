#pragma once
#include "GameBoard.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <string>

#define START_MONEY 350

using namespace std;
class GameEngine{
private:
	GameBoard board;
	vector<Player*> players;
	Deck deck;
	int playerIndex;
	int boardSize;
	int newRoundMoney;
public:
	//constructor
	GameEngine();//copy constructor
	void play();//start the game
	bool preTurn();//asks players if they want to play or forfeit
	bool turn();//actual game turn after a player says he wants to play
	void initPlayers();//init players in game
	int rollDice(); //return a value 1-6
	void printPlayerPos(int& oldpose, int& dice,int& newpose)const;//print player position on board
	void playerForfeit(); //player quits game, delete him and free his assets to the public
	void bankPayPrint(int oba, int pay)const;//print player payment + bank before & after data

	//block ctor, operator= 
	GameEngine(const GameEngine& ge) { *this = ge; }
	const GameEngine& operator=(const GameEngine&) { throw exception("COPYING GAME ENGINE DATA IS NOT ALLOWED!"); }
};

