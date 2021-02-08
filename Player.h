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
	Player(string& Name,int money=0):name(Name),bankAcc(money),boardIndex(0),jailed(false),finishedLoop(false){}
	~Player();
	bool payment(int money);//payment
	bool setPosition(int pos, int bsize);//update position on board slot
	void claimPawned();//try to claim asset from pawned to bought
	void addAsset(Asset* asset, int assetPrice);//add purchased asset to list
	void clearAssets();//clear ownership
	string getName()const { return name; }//return the name of player
	int getMoney()const { return bankAcc; }//return how much money player has in his bank
	bool isJailed()const { return jailed; }//return if player is in jail
	void setJail(bool status) { jailed = status; }//set player status to jailed
	int getPosition()const { return boardIndex; }//return board slot position of player
	void increaseRibit();//increase ribit of players assets - sub method
	
	//block ctor, operator= 
	Player(const Player& player) { *this = player; }
	const Player& operator=(const Player&) { throw exception("COPYING PLAYER DATA IS NOT ALLOWED!"); }
};

