#include "EnemyMeteorBullet.h"
#include "../../../../Utility/Enum/MeshName.h"
#include "../../../../Base/Actor/World/IWorld.h"
#include "../../../../Base/Actor/Field/Field.h"
#include "../../../../Base/Actor/Ray.Line/Ray.h"
#include "../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../Effect/Explosion/Explosion.h"
#include "../../EnemyAttack/EnemyAttack.h"

EnemyMeteorBullet::EnemyMeteorBullet(IWorld* world, GSvector3& position,
	float count, float radius, int& id, int& damage)
	: Actor(world, "EnemyBullet", position, BoundingSphere(0.0f), nullptr)
	, mHitGround(false)
	, mCounter(count)
	, mRadius(radius)
	, mDamage(damage)
	, m_ID(id)
{

}

void EnemyMeteorBullet::OnUpdate(float deltaTime)
{
	Ray lRay(m_Position, GSvector3(0.0f, 1.0f, 0.0f));
	GSvector3 lInterSect;
	m_World->GetField()->Collision(lRay, &lInterSect);

	if (m_Position.y <= lInterSect.y && mHitGround == false)
	{
		m_World->AddActor(ActorGroup::EnemyAttack, new_Actor<EnemyAttack>(
			m_World, this, 1.0f, mCounter, mRadius, m_ID, mDamage));
		m_World->AddActor(ActorGroup::Effect, new_Actor<Explosion>(m_World, this, 1.0f));
		mHitGround = true;
	}

	if (mHitGround == false)
	{
		GSvector3 lVelocity(0.0f, -3.0f, 0.0f);
		m_Position += lVelocity;
	}
	else if (mCounter <= 0)
		Dead();
	else
		mCounter -= deltaTime;
}

void EnemyMeteorBullet::OnDraw()const
{
	if (mHitGround == false)
	{
		GSmatrix4 lProjection(m_Rotate);
		lProjection.setPosition(m_Position);

		glPushMatrix();
		glMatrixMode(GL_MODELVIEW);
		glMultMatrixf(lProjection);
		gsDrawMesh((GSuint)MeshName::MeteorBullet);
		glPopMatrix();
	}
}

void EnemyMeteorBullet::OnCollide(Actor& other)
{

}