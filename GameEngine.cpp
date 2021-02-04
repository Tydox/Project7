#include "GameEngine.h"

#include <string>


GameEngine::GameEngine()
{
	initPlayers();
}

void GameEngine::initPlayers()
{
	bool run;
	int playsAmount;
	string tmpName;
	cout << "Enter Players Amount: ";
	cin >> playsAmount;
	for (int i = 0; i < playsAmount; i++)
	{
		run = true; //continue while
		tmpName.clear(); //clear name
		do
		{
			try
			{
				cout << "Enter Player[" << i << "] name: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, tmpName);

				if (tmpName.empty())
					throw exception("Given Name is empty!");

				run = false;
			}
			catch (exception& error)
			{
				cout << error.what() << endl;
			}
		} while (run);
		players.emplace_back(new Player(tmpName,START_MONEY));

#ifdef DEBUG
		cout << "Player[" << i << "]: " << players[i]->getName() << " " <<players[i]->getMoney()<< endl;
#endif
	}
}
