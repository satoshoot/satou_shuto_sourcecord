#include "PlayerAttack.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/EventMessage/EventMessage.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../Effect/Slash/Slash.h"
#include "../../Effect/Particle/Particle.h"
#include "../../../Wepon/WeponType/WeponType.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Wepon/Wepon/Wepon.h"
#include "../../../Utility/Enum/SoundName.h"
#include "../../../Utility/Enum/EffectName.h"
#include <GSeffect.h>

PlayerAttack::PlayerAttack(IWorld* world, GameManager* gameManaer, Actor* player,
	float front, float timer, float radius, int id, int& damage)
	:Actor(world, "PlayerAttack", GSvector3(0.0f, 0.0f, 0.0f), BoundingSphere(radius), gameManaer)
	, mCounter(timer)
	, pPlayer(player)
	, mFront(front)
	, mDamage(damage)
{
	m_World->sendMessage(EventMessage::EnemyDamageID, &id);
	mIDList.clear();
	mIDList.push_back(0);
}
void PlayerAttack::OnUpdate(float time)
{
	GSvector3 lFront = pPlayer->GetRotate().getAxisZ().normalize();
	lFront *= mFront;

	m_Position = pPlayer->GetPosition() + lFront;


	if (mCounter <= 0 || pPlayer->IsDead())
		Dead();

	if (mIDList.size() > 10)
		mIDList.pop_front();

	mCounter--;
}

void PlayerAttack::OnDraw()const
{
	//GetBody().Draw();
}

void PlayerAttack::OnCollide(Actor& other)
{
	for (IntList::iterator i = mIDList.begin(); i != mIDList.end(); i++)
	{
		if (m_ID == *i)
			return;
	}

	mIDList.push_back(m_ID);


	//パーティクルの個数
	int lParticleMax = 5;
	//当った相手の方向のベクトル
	GSvector3 front = other.GetPosition() - m_Position;
	front.normalize();



	Effect(other, front);

}

void PlayerAttack::OnMessage(EventMessage message, void* param)
{
	switch (message)
	{
	case EventMessage::PlayerHitStopID:
		int* lID = (int*)param;

		m_ID = *lID;

		break;
	}
}

void PlayerAttack::AddParticle(int num, GSvector3& front)
{
	//パーティクルを出す
	for (int i = 0; i < num; i++)
	{
		GSvector3 lPosition = m_Position + (front * 4) + GSvector3(0.0f, 5.0f, 0.0f);
		m_World->AddActor(ActorGroup::Effect, new_Actor<Particle>(
			m_World, lPosition, p_GameManager));
	}
}

int PlayerAttack::Damage()const
{
	return mDamage;
}