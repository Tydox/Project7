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
	
protected:

public:
	Deck()
	{
		for (int i = 0; i < DECK_SIZE;++i)
		{
#ifdef DEBUG1
			std::cout << deckOfCards.size()<< ": ";
#endif
			deckOfCards.push(new Card());
			
			

		}
	}
	
	int getCard()
	{
		//TODO USE THIS CODE IN ORDER TO PUSH POP THE CARDS
			std::cout << "Payment: " << deckOfCards.front()->getVal() << std::endl;
			Card* c = deckOfCards.front();
			deckOfCards.pop();
			deckOfCards.push(c);
			return c->getVal();
	}
	
};

