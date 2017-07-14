#include "BigCursorPosition.h"

BigCursorPosition::BigCursorPosition() :
	DOWN_POSITION(120.0f, 730.0f),
	UP_POSITION(120.0f, 120.0f),
	RIGHT_POSITION(500.0f, 120.0f),
	m_Position(UP_POSITION),
	m_TargetPosition(UP_POSITION),
	m_RandomTime(1),
	m_Target(CursorPosition::Up),
	m_TargetPlus(1)
{
}
void BigCursorPosition::StartUpdate(float deltaTime, float& counter)
{
	TargetMove(deltaTime, m_TargetPosition);

	ChangeTargetPosition(counter);
}

void BigCursorPosition::EndUpdate(float deltaTime, float& counter)
{}

void BigCursorPosition::Draw() const
{}

void BigCursorPosition::TargetMove(float deltaTime, const GSvector2& targetPosition)
{
	GSvector2 l_Velocity = targetPosition - m_Position;
	m_Position += l_Velocity / 10 * deltaTime;
}

/*3‚Â‚ÌŽw’è‚µ‚½ˆÊ’u‚ÉˆÚ“®‚·‚é*/
void BigCursorPosition::ChangeTargetPosition(float & counter)
{
	if ((int)counter % m_RandomTime != 0 || counter <= 160)
		return;

	m_Target += m_TargetPlus;

	if (m_Target == CursorPosition::Right)
	{
		m_TargetPosition = RIGHT_POSITION;
		m_RandomTime = gsRand(counter + 40, counter + 80);
		m_TargetPlus *= -1;
		return;
	}
	if (m_Target == CursorPosition::Up)
	{
		m_TargetPosition = UP_POSITION;
		m_RandomTime = gsRand(counter + 40, counter + 120);
		return;
	}
	if (m_Target == CursorPosition::Down)
	{
		m_TargetPosition = DOWN_POSITION;
		m_RandomTime = gsRand(counter + 40, counter + 120);
		m_TargetPlus *= -1;
		return;
	}
}

GSvector2 BigCursorPosition::GetPosition() const
{
	return m_Position;
}