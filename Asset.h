#pragma once
#include <iomanip>

#include "Slot.h"
#include "Player.h"
using namespace std;
class Player;
class Asset: public Slot
{
private:
	string groupName;
	int assetPrice;
	int assetRent;
	Player* playerLink;
	int assetYearsPawn;
		
	const static int assetIntrest;
	
protected:
	
public:
	Asset(string& sN,string& gN, int aP, int aR,int sI):Slot(sN, sI), groupName(gN), assetPrice(aP), assetRent(aR), playerLink(nullptr), assetYearsPawn(0){}

	void clearPlayerLink() { playerLink = nullptr; assetYearsPawn = 0; }

	//Medthod for virtual abstract class
	virtual void print() {
		cout << groupName;
		if (playerLink!=nullptr) {
			//cout << playerLink->getPosition(); TODO ERROR CANT ACCESS PLAYER POSITION
		}
	}

	
};

