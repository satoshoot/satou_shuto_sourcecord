#include "TitleIcon.h"
#include "../../../../Screen/Screen.h"


TitleIcon::TitleIcon(const GSvector2& position, const TextureName& name) :
	m_Size(0.0f, 0.0f),
	m_Alpha(0.4f),
	m_AlphaPlus(0.0004f),
	m_Position(position),
	m_Name(name)
{
}

void TitleIcon::StartUpdate(float deltaTime, float& counter)
{
	Alpha();

	if (SizeDown(deltaTime, counter)
		|| SizeUp(deltaTime, counter)
		|| OpenIcon(deltaTime, counter))
		return;
}

void TitleIcon::EndUpdate(float deltaTime, float& counter)
{
	if (counter >= 90)
	{
		m_Size -= GSvector2(0.1f, 0.1f);
		ClampSize(0.0f, 1.0f);
	}
}

void TitleIcon::Draw() const
{
	const GSvector2 TEXTURE_SIZE(190.0f, 180.0f);
	GSrect l_Rect(0.0f, 0.0f, TEXTURE_SIZE.x, TEXTURE_SIZE.y);
	GSvector2 l_Center(TEXTURE_SIZE.x / 2, TEXTURE_SIZE.y / 2);
	GScolor l_Color(1.0f, 1.0f, 1.0f, m_Alpha);

	gsDrawSprite2D(
		(GSuint)m_Name,
		&m_Position,
		&l_Rect,
		&l_Center,
		&l_Color,
		&m_Size,
		0.0f);
}

bool TitleIcon::OpenIcon(float deltaTime, float& counter)
{
	if (counter >= 60)
	{
		m_Size += GSvector2(0.02f, 0.02f);
		ClampSize(0.0f, 0.3f);
		return true;
	}

	return false;
}

bool TitleIcon::SizeUp(float deltaTime, float & counter)
{
	if (counter >= 90)
	{
		const float l_Max = 0.8f;
		float l_Speed = (l_Max - m_Size.x) / 10;
		m_Size += GSvector2(l_Speed, l_Speed);
		ClampSize(0.0f, l_Max);
		return true;
	}

	return false;
}

bool TitleIcon::SizeDown(float deltaTime, float & counter)
{
	if (counter >= 125)
	{
		float l_Speed = (1.0f - m_Size.x) / 10;
		m_Size -= GSvector2(l_Speed, l_Speed);
		ClampSize(0.65f, 1.0f);
		return true;
	}

	return false;
}

void TitleIcon::Alpha()
{
	if (m_Alpha >= 0.5f || m_Alpha <= 0.4f)
		m_AlphaPlus *= -1;

	m_Alpha += m_AlphaPlus;
}

void TitleIcon::ClampSize(float min, float max)
{
	m_Size.x = CLAMP(m_Size.x, min, max);
	m_Size.y = CLAMP(m_Size.y, min, max);
}