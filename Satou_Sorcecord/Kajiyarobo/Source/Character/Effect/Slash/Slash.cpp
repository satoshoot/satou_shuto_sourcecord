#include "Slash.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "Cut/Cut.h"

Slash::Slash(IWorld* world, GSvector3 position, GameManager* gameManager)
	:Actor(world, "Slash", position, BoundingSphere(0.0f), gameManager)
{

}

void Slash::OnUpdate(float deltaTime)
{
	for (int i = 0; i < 80; i++)
	{
		m_World->AddActor(ActorGroup::Effect, new_Actor<Cut>(
			m_World, m_Position, p_GameManager, (float)i));
	}
	Dead();
}