#include "BossHitID.h"

BossHitID::BossHitID()
{
	mIDList.clear();
}

void BossHitID::Add(int& id)
{
	mIDList.push_back(id);
}

void BossHitID::DeletePop()
{
	if (mIDList.size() > 10)
		mIDList.pop_front();
}

bool BossHitID::HitStop(int& id)
{
	for (IDList::iterator i = mIDList.begin(); i != mIDList.end(); i++)
	{
		if (id == *i)
			return true;
	}
	return false;
}
