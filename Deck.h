#pragma once
#include "Card.h"
#include <queue>
#include <iostream>
#define DECK_SIZE 64

using namespace std;
class Deck
{
private:
	queue<Card*> deckOfCards;
public:
	Deck();
	int getCard();	
	~Deck();
	Deck(const Deck& deck) { *this = deck; }
	const Deck& operator=(const Deck&) { throw exception("COPYING DECK DATA IS NOT ALLOWED!"); }

};

