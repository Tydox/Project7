#include <iostream>
#include <vector>
#include "GameEngine.h"

int main()
{
	try {
		GameEngine newGame;
	}
	catch(exception& error)
	{
		cout << error.what();
	}
	return 1;
}