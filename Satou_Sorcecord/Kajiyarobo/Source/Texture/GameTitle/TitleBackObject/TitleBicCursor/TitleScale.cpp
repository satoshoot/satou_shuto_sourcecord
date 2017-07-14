#include "TitleScale.h"

TitleScale::TitleScale() :
	TEXTURE_SIZE(480.0f, 700.0f),
	m_Size(0.0f, 0.0f),
	m_Alpha(0.2f)
{
}

void TitleScale::StartUpdate(float deltaTime, float & counter)
{
	if (counter <= 90 || m_Size >= TEXTURE_SIZE)
		return;
	if (counter >= 60 * 3 + 30)
	{
		m_Size = TEXTURE_SIZE;
		return;
	}

	m_Size += GSvector2(25.0f, 25.0f) * deltaTime;
	m_Size.x = CLAMP(m_Size.x, 0.0f, TEXTURE_SIZE.x);
	m_Size.y = CLAMP(m_Size.y, 0.0f, TEXTURE_SIZE.y);
}

void TitleScale::EndUpdate(float deltaTime, float & counter)
{
	if (counter <= 40 || m_Size <= GSvector2(0.0f, 0.0f))
		return;

	m_Size -= GSvector2(30.0f, 30.0f) * deltaTime;
	m_Size.x = CLAMP(m_Size.x, 0.0f, TEXTURE_SIZE.x);
	m_Size.y = CLAMP(m_Size.y, 0.0f, TEXTURE_SIZE.y);

}

void TitleScale::Draw() const
{
	const GSrect l_Rect(0.0f, 0.0f, m_Size.x, m_Size.y);
	GScolor l_Color(1.0f, 1.0f, 1.0f, m_Alpha);

	gsDrawSprite2D(
		(GSuint)TextureName::TitleScale,
		&GSvector2(100.0f, 100.0f),
		&l_Rect,
		NULL,
		&l_Color,
		NULL,
		0.0f
		);
}
