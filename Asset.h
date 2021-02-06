#pragma once
#include <iomanip>
#include "Slot.h"
#include "Player.h"
using namespace std;
class Player;

#define RIBIT 2

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
			//cout << playerLink->getPosition(); //TODO ERROR CANT ACCESS PLAYER POSITION
		}
	}
	void redeemAsset() { assetYearsPawn = 0; }
	bool isNotOwned() { if (playerLink)return false;  return true; }
	//int price() { return assetPrice; }

	Player* getPLink() { return playerLink; }
	void setPLink(Player* plink) {
		if (plink)
			playerLink = plink;
		else 
			throw exception("Given Player Pointer is NULL! @Asset!");
	}
	void setPawned() { assetYearsPawn = 1; }
	bool isPawned()
	{
		if (assetYearsPawn >= 1)
			return true;
		
		return false;
	}

	int getPidyon()	{return assetYearsPawn * assetRent * assetIntrest;}

	int getRent() { return assetRent; }
	int getPrice() { return assetPrice; }
};

