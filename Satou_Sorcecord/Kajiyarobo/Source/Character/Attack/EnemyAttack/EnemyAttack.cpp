#include "EnemyAttack.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../Effect/Particle/Particle.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/EventMessage/EventMessage.h"

EnemyAttack::EnemyAttack(IWorld* world, Actor* enemy,
	float front, float count, float radius, int& id, int& damage)
	: Actor(world, "EnemyAttack", GSvector3(0.0f, 0.0f, 0.0f), BoundingSphere(radius), nullptr)
	, pEnemy(enemy)
	, mFront(front)
	, mCounter(count)
	, m_ID(0)
	, mDamageID(id)
	, mDamage(damage)
{
	mIDList.clear();
}

void EnemyAttack::OnUpdate(float deltaTime)
{
	GSvector3 lFront = pEnemy->GetRotate().getAxisZ().normalize();
	lFront *= mFront;

	m_Position = pEnemy->GetPosition() + lFront;

	if (mCounter <= 0 || pEnemy->IsDead())
		Dead();

	if (mIDList.size() > 10)
		mIDList.pop_front();

	mCounter -= deltaTime;
}

void EnemyAttack::OnDraw()const
{
	//GetBody().Draw();
}

void EnemyAttack::OnCollide(Actor& other)
{
	for (IDList::iterator i = mIDList.begin(); i != mIDList.end(); i++)
	{
		if (m_ID == *i)
			return;
	}

	mIDList.push_back(m_ID);

	//当った相手の方向のベクトル
	GSvector3 front = other.GetPosition() - m_Position;
	front.normalize();

	//パーティクルを出す
	for (int i = 0; i < 5; i++)
	{
		GSvector3 lPosition = m_Position + (front * 4) + GSvector3(0.0f, 5.0f, 0.0f);
		m_World->AddActor(ActorGroup::Effect, new_Actor<Particle>(
			m_World, lPosition, p_GameManager));
	}
}

void EnemyAttack::OnMessage(EventMessage message, void* param)
{
	switch (message)
	{
		int* lID;
	case EventMessage::EnemyHitStopID:
		lID = (int*)param;

		m_ID = *lID;
		break;
	}
}

int EnemyAttack::Damage()const
{
	return mDamage;
}

int EnemyAttack::GetID()const
{
	return mDamageID;
}