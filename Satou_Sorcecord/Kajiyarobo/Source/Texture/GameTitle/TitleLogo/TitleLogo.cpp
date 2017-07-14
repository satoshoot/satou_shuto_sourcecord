#include "TitleLogo.h"

TitleLogo::TitleLogo()
	: mAlpha(1.0f)
	, mAlphaPlus(0.005f)
	, mSize(0.0f, 200.0f)
	, mAngle(30)
	, mPosition(1000.0f, 325.0f)
	, mScale(1.6f, 1.6f)
{

}

void TitleLogo::StartUpdate(float deltaTime, float& count)
{
	if (TitleEnd(count) ||
		TitleLogoDraw(count) ||
		Rotate(count) ||
		MoveBottomLeft(deltaTime, count) ||
		MoveTopLeft(deltaTime, count) ||
		MoveLeft(deltaTime, count) ||
		TitleDraw(count))
		return;
}

void TitleLogo::EndUpdate(float deltaTime, float& count)
{
	if (mSize.x <= 0.0f)
		return;

	if (count == 30 || count == 40 || count == 50)
		mAlpha = 0.5f;
	if (count == 35 || count == 45 || count == 55)
		mAlpha = 0.8f;

	if (count >= 80)
		mSize.x -= 100.0f;

	mSize.x = CLAMP(mSize.x, 0.0f, 1200.0f);
}

void TitleLogo::Draw()const
{
	GSrect lRect(0.0f, 0.0f, mSize.x, 200.0f);
	GScolor lColor(1.0f, 1.0f, 1.0f, mAlpha);

	gsDrawSprite2D(
		(GSuint)TextureName::TitleLogo,
		&mPosition,
		&lRect,
		&GSvector2(0.0f, 100.0f),
		&lColor,
		&mScale,
		mAngle);
}

bool TitleLogo::TitleDraw(float& count)
{
	if (count >= 50)
	{
		mSize.x += 20.0f;
		mSize.x = CLAMP(mSize.x, 0.0f, 156.0f);
		return true;
	}
	return false;
}
/*タイトルの出撃を表示*/
bool TitleLogo::MoveLeft(float deltaTime, float& count)
{
	if (count >= 70)
	{
		if (mPosition.x <= 500.0f)
		{
			mPosition.x -= 1 * deltaTime;
			return true;
		}
		mPosition.x -= 140.0f * deltaTime;
		return true;
	}
	return false;
}
/*左上に移動*/
bool TitleLogo::MoveTopLeft(float deltaTime, float& count)
{
	if (count >= 90)
	{
		GSvector2 lVelocity = GSvector2(200.0f, 200.0f) - mPosition;
		lVelocity.normalize();
		if (mPosition.x <= 200.0f)
			mPosition.x -= 0.1f * deltaTime;
		if (mPosition.y <= 200.0f)
			mPosition.y -= 0.1f * deltaTime;
		if (mPosition <= GSvector2(200.0f, 200.0f))
			return true;

		mPosition += lVelocity * 70 * deltaTime;
		return true;
	}
	return false;
}
/*左下に移動*/
bool TitleLogo::MoveBottomLeft(float deltaTime, float& count)
{
	if (count >= 100)
	{
		GSvector2 lVelociy = GSvector2(80.0f, 300.0f) - mPosition;
		lVelociy.normalize();
		mPosition += lVelociy * 18 * deltaTime;
		mPosition.x = CLAMP(mPosition.x, 80.0f, 1000.0f);
		mPosition.y = CLAMP(mPosition.y, 0.0f, 300.0f);
		mScale -= GSvector2(0.08f, 0.08f);
		mScale.x = CLAMP(mScale.x, 1.0f, 2.0f);
		mScale.y = CLAMP(mScale.y, 1.0f, 2.0f);

		return true;
	}
	return false;
}
/*文字を回転*/
bool TitleLogo::Rotate(float& count)
{
	if (count >= 140)
	{
		mAngle -= 1.0f;
		mAngle = CLAMP(mAngle, 0.0f, 360.0f);
		return true;
	}
	return false;
}
/*文字をすべて表示*/
bool TitleLogo::TitleLogoDraw(float& count)
{
	if (count >= 180)
	{
		mSize.x += 100.0f;
		mSize.x = CLAMP(mSize.x, 0.0f, 1200.0f);
		return true;
	}
	return false;
}
/*タイトルの演出終了*/
bool TitleLogo::TitleEnd(float& count)
{
	if (count >= 60 * 3 + 30)
	{
		mSize.x = 1200.0f;
		mAngle = 0.0f;
		mPosition = GSvector2(80.0f, 300.0f);
		mScale = GSvector2(1.0f, 1.0f);
		return true;
	}
	return false;
}
