#include "TitleCursor.h"

TitleCursor::TitleCursor() :
	UP_ICON_POSITION(WIDTH - 200.0f, 550.0f),
	UNDER_ICON_POSITION(WIDTH - 200.0f, 750.0f),
	SCALE(2.5f),
	m_Position(UP_ICON_POSITION.x - 200.0f, UP_ICON_POSITION.y - 150.0f),
	m_Center(0.0f, 0.0f),
	m_Angle(0.0f),
	m_Size(0.0f, 0.0f),
	m_TargetPosition(UP_ICON_POSITION),
	m_PositionDown(false),
	m_RandomTime(gsRand(30.0f, 150.0f))
{

}

void TitleCursor::StartUpdate(float deltaTime, float& counter)
{
	if (counter <= 100 //100fÇ‹Ç≈ÇÕâΩÇ‡ÇµÇ»Ç¢
		|| OpenCursor(deltaTime, counter)
		|| ChangeTargetPosition(counter))
		return;

	m_Angle += 1.0f * deltaTime;
	m_Size = GSvector2(30.0f, 30.0f);
	m_Center = GSvector2(15.0f, 15.0f);
	Move(deltaTime, counter);
}

void TitleCursor::EndUpdate(float deltaTime, float& counter)
{
	m_Angle += 1.0f;
	if (counter >= 80)
	{
		m_Size -= GSvector2(1.5, 1.5f)*deltaTime;
		m_Size.x = CLAMP(m_Size.x, 0.0f, 30.0f);
		m_Size.y = CLAMP(m_Size.y, 0.0f, 30.0f);
	}
}

void TitleCursor::Draw()const
{
	GSrect l_Rect(0.0f, 0.0f, m_Size.x, m_Size.y);
	GScolor l_Color(1.0f, 1.0f, 1.0f, 0.4f);
	const GSvector2 l_Scale(SCALE, SCALE);

	gsDrawSprite2D(
		(GSuint)TextureName::Target,
		&m_Position,
		&l_Rect,
		&m_Center,
		&l_Color,
		&l_Scale,
		m_Angle);
}

bool TitleCursor::OpenCursor(float deltaTime, float& counter)
{
	if (counter == 120)
	{
		m_Center = GSvector2(15.0f, 15.0f);
		m_Position += GSvector2(15.0f * SCALE, 15.0f * SCALE); //íÜêSÇ∆à íuÇçáÇÌÇπÇÈ
		m_RandomTime = gsRand(counter + 30.0f, counter + 150.0f);
		return true;
	}
	if (counter <= 120)
	{
		m_Size += GSvector2(1.5f, 1.5f) * deltaTime;
		m_Size.x = CLAMP(m_Size.x, 0.0f, 30.0f);
		m_Size.y = CLAMP(m_Size.y, 0.0f, 30.0f);
		return true;
	}
	return false;
}

bool TitleCursor::ChangeTargetPosition(float& counter)
{
	if ((int)counter % m_RandomTime == 0)
	{
		if (m_PositionDown == false)
		{
			m_TargetPosition = UP_ICON_POSITION;
			m_RandomTime = gsRand(counter + 30.0f, counter + 120.0f);
			m_PositionDown = true;
			return true;
		}
		m_TargetPosition = UNDER_ICON_POSITION;
		m_RandomTime = gsRand(counter + 30.0f, counter + 120.0f);
		m_PositionDown = false;
		return true;
	}

	return false;
}

void TitleCursor::Move(float deltaTime, float& counter)
{
	GSvector2 l_Velocity = m_TargetPosition - m_Position;

	m_Position += l_Velocity / 10 * deltaTime;
}
