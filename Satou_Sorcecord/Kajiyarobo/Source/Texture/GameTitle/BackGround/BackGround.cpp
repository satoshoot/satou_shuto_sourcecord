#include "BackGround.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../TitleLogo/TitleLogo.h"

BackGround::BackGround()
	: mSize(GSvector2(0.0f, 0.0f))
	, mAlpha(1.0f)
	, mAlphaPlus(0.002f)
{

}

void BackGround::StartUpdate(float& count)
{
	if (mAlpha <= 0.7f || mAlpha >= 1.0f)
		mAlphaPlus *= -1;

	mAlpha += mAlphaPlus;
	if (count >= 60 * 3 + 30)
	{
		mSize = GSvector2(1.0f, 1.0f);
		return;
	}

	if (count <= 10)
		return;

	if (count >= 20)
	{
		mSize.x += 0.15f;
		mSize.y += 0.12f;
		mSize.x = CLAMP(mSize.x, 0.0f, 1.0f);
		mSize.y = CLAMP(mSize.y, 0.0f, 1.0f);
		return;
	}
	mSize.x = 0.03f;
	mSize.y += 0.07f;
	mSize.y = CLAMP(mSize.y, 0.0f, 1.0f);
}

void BackGround::EndUpdate(float& count)
{
	if (count < 115)
		return;

	if (count >= 90)
	{
		mSize.x -= 0.4f;
		mSize.x = CLAMP(mSize.x, 0.05f, 1.0f);
		mSize.y -= 0.2f;
		mSize.y = CLAMP(mSize.y, 0.0f, 1.0f);
		return;
	}
	if (count >= 115)
		mSize.x -= 0.08f;
}

void BackGround::BackDraw()const
{
	GScolor lColor(1.0f, 1.0f, 1.0f, mAlpha);
	gsDrawSprite2D(
		(GSuint)TextureName::TitleBack,
		&GSvector2(700.0f, 478.0f),
		&GSrect(0.0f, 0.0f, 1400.0f, 900.0f),
		&GSvector2(700.0f, 480.0f),
		&lColor,
		&mSize,
		0.0f);
}

void BackGround::FrameDraw()const
{
	gsDrawSprite2D(
		(GSuint)TextureName::TitleFrame,
		&GSvector2(700.0f, 480.0f),
		&GSrect(0.0f, 0.0f, 1400.0f, 900.0f),
		&GSvector2(700.0f, 480.0f),
		NULL,
		&mSize,
		0.0f);
}