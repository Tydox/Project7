#include "Deck.h"

Deck::Deck()
{
		for (int i = 0; i < DECK_SIZE; ++i)
		{
#ifdef DEBUG1
			std::cout << deckOfCards.size() << ": ";
#endif
			deckOfCards.push(new Card());
		}
	}

int Deck::getCard()
{
	//TODO USE THIS CODE IN ORDER TO PUSH POP THE CARDS
	std::cout << "Payment: " << deckOfCards.front()->getVal() << std::endl;
	Card* c = deckOfCards.front();
	deckOfCards.pop();
	deckOfCards.push(c);
	return c->getVal();
}

Deck::~Deck()
{
	cout << "DECK DESTURCTOR CALLED: " << endl;

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
