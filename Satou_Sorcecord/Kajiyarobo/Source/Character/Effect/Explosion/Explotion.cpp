#include "Explosion.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "Fire/Fire.h"
#include "../../../Utility/Enum/SoundName.h"

Explosion::Explosion(IWorld* world, Actor* enemy, float front)
	:Actor(world, "Explosion", GSvector3(0.0f, 0.0f, 0.0f), BoundingSphere(0.0f), nullptr)
{
	for (int i = 0; i < 200; i++)
	{
		m_World->AddActor(ActorGroup::Effect, new_Actor<Fire>(m_World, enemy, front));
	}

	gsPlaySE((GSuint)SoundName::ExplotionSE);
	Dead();
}

Explosion::Explosion(IWorld* world, GSvector3& position)
	: Actor(world, "Explotion", position, BoundingSphere(0.0f), nullptr)
{
	for (int i = 0; i < 200; i++)
	{
		m_World->AddActor(ActorGroup::Effect, new_Actor<Fire>(m_World, position));
	}
	gsPlaySE((GSuint)SoundName::ExplotionSE);

	Dead();
}