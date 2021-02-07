#pragma once
#include <iostream>
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
	
protected:

public:

	Player(string& Name,int money=0):name(Name),bankAcc(money),boardIndex(0),jailed(false),finishedLoop(false){}
	void clearAssets();//clear ownership
	string getName()const { return name; }
	int getMoney()const { return bankAcc; }
	bool isJailed()const { return jailed; }
	void setJail(bool status) { jailed = status; }
	int getPosition()const { return boardIndex; }
	bool setPosition(int pos, int bsize);
	void addAsset(Asset* ass, int assetPrice);
	bool payment(int money);
	void increaseRibit();
	Player(const Player&) { throw exception("COPYING PLAYER DATA IS NOT ALLOWED!"); }
		//#ifdef DEBUG
	~Player();
		//#endif
};

