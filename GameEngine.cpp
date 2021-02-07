#include "GameEngine.h"

#include <string>


GameEngine::GameEngine():playerIndex(0)
{
	boardSize = board.getSize()-1;
	initPlayers();
}

void GameEngine::play()
{
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
		
		#ifdef DEBUG
			cout << players[playerIndex]->getName();
		#endif

		if(!(preTurn()))
			continue;
		if (!turn())
		{
			playerForfeit();//player lost - remove from game
			continue;
		}
		
		
		++playerIndex;
	}
	cout << endl << "The Winner is: " << players[0]->getName() << "!!!!!!!!!!!!" << endl;
	playerForfeit();
	cout << endl << "GAME Over!" << endl;
}



void GameEngine::initPlayers()
{
	bool run=true;
	int pAmount;
	string playsAmount;
	string tmpName;
	do
	{
		try
		{
			cout << "Enter Players Amount: ";
			cin >> playsAmount;
			
			if (!std::all_of(playsAmount.begin(), playsAmount.end(), ::isdigit))
				throw exception("Invalid Input!");

			pAmount = stoi(playsAmount);
			if(pAmount<2)
				throw exception("Needed at least 2 players to start game!");
			
			run = false;
		}
		catch (exception& error)
		{
			cout << error.what() << endl;
		}
	} while (run);

	for (int i = 0; i < pAmount; i++)
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

void GameEngine::printPlayerPos(int& oldpose, int& dice, int& newpose)const
{
	cout << left << setw(13) << setfill(' ') << "Dice Rolled";//DICE
	cout << left << setw(18) << setfill(' ') << "Current Position";//old position
	cout << left << setw(18) << setfill(' ') << "New Position";	//newposition
	cout << left << setw(5) << setfill(' ') << "Type" << endl;
	cout << left << setw(13) << setfill(' ') << dice;	//data print
	cout << left << setw(18) << setfill(' ') << oldpose;
	cout << left << setw(18) << setfill(' ') << newpose;
}

void GameEngine::playerForfeit()
{

#ifdef DEBUG
	cout << players[playerIndex]->getName() << " Lost!" << endl;
		cout << "Players Vector size Before: " << players.size() << endl;
#endif
	
		delete players[playerIndex];
		players[playerIndex] = nullptr;
		players.erase(players.begin() + playerIndex);

#ifdef DEBUG
		cout << "Players Vector size After: " << players.size() << endl;
#endif

}

void GameEngine::instaPrint(int& oba, int pay)
{
	cout << left << setw(75) << setfill('-') << "" << endl;
	cout << left << setw(14) << setfill(' ') << "Payment";
	cout << left << setw(25) << setfill(' ') << "Bank Account Before";
	cout << left << setw(20) << setfill(' ') << "Bank Account After" << endl;
	cout << left << setw(14) << setfill(' ') << pay;
	cout << left << setw(25) << setfill(' ') << oba;
	cout << left << setw(20) << setfill(' ') << players[playerIndex]->getMoney() << endl;
	cout << left << setw(75) << setfill('-') << "" << endl << endl;
}




bool GameEngine::preTurn()
{	string tF; //Turn Flag if to play or quit

	while(true)//GET USER INPUT
	try {
		cout << left << setw(50) << setfill('_') << "" << endl;
		cout << left << setw(16) << setfill(' ') << "Current Player:";
		cout << left << setw(4)  << setfill(' ') << players[playerIndex]->getName() << endl;
		cout << left << setw(36) << setfill(' ') << "Do you want to Play[P]/Forfeit[F]:";

			
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
		playerForfeit();
		return false;
	}

	
	if (tF == "p" || tF == "P")//PLAYER CHOSE TO PLAY
	{
		return true;
	}
}

bool GameEngine::turn()
{
	if (players[playerIndex]->isJailed())//check is player is jailed, is so skip turn
	{
		cout << "Player is jailed, skipping turn!" << endl;
		players[playerIndex]->setJail(false);
		return true;
	}
	
	int dice = rollDice();//generate dice num 1-6
	int oldPos = players[playerIndex]->getPosition();//get old position for print val
	
	bool payedNewRound = false;//flag to know if to pay for completed the board loop slot
	if (players[playerIndex]->setPosition(dice, boardSize)) //set new pos ||true = finished loop, give money
	{
#ifdef DEBUG
		cout << "Finished loop!" << endl;
#endif
		players[playerIndex]->increaseRibit();
		players[playerIndex]->payment(START_MONEY);
		payedNewRound = true;
		//TODO ADD MONEY TO PLAYER BECAUSE HE DID A FULL LOOP 18->+1
	}
	int newPos = players[playerIndex]->getPosition();//get players old pos
	printPlayerPos(oldPos,dice,newPos); //print old pos

	
	board.printSlot(newPos);
	bool playerSurvived = true;//flag to know if player payed the payment successfully
	int oldBankAcc = players[playerIndex]->getMoney();//save bank $ before payment change

	//CHECK WHAT KIND OF SLOT PLAYER IS ON
	//INSTRUCTION SLOT
	Instruction* tmpInst = dynamic_cast<Instruction*>(board.getSlot(newPos));
	if (tmpInst)
	{
		int instaType = tmpInst->getType();
		switch (instaType)
		{
		case 0:{//type 0 - start give 350
				if(!payedNewRound)
					players[playerIndex]->payment(START_MONEY);

				instaPrint(oldBankAcc, START_MONEY);
				break;
			}
			
		case 1:{//type 1 - jail
				players[playerIndex]->setJail(true);
				return true;
				
		}
		case 2:{//type 2 - get ticket
			int payment = deck.getCard();
			playerSurvived = players[playerIndex]->payment(payment);
			instaPrint(oldBankAcc, payment);
						
			if (!playerSurvived)
				cout << players[playerIndex]->getName() << " couldn't pay the payment fee!" << endl;

			break;
		}	
		}
	}
	
	
	//ASSET SLOT
	Asset* tmpAsset = dynamic_cast<Asset*>(board.getSlot(newPos));
	if (tmpAsset)
		if (tmpAsset->isNotOwned())//check if there is an owner to the asset
		{
			bool run = true;
			string opt;
			do
			{
				try
				{
					cout << "Purchase Asset? [Y/N]: ";
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, opt);
					
					if (opt.empty() || !(opt == "Y" || opt == "y" || opt == "N" || opt == "n"))
						throw exception("Invalid Input! Try again!");

					run = false;
				}
				catch (exception& error)
				{
					cout << error.what() << endl;
				}
			} while (run);

			if (opt == "N" || opt == "n")
				return true;

			if (opt == "Y" || opt == "y")
			{
				int ap = tmpAsset->getPrice();//ap = asset price
				int pc = players[playerIndex]->getMoney(); // pc = player bank cash $
				if (pc >= ap)//check if player has enough cash to buy asset
				{
					tmpAsset->setPLink(players[playerIndex]);//connect Player and Asset to point at each other
					players[playerIndex]->addAsset(tmpAsset,ap);//and remove money from bank acc
					cout << "Purchase was successful!" << endl;
				}
				else
				{
					cout << "You do not have enough money to purchase this asset!" << endl << "Ending Turn!" << endl;
				}
			}



		}
		else //asset has an owner || either bank or player
		{
			int rentPrice = tmpAsset->getRent();
			playerSurvived = players[playerIndex]->payment(((-1) * rentPrice));//player pays rent
			instaPrint(oldBankAcc, (-1)* rentPrice);
			
			if (!playerSurvived)
				cout << players[playerIndex]->getName() << " couldn't pay the rent!" << endl;
			if (!(tmpAsset->isPawned()))//if some player owns asset add +rent$ to their bank account
			{
				Player* tmpPlayer = tmpAsset->getPLink();
				tmpPlayer->payment(rentPrice);
			}

		}


	return playerSurvived;
}

