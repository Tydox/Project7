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
