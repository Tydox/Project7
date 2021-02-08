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
public:
	
	Asset(string& sN,string& gN, int aP, int aR,int sI):Slot(sN, sI), groupName(gN), assetPrice(aP), assetRent(aR), playerLink(nullptr), assetYearsPawn(0){}
	virtual ~Asset() = default;
	void clearPlayerLink() { playerLink = nullptr; assetYearsPawn = 0; } //clear player from owning an asset - sub method
	virtual void print()const;//Medthod for virtual abstract class
	void redeemAsset() { assetYearsPawn = 0; }//remove asset from being pawned
	bool isNotOwned()const { if (playerLink)return false;  return true; }//return if asset is owned by a player
	Player* getPLink()const { return playerLink; }//get pointer of player who owns asset
	void setPLink(Player* plink); // set player as owner of asset
	void setPawned() { assetYearsPawn = 1; }//set asset as pawned
	bool isPawned()const;//return if asset is pawned
	int getPidyon()const {return assetYearsPawn * assetRent * assetIntrest;} //get the value of pidyon
	int getRent() const { return assetRent; } //return rent value
	int getPrice()const { return assetPrice; }//return asset buy price value
	void addYear() { assetYearsPawn += 1; } // add a year to a pawned asset - sub method

	//block copy and op=
	Asset(const Asset& asset) :Slot() { *this = asset; }
	const Asset& operator=(const Asset& asset){ throw exception("COPYING ASSET DATA IS NOT ALLOWED!"); }
	
};

