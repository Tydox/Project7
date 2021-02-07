#include "GameBoard.h"

#include <string>


GameBoard::GameBoard():boardSize(0) {

	ifstream slotFile("board.txt", ios::in);
	if(!slotFile.is_open())
		throw exception("Failed to open file!");

	//slotData.seekg(3,ios::beg);
	
	string slotType, slotName;
	//instruction data
	string instType;
	//asset data
	string groupName, assetPrice, assetRent;
	int slotIndex = 0;
	

	while (!slotFile.eof()) {
		++boardSize;
		slotType.clear();
		slotName.clear();
		instType.clear();
		groupName.clear();
		assetPrice.clear();
		assetRent.clear();

		getline(slotFile, slotType, ',');
		
		if (slotType == "P")
		{
			getline(slotFile, groupName, ',');
			getline(slotFile, slotName, ',');
			getline(slotFile, assetPrice, ',');
			getline(slotFile, assetRent, '\n');

			slot.emplace_back(new Asset(slotName, groupName, stoi(assetPrice), stoi(assetRent), slotIndex++));
			continue;
		}
		if (slotType == "I")
		{
			getline(slotFile, instType, ',');
			getline(slotFile, slotName, '\n');
			
			if(instType == "J")
				slot.emplace_back(new Jail(1,slotName,slotIndex++));
			if (instType == "T")
				slot.emplace_back(new GetTicket(2, slotName, slotIndex++));
			if (instType == "S")
				slot.emplace_back(new Start(0, slotName, slotIndex++));
		}
	}
#ifdef DEBUG1
	for (int i = 0; i < slot.size(); i++)
		cout << slot[i]->getIndex()<< ": " << slot[i]->getName() <<endl;
#endif
}

void GameBoard::printSlot(int pos)const
{
#ifdef DEBUG
	cout << "GAME BOARD PRINT!" << endl;
#endif
	slot[pos]->print();

	cout << endl;
}

GameBoard::~GameBoard()
{
	cout << "GAME BOARD DESTURCTOR: " << endl;
		while (!(slot.empty()))
		{
#ifdef DEBUG
			cout << "Slot Erased: " << slot[0]->getName() << endl;
#endif

			delete slot[0];
			slot[0] = nullptr;
			slot.erase(slot.begin());
		}
}