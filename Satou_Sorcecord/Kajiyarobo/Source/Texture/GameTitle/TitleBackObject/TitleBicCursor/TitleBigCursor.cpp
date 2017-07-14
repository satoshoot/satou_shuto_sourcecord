#include "TitleBigCursor.h"
#include "BigCursorPosition.h"

TitleBigCursor::TitleBigCursor(BigCursorPosition& basePosition) :
	p_CursorPosition(&basePosition),
	m_Position(120.0f, 120.0f),
	m_Scale(0.0f, 0.0f),
	m_Angle(0.0f),
	m_AngleMax(120.0f),
	m_RandomTime(gsRand(1, 180))

{
}

void TitleBigCursor::StartUpdate(float deltaTime, float& counter)
{
	if (counter <= 100 ||
		OpenCursor(deltaTime, counter))
		return;

	m_Position = p_CursorPosition->GetPosition();
	m_Scale = GSvector2(1.0f, 1.0f);
	Rotate(deltaTime, counter);
}

void TitleBigCursor::EndUpdate(float deltaTime, float& counter)
{
	Rotate(deltaTime, counter);

	if (counter <= 40 || m_Scale <= GSvector2(0.0f, 0.0f))
		return;

	m_Scale -= GSvector2(0.3f, 0.3f) * deltaTime;
	m_Scale.x = CLAMP(m_Scale.x, 0.0f, 1.0f);
	m_Scale.y = CLAMP(m_Scale.y, 0.0f, 1.0f);
}

void TitleBigCursor::Draw() const
{
	const GSvector2 TEXTURE_SIZE(630.0f, 630.0f);
	GSrect l_Rect(0.0f, 0.0f, TEXTURE_SIZE.x, TEXTURE_SIZE.y);
	GSvector2 l_Center(TEXTURE_SIZE.x / 2, TEXTURE_SIZE.y / 2);
	GScolor l_Color(1.0f, 1.0f, 1.0f, 0.3f);

	gsDrawSprite2D(
		(GSuint)TextureName::TitleBigCursor,
		&m_Position,
		&l_Rect,
		&l_Center,
		&l_Color,
		&m_Scale,
		m_Angle);
}

bool TitleBigCursor::OpenCursor(float deltaTime, float& counter)
{
	if (counter <= 160)
	{
		const float l_Max = 1.0f;
		float l_Speed = (l_Max - m_Scale.x) / 10;
		m_Scale += GSvector2(l_Speed, l_Speed) * deltaTime;
		m_Scale.x = CLAMP(m_Scale.x, 0.0f, l_Max);
		m_Scale.y = CLAMP(m_Scale.y, 0.0f, l_Max);

		return true;
	}
	return false;
}

void TitleBigCursor::Rotate(float deltaTime, float& counter)
{
	if ((int)counter % m_RandomTime == 0)
	{
		m_AngleMax = gsRand(0.0f, 180.0f);
		m_AngleMax *= -1;
		m_RandomTime = gsRand(counter + 30.0f, counter + 80.0f);
	}
	m_Angle += (m_AngleMax - m_Angle) / 13 * deltaTime;
}