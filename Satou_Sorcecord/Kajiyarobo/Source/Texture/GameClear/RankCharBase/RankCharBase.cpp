#include "RankCharBase.h"

#include<gslib.h>

RankCharBase::RankCharBase(TextureName name, float count)
	: mName(name)
	, mSize(0.0f)
	, mCounter(count)
{ }

void RankCharBase::Draw()const
{
	const GSrect lRect(0.0f, 0.0f, 250.0f, 300.0f);
	const GSvector2 lSize(mSize, mSize);

	gsDrawSprite2D(
		(GSuint)mName,
		&GSvector2(900.0f, 670.0f),
		&lRect,
		&GSvector2(250.0f / 2, 300.0f / 2 + 50.0f),
		NULL,
		&lSize,
		0.0f
		);
}