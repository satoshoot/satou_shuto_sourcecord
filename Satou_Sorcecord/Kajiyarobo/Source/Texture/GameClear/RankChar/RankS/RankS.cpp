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

	/*�T�C�Y��傫�����Ă���
	26f���珬��������*/
	mSize += (mCounter - 26) / 800 * deltaTime;

	mCounter -= deltaTime;
}