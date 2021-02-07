#include "Player.h"

void Player::clearAssets()
{
	while(!(assetOwned.empty()))
	{
			#ifdef DEBUG
		cout << "Assert Ownership Cleared: " << assetOwned[0]->getName() << endl;
			#endif
		assetOwned[0]->clearPlayerLink();
		assetOwned.erase(assetOwned.begin());
	}
}


bool Player::setPosition(int pos, int bsize)
{
	int newPos = boardIndex + pos;
		boardIndex = ((boardIndex + pos) % (bsize));
		if (newPos / (bsize) > 0)
			return true;
		return false;
}

void Player::addAsset(Asset* asset, int assetPrice)
{
	bankAcc -= assetPrice;
	assetOwned.emplace_back(asset);
}

void Player::claimPawned()
{
	//check if there are any pawned assets to reclaim
		for (int i = 0; i < assetOwned.size(); ++i) 
		{
			if (assetOwned[i]->isPawned()) 
				if ((bankAcc - assetOwned[i]->getPidyon()) >= 0)
					assetOwned[i]->redeemAsset();
		}
}

bool Player::payment(int money)
{
	if (money >= 0){//give money to player
		bankAcc += money;

		claimPawned();
		return true;
	}
	
	if (money <= 0) {//TODO CHECK HOW TO OPTIMZE THE CODE

		
		if (bankAcc + money >= 0)//take money from player if he has enough in bank
		{
			bankAcc += money;
			return true;
		}
		
		bankAcc += money;
		if (bankAcc < 0) {//if player does not have enough money->pawn assets until enough
			for (int i = 0; i < assetOwned.size(); ++i)
			{
				if (assetOwned[i]->isPawned())//skip if asset's already pawned
					continue;

				assetOwned[i]->setPawned();//pawn asset
				cout << left << setw(7) << setfill(' ') << "Pawned";
				assetOwned[i]->print();//print asset data
				bankAcc += assetOwned[i]->getPrice(); //get $ of asset to player bank acc
				
				if (bankAcc>= 0)
					return true;
			}
			return false;//not enough money after pawning all assets
		}
		
	}
}

void Player::increaseRibit()
{
	for (int i = 0; i < assetOwned.size(); ++i)
	{
		if (assetOwned[i]->isPawned())
				assetOwned[i]->addYear();
	}
}

Player::~Player()
{
#ifdef DEBUG
	cout << "PLAYER DESTURCTOR CALLED: " << name << endl;
	#endif
	while (!(assetOwned.empty()))
	{
#ifdef DEBUG
		cout << "Assert Ownership Cleared: " << assetOwned[0]->getName() << endl;
#endif
		assetOwned[0]->clearPlayerLink();
		assetOwned.erase(assetOwned.begin());
	}
}

