#include "MenuCursor.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Utility/Enum/SoundName.h"

MenuCursor::MenuCursor()
	: mPosition(0.0f, 0.0f)
	, mSelectCount(0)
	, mChangePage(false)
{

}

void MenuCursor::Update(float deltaTime)
{
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X) ||
		gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_LEFT))
	{
		gsPlaySE((GSuint)SoundName::Cursor);
		mSelectCount--;
	}
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_Y) ||
		gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_RIGHT))
	{
		gsPlaySE((GSuint)SoundName::Cursor);
		mSelectCount++;
	}
	if (mSelectCount > 3)
	{
		mSelectCount = 0;
		mChangePage = true;
	}
	else if (mSelectCount < 0)
	{
		mSelectCount = 3;
		mChangePage = true;
	}
	else
		mChangePage = false;


	switch (mSelectCount)
	{
	case 0:
		mPosition = GSvector2(460.0f, 760.0f);
		break;
	case 1:
		mPosition = GSvector2(710.0f, 760.0f);
		break;
	case 2:
		mPosition = GSvector2(960.0f, 760.0f);
		break;
	case 3:
		mPosition = GSvector2(1210.0f, 760.0f);
		break;
	}
}

void MenuCursor::Draw()const
{
	const GSrect rect(0.0f, 0.0f, 190.0f, 180.0f);
	gsDrawSprite2D(
		(GSuint)TextureName::SelectCursor,
		&mPosition,
		&rect,
		&GSvector2(95.0f, 90.0f),
		NULL,
		NULL,
		0.0f
		);
}

int MenuCursor::GetSelectCount()const
{
	return mSelectCount;
}

void MenuCursor::ResetCursor()
{
	mSelectCount = 0;
}