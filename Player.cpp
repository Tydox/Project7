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
