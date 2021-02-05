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

	Player(string& Name,int money):name(Name),bankAcc(money),boardIndex(0),jailed(false),finishedLoop(false){}
	void clearAssets();
	string getName() { return name; }
	int getMoney() { return bankAcc; }
	bool isJailed() { return jailed; }
	void setJail(bool status) { jailed = status; }
	int getPosition() { return boardIndex; }
	bool setPosition(int pos, int bsize);
	void addAsset(Asset* ass)
	{
		assetOwned.emplace_back(ass);
	}

	bool payment(int num); //
};

