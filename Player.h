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
	bool isJailed;
	bool finishedLoop;
	
protected:

public:

	Player(string& Name,int money):name(Name),bankAcc(money),boardIndex(0),isJailed(false),finishedLoop(false){}
	void clearAssets();
	string getName() { return name; }
	int getMoney() { return bankAcc; }
};

