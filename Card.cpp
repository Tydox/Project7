#include "Card.h"

Card::Card()
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<int> dis(-350, 350);
	value = dis(gen);
		#ifdef DEBUG1
	std::cout << "Cards Value: " << value << std::endl;
		#endif
}
