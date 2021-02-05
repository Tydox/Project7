#include "GameEngine.h"

#include <string>


GameEngine::GameEngine():playerIndex(0)
{
	boardSize = board.getSize()-1;
	initPlayers();
	play();
}

void GameEngine::play()
{
	//int playerIndex = 0;
	while (1)
	{
		if (playerIndex == players.size())
		{
			playerIndex = 0;
			continue;
		}
		//if remains 1 or no players - end game
		if (players.size() <= 1)
			break;
		
		#ifndef DEBUG
			cout << players[i]->getName();
		#endif

		if(!(preTurn()))
			continue;
		turn();
		
		
		++playerIndex;
	}
	
}



void GameEngine::initPlayers()
{
	bool run=true;
	int playsAmount;
	string tmpName;
	do
	{
		try
		{
			cout << "Enter Players Amount: ";
			cin >> playsAmount;

			if (playsAmount < 2)
				throw exception("Needed at least 2 players to start game!");				

			run = false;
		}
		catch (exception& error)
		{
			cout << error.what() << endl;
		}
	} while (run);

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

int GameEngine::rollDice()
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<int> dis(1, 6);
	return dis(gen);
}

void GameEngine::printPlayerPos()
{
	cout << players[playerIndex]->getName() << "'s current Position: " << players[playerIndex]->getPosition() << endl;
}




bool GameEngine::preTurn()
{	string tF; //Turn Flag if to play or quit

	while(true)//GET USER INPUT
	try {
		cout << "Player:" << players[playerIndex]->getName() << "Do you want to Play[P]/Forfeit[F]: ";
			
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, tF);//get from user input if to play or quit
		
		if (!(tF=="P" || tF == "F" || tF == "p" || tF == "f"))//check if user input is valid
			throw exception("Invalid Input!");

		break;
	}
	catch (exception& error)
	{
		cout << error.what() << endl; //give warning and let the user input again
	}

	
	if (tF == "f" || tF == "F") //PLAYER CHOSE TO FORFEIT
	{
		#ifdef DEBUG
		cout << "Players Vector size Before: " << players.size()<<endl;
		#endif
		
		players[playerIndex]->clearAssets(); //free his assets from ownership
		players.erase(players.begin() + playerIndex);
		
		#ifdef DEBUG
		cout << "Players Vector size After: " << players.size() << endl;
		#endif
		return false;
	}

	
	if (tF == "p" || tF == "P")//PLAYER CHOSE TO PLAY
	{
		return true;
	}
}

void GameEngine::turn()
{
	if(players[playerIndex]->isJailed())
	{
		cout << "Player is jailed, skipping turn!" << endl;
		players[playerIndex]->setJail(false);
		return;
	}

	printPlayerPos(); //print old pos
	int dice = rollDice();
	
	if(players[playerIndex]->setPosition(dice,boardSize)) //set new pos ||true = finished loop, give money
	{
		
		//TODO ADD MONEY TO PLAYER BECAUSE HE DID A FULL LOOP 18->+1
	}
	printPlayerPos(); //print new pos
	int newPos = players[playerIndex]->getPosition();//get players old pos

	//Asset* tmpAsset = dynamic_cast<Asset*>(board.getSlot(newPos));


	Instruction* tmpInst = dynamic_cast<Instruction*>(board.getSlot(newPos));
	if (tmpInst)
		if (tmpInst->getType()==1)
			players[playerIndex]->setJail(true);

	
	
	board.printSlot(newPos);
	

	
}
