#include <iostream>
#include <vector>
#include "GameEngine.h"

int main()
{
	try {
		GameEngine newGame;
		newGame.play();
	}
	catch(exception& error)
	{
		cout << error.what();
	}
	return 1;
}