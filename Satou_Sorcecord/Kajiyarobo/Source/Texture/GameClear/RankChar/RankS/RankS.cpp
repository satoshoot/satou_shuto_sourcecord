#include "RankS.h"
#include "../../../../Utility/Enum/TextureName.h"

RankS::RankS()
	: RankCharBase(TextureName::RankS, 70)
{

}

void RankS::Update(float deltaTime)
{
	if (mCounter <= 0)
		return;

	/*ƒTƒCƒY‚ð‘å‚«‚­‚µ‚Ä‚¢‚­
	26f‚©‚ç¬‚³‚­‚·‚é*/
	mSize += (mCounter - 26) / 800 * deltaTime;

	mCounter -= deltaTime;
}