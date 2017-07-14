#include "SpeedBulletEffect.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "Laser/Laser.h"


SpeedBulletEffect::SpeedBulletEffect(
	IWorld* world, const GSvector3 position, GameManager* gameManager, GSvector3& velocity, float count)
	: Actor(world, "Effect", position, BoundingSphere(0.0f), gameManager)
	, mVelocity(velocity)
	, mCounter(count)
{
	for (int i = 0; i < 5; i++)
	{
		m_World->AddActor(ActorGroup::Effect, new_Actor<Laser>(
			m_World, m_Position - mVelocity * i / 3, p_GameManager, mVelocity, 4.0f, mCounter));
	}
}

void SpeedBulletEffect::OnUpdate(float deltaTime)
{


	m_Position += mVelocity * 4;

	if (mCounter <= 0)
		Dead();

	mCounter -= deltaTime;
}
