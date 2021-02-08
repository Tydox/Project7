#include "Deck.h"

Deck::Deck()
{
		for (int i = 0; i < DECK_SIZE; ++i)
			deckOfCards.push(new Card());
}

int Deck::getCard()
{
	Card* c = deckOfCards.front();
	deckOfCards.pop();
	deckOfCards.push(c);
	return c->getVal();
}

Deck::~Deck()
{
#ifdef DEBUG
	cout << "DECK DESTURCTOR CALLED: " << endl;
#endif
	
	Card* tc = nullptr;//tc=tmp card
	while (!(deckOfCards.empty()))
	{
		tc = deckOfCards.front();
#ifdef DEBUG
		cout << "DECK Erased: " << tc->getVal() << endl;
#endif
		delete tc;
		tc = nullptr;
		deckOfCards.pop();
	}
}
