#pragma once
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
	//Medthod for virtual abstract class
	virtual void print() {}
public:
	Asset(string& sN,string& gN, int aP, int aR,int sI):Slot(sN, sI), groupName(gN), assetPrice(aP), assetRent(aR), playerLink(nullptr), assetYearsPawn(0){}

	void clearPlayerLink() { playerLink = nullptr; assetYearsPawn = 0; }
	
};

