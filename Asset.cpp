#include "Asset.h"
const int Asset::assetIntrest = RIBIT;

void Asset::print()const
{
	cout << "Asset" << endl;
	cout << left << setw(75) << setfill('-') << "" << endl;
	cout << left << setw(15) << setfill(' ') << "Name";
	cout << left << setw(15) << setfill(' ') << "Group";
	cout << left << setw(15) << setfill(' ') << "Buy Price";
	cout << left << setw(15) << setfill(' ') << "Rent Price";
	cout << left << setw(15) << setfill(' ') << "Owned?"<<endl;
	
	cout << left << setw(15) << setfill(' ') << name;
	cout << left << setw(15) << setfill(' ') << groupName;
	cout << left << setw(15) << setfill(' ') << assetPrice;
	cout << left << setw(15) << setfill(' ') << assetRent;
	
	if (this->isNotOwned())
		cout << left << setw(15) << setfill(' ') << "NO" << endl;
	else
		cout << left << setw(15) << setfill(' ') << playerLink->getName() << endl;

	cout << left << setw(75) << setfill('-') << "" << endl;
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