#pragma once

#include "Card.h"
#include <queue>
#include <iostream>
using namespace std;

#define DECK_SIZE 5

class Deck
{
private:
	queue<Card*> deckOfCards;
public:
	Deck();
	int getCard();	
	~Deck();	
};

