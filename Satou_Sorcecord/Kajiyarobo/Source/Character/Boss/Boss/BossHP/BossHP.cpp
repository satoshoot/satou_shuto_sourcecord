#include "BossHP.h"
#include <gslib.h>

BossHP::BossHP()
	: m_GameClear(this)
	, m_HP(0)
	, m_MaxHP(0)
	, m_StunEnd(false)
	, m_KnockBack(false)
	, m_BossEnd(false)
	, m_QuestClear(false)
{

}

BossHP::~BossHP()
{ }

void BossHP::Start(int hp)
{
	m_HP = hp;
	m_MaxHP = hp;
	m_BossEnd = false;
	m_QuestClear = false;
	m_StunEnd = false;
	m_GameClear.Initialize();
}

void BossHP::Update(float deltaTime)
{
	m_GameClear.Update(deltaTime, Dead());
}

void BossHP::Draw()const
{
	if (Dead() == true)
		m_GameClear.Draw();
}

void BossHP::End()
{
	m_GameClear.End();
}

//ó^Ç¶ÇÁÇÍÇΩÉ_ÉÅÅ[ÉW
void BossHP::Damage(int hp)
{
	m_HP -= hp;

	if (gsRandf(0, 2500) <= hp)
		m_KnockBack = true;

}
//ç°ÇÃHPÇï‘Ç∑
int BossHP::GetHP()const
{
	return m_HP;
}

bool BossHP::Dead()const
{
	if (m_HP <= 0)
		return true;

	return false;
}

bool BossHP::Stun()
{
	if (m_HP <= m_MaxHP / 2 && m_StunEnd == false)
	{
		m_StunEnd = true;

		return true;
	}

	return false;
}

bool BossHP::KnockBack()
{
	if (m_KnockBack == true)
	{
		m_KnockBack = false;
		return true;
	}

	return false;
}

bool BossHP::QuestClear()
{
	return m_QuestClear;
}

void BossHP::QuestEnd()
{
	m_QuestClear = true;
}

bool BossHP::IsBossEnd()
{
	return m_BossEnd;
}

void BossHP::BossEnd()
{
	m_BossEnd = true;
}