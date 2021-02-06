#include "Player.h"

void Player::clearAssets()
{
	while(!(assetOwned.empty()))
	{
			#ifdef DEBUG
			cout << "Assert Erased: " << assetOwned[0]->getName();
			#endif

		assetOwned[0]->clearPlayerLink();
		assetOwned.erase(assetOwned.begin());
		//assetOwned.shrink_to_fit();

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

bool Player::payment(int money)
{
	if (money >= 0){//give money to player
		bankAcc += money;

		//check if there are any pawned assets
		for (int i = 0; i < assetOwned.size(); ++i) 
		{
			if (assetOwned[i]->isPawned()) 
			{
				if (bankAcc - assetOwned[i]->getPidyon() >= 0) 
					assetOwned[i]->redeemAsset();
			}
		}
		
		return true;
	}
	
	if (money <= 0) {//TODO CHECK HOW TO OPTIMZE THE CODE

		if (bankAcc + money >= 0)//take money from player if he has enough in bank
		{
			bankAcc += money;
			return true;
		}
		
		bankAcc += money;
		if (bankAcc < 0) {
			for (int i = 0; i < assetOwned.size(); ++i)
			{
				if (assetOwned[i]->isPawned())
					continue;

				assetOwned[i]->setPawned();//pawn asset
				assetOwned[i]->print();//print asset data
				bankAcc += assetOwned[i]->getPrice(); //get $ of asset to player bank acc
				if (bankAcc>= 0)
					return true;
			}
			return false;
		}
		
	}
	return true;

	
}
