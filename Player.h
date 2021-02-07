#pragma once
#include <vector>
#include "Asset.h"

using namespace std;
class Asset;
 
class Player
{
private:
	string name;
	int bankAcc;
	int boardIndex;
	vector<Asset*> assetOwned;
	bool jailed;
	bool finishedLoop;
public:
	//constructor
	Player(string& Name,int money=0):name(Name),bankAcc(money),boardIndex(0),jailed(false),finishedLoop(false){}
	bool payment(int money);//payment
	bool setPosition(int pos, int bsize);//update position on board slot
	void claimPawned();//try to claim asset from pawned to bought
	void addAsset(Asset* asset, int assetPrice);//add purchased asset to list

	
	void clearAssets();//clear ownership
	string getName()const { return name; }
	int getMoney()const { return bankAcc; }
	bool isJailed()const { return jailed; }
	void setJail(bool status) { jailed = status; }
	int getPosition()const { return boardIndex; }
	void increaseRibit();
	
	
	Player(const Player& player) { *this = player; }
	const Player& operator=(const Player&) { throw exception("COPYING PLAYER DATA IS NOT ALLOWED!"); }

	~Player();

};

