#include "Rank.h"
#include "../../../Utility/Enum/TextureName.h"

Rank::Rank()
	: mSize(0.0f, 120.0f)
	, mAlpha(1.0f)
	, mAlphaPlus(0.003f)
{

}

void Rank::Update(float deltaTime, const float& count)
{
	if (mAlpha <= 0.6f || mAlpha >= 1.0f)
		mAlphaPlus *= -1;

	mAlpha += mAlphaPlus;

	if (count <= 60 * 5 + 30)
	{
		mSize.x += 50.0f;
		mSize.x = CLAMP(mSize.x, 0.0f, 400.0f);
	}
}

void Rank::Draw()const
{
	GSrect lRect(0.0f, 0.0f, mSize.x, mSize.y);
	GScolor lColor(1.0f, 1.0f, 1.0f, mAlpha);

	gsDrawSprite2D(
		(GSuint)TextureName::Rank,
		&GSvector2(350.0f, 700.0f),
		&lRect,
		&GSvector2(0.0f, 60.0f),
		&lColor,
		NULL,
		0.0f
		);
}