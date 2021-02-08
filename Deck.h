#pragma once
#include "Card.h"
#include <queue>
#include <iostream>
#define DECK_SIZE 64 //amount of cards you want to have in the deck

using namespace std;
class Deck{
private:
	queue<Card*> deckOfCards;
public:
	Deck();//constructor
	~Deck();//destructor
	int getCard();//pop a card-> return value->push card to the back of the deck
	
	//block ctor, operator= 
	Deck(const Deck& deck) { *this = deck; }
	const Deck& operator=(const Deck&) { throw exception("COPYING DECK DATA IS NOT ALLOWED!"); }

};

