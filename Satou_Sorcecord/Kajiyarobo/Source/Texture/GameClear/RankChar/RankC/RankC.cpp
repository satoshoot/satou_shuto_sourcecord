#include "RankC.h"
#include "../../../../Utility/Enum/TextureName.h"

RankC::RankC()
	: RankCharBase(TextureName::RankC, 30)
{

}

void RankC::Update(float deltaTime)
{
	if (mSize >= 0.7f)
		return;

	mSize += 0.03f * deltaTime;

	mCounter -= deltaTime;
}