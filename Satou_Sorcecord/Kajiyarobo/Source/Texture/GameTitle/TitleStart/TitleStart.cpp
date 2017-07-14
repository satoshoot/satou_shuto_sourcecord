#include "TitleStart.h"

TitleStart::TitleStart()
	: mPosition(200.0f, 600.0f)
	, mSize(0.0f, 70.0f)
	, mAlpha(1.0f)
	, mAlphaPlus(0.004f)
{ }


void TitleStart::StartUpdate(float deltaTime, float& count)
{
	Alpha();

	if (DrawStart(count) ||
		MoveRight(deltaTime, count, 150.0f, 450.0f, 70.0f) ||
		MoveDown(count) ||
		DrawButton(count))
		return;
}

void TitleStart::EndUpdate(float deltaTime, float& count)
{
	Alpha();
	if (MoveRight(deltaTime, count, 75.0f, 1500.0f, 300.0f) ||
		MoveTopRight(deltaTime, count) ||
		ReturnButton(count))
		return;
}

void TitleStart::Draw()const
{
	GSrect lRect(0.0f, 0.0f, mSize.x, mSize.y);
	GScolor lColor(1.0f, 1.0f, 1.0f, mAlpha);
	gsDrawSprite2D(
		(GSuint)TextureName::Start,
		&mPosition,
		&lRect,
		&GSvector2(0.0f, 35.0f),
		&lColor,
		NULL,
		0.0f);
}
/*ボタンの表示*/
bool TitleStart::DrawButton(float& count)
{
	if (count >= 110)
	{
		mSize.x += 15.0f;
		mSize.x = CLAMP(mSize.x, 0.0f, 80.0f);
		mSize.y += 15.0f;
		mSize.y = CLAMP(mSize.y, 0.0f, 70.0f);
		return true;
	}
	return false;
}
/*下に移動*/
bool TitleStart::MoveDown(float& count)
{
	if (count >= 130)
	{
		if (mPosition.y >= 650.0f)
		{
			mPosition.y += 1;
			return true;
		}
		mPosition.y += 100.0f;
		return true;
	}
	return false;
}
/*右に移動*/
bool TitleStart::MoveRight(float deltaTime, float& count, float time, float max, float velocity)
{
	if (count >= time)
	{
		if (mPosition.x >= max)
		{
			mPosition.x += 0.1f * deltaTime;
			return true;
		}
		mPosition.x += velocity * deltaTime;
		return true;
	}
	return false;
}
/*スタートを表示*/
bool TitleStart::DrawStart(float& count)
{
	if (mSize.x >= 420.0f)
	{
		TitleEnd();
		return true;
	}
	if (count >= 60 * 3 + 30)
	{
		mSize.x += 80.0f;
		mSize.x = CLAMP(mSize.x, 0.0f, 420.0f);
		return true;
	}
	return false;
}
/*タイトルの演出終了*/
void TitleStart::TitleEnd()
{
	mSize = GSvector2(420.0f, 70.0f);
	mPosition = GSvector2(485.0f, 719.0f); //Aマークが止まる位置
}
/*ボタンのみの状態に戻す*/
bool TitleStart::ReturnButton(float& count)
{
	if (count >= 20)
	{
		mSize.x -= 80.0f;
		mSize.x = CLAMP(mSize.x, 80.0f, 420.0f);
		return true;
	}
	return false;
}
/*右上に移動*/
bool TitleStart::MoveTopRight(float deltaTime, float& count)
{
	if (count >= 60)
	{
		if (mPosition >= GSvector2(700.0f, 500.0f))
		{
			mPosition.x += 0.4f * deltaTime;
			mPosition.y -= 0.4f * deltaTime;
			return true;
		}
		GSvector2 lVelocity = GSvector2(700.0f, 550.0f) - mPosition;
		lVelocity.normalize();
		mPosition += lVelocity * 70.0f * deltaTime;
		mPosition.x = CLAMP(mPosition.x, 0.0f, 750.0f);
		mPosition.y = CLAMP(mPosition.y, 550.0f, 900.0f);
		return true;
	}
	return false;
}
void TitleStart::Alpha()
{
	if (mAlpha <= 0.6f || mAlpha >= 1.0f)
		mAlphaPlus *= -1;

	mAlpha += mAlphaPlus;
}