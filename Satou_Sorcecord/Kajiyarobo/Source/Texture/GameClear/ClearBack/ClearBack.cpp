#include "ClearBack.h"
#include "../../../Utility/Enum/TextureName.h"

ClearBack::ClearBack()
	: mSize(0.0f, 0.0f)
{

}

void ClearBack::Update(float deltaTime, const float& count)
{
	if (count <= 60 * 7 + 50)
	{
		mSize.x += 0.15f;
		mSize.x = CLAMP(mSize.x, 0.0f, 1.0f);
		mSize.y = 1.0f;
		return;
	}
	if (count <= 60 * 8)
	{
		mSize.x = 0.03f;
		mSize.y += 0.12f;
		mSize.y = CLAMP(mSize.y, 0.0f, 1.0f);
	}
}

void ClearBack::Draw()const
{
	GSrect lRect(0.0f, 0.0f, 900.0f, 700.0f);

	gsDrawSprite2D(
		(GSuint)TextureName::GameClear,
		&GSvector2(700.0f, 480.0f),
		&lRect,
		&GSvector2(450.0f, 350.0f),
		NULL,
		&mSize,
		0.0f
		);
}