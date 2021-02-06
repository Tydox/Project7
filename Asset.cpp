#include "Asset.h"
const int Asset::assetIntrest = RIBIT;

void Asset::print()const
{
	cout << "Slot [" << index << "]:" << endl << "Asset name:" << name << endl;
	cout << "Group Name: " << groupName << endl;
#ifdef DEBUG
	cout << "Asset Price:" << assetPrice << endl;
#endif
	
		if (playerLink) {
			cout << "Player Position:" << playerLink->getPosition() << endl; //TODO ERROR CANT ACCESS PLAYER POSITION
		}
}

void Asset::setPLink(Player* plink)
{
	if (plink)
		playerLink = plink;
	else
		throw exception("Given Player Pointer is NULL! @Asset!");
}

bool Asset::isPawned()const
{
	if (assetYearsPawn >= 1)
		return true;

	return false;
}