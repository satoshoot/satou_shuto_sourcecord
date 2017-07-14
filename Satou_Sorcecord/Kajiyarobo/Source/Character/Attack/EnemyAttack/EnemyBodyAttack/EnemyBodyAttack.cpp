#include "EnemyBodyAttack.h"
#include "../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../Base/Actor/World/IWorld.h"
#include "../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../EnemyAttack.h"

EnemyBodyAttack::EnemyBodyAttack(IWorld* world, AnimationMesh* animation,
	int born, float front, float count, float radius, int& id, int& damage)
	: Actor(world, "EnemyBodyAttack", GSvector3(0.0f, 0.0f, 0.0f), BoundingSphere(0.0f), nullptr)
	, pAnimation(animation)
	, mCounter(count)
	, mBornID(born)
{
	m_World->AddActor(ActorGroup::EnemyAttack, new_Actor<EnemyAttack>(
		m_World, this, front, count, radius, id, damage));
}

void EnemyBodyAttack::OnUpdate(float deltaTime)
{
	const GSmatrix4 lBornPosition = pAnimation->GetMatrices().at(mBornID);

	m_Position = lBornPosition.getPosition();

	if (mCounter <= 0)
		Dead();

	mCounter -= deltaTime;
}

void EnemyBodyAttack::OnDraw()const
{

}

void EnemyBodyAttack::OnCollide(Actor& other)
{

}