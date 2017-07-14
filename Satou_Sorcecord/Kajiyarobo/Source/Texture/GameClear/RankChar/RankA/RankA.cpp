#include "RankA.h"
#include "../../../../Utility/Enum/TextureName.h"

RankA::RankA()
	: RankCharBase(TextureName::RankA, 50)
{

}

void RankA::Update(float deltaTime)
{
	if (mCounter <= 0)
		return;

	mSize += (mCounter - 16) / 800 * deltaTime;

	mCounter -= deltaTime;
}