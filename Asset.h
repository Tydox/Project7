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
	virtual void print()const;
	void redeemAsset() { assetYearsPawn = 0; }
	bool isNotOwned()const { if (playerLink)return false;  return true; }
	//int price() { return assetPrice; }

	Player* getPLink() { return playerLink; }
	void setPLink(Player* plink);
	void setPawned() { assetYearsPawn = 1; }
	bool isPawned()const;
	
	int getPidyon()const {return assetYearsPawn * assetRent * assetIntrest;}

	int getRent() const { return assetRent; }
	int getPrice()const { return assetPrice; }
	void addYear() { assetYearsPawn += 1; }

#ifdef DEBUG
	~Asset() { cout << "ASSET DESTURCTOR CALLED: " << name << endl; }
#endif
};

