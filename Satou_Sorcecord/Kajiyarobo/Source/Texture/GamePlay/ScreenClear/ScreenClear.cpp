#include "ScreenClear.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../../Screen/Screen.h"

ScreenClear::ScreenClear() :
	m_Alpha(1.0f)
{
}

void ScreenClear::OnUpdate(float deltaTime)
{
	if (m_Alpha <= 0.0f)
	{
		Dead();
		return;
	}
	m_Alpha -= 0.03f;
}

void ScreenClear::OnDraw() const
{
	GSrect l_Rect(0.0f, 0.0f, WIDTH, HEIGHT);
	GScolor l_Color(0.0f, 0.0f, 0.0f, m_Alpha);
	gsDrawSprite2D(
		(GSuint)TextureName::ScreenHide,
		&GSvector2(0.0f, 0.0f),
		&l_Rect,
		NULL,
		&l_Color,
		NULL,
		0.0f
		);
}
