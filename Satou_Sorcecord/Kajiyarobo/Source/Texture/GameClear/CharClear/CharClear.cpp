#include "CharClear.h"
#include "../../../Utility/Enum/TextureName.h"

CharClear::CharClear()
	: mSize(0.0f, 100.0f)
	, mPosition(1035.0f, 320.0f)
	, mAlpha(1.0f)
	, mAlphaPlus(0.0025f)
{

}

void CharClear::Update(float deltaTime, float& count)
{
	if (mAlpha <= 0.7f || mAlpha >= 1.0f)
		mAlphaPlus *= -1;

	mAlpha += mAlphaPlus;

	if (count <= 60 * 7 + 30)
	{
		mSize.x += 80.0f;
		mSize.x = CLAMP(mSize.x, 0.0f, 670.0f);
		mPosition.x -= 80.0f;
		mPosition.x = CLAMP(mPosition.x, 1035.0f - 670.0f, 1400.0f);
	}
}

void CharClear::Draw()const
{
	GSrect lRect(670.0f - mSize.x, 0.0f, 670.0f, mSize.y);
	GScolor lColor(1.0f, 1.0f, 1.0f, mAlpha);

	gsDrawSprite2D(
		(GSuint)TextureName::CharClear,
		&mPosition,
		&lRect,
		&GSvector2(0.0f, 50.0f),
		&lColor,
		NULL,
		0.0f
		);
}