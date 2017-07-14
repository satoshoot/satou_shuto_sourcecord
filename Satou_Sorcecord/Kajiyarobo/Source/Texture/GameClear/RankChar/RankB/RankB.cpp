#include "RankB.h"
#include "../../../../Utility/Enum/TextureName.h"

RankB::RankB()
	: RankCharBase(TextureName::RankB, 30)
{

}

void RankB::Update(float deltaTime)
{
	if (mCounter <= 0)
		return;

	mSize += (mCounter - 10) / 300 * deltaTime;

	mCounter -= deltaTime;

}