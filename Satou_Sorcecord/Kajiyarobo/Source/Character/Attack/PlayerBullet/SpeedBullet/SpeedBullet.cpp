#include "SpeedBullet.h"
#include "../../../Player/Player/Player.h"
#include "../../../../Utility/Enum/MeshName.h"
#include "../../../../Base/Actor/World/IWorld.h"
#include "../../../../Base/Actor/EventMessage/EventMessage.h"
#include "../../../Effect/SpeedBulletEffect/SpeedBulletEffect.h"
#include "../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../PlayerAttack/PlayerGunAttack.h"
#include "../../../../Wepon/WeponType/WeponType.h"
#include "../../../../Base/Actor/Field/Field.h"

SpeedBullet::SpeedBullet(
	IWorld* world, GSvector3 position, GameManager* gameManager, Actor* player,
	const float& range, int id, int& damage)
	: Actor(world, "PlayerBullet", position, BoundingSphere(2.0f), gameManager)
	, mCounter(30 + range)
	, mPlayerAttack(nullptr)
{
	mVelocity = player->GetRotate().getAxisZ().normalize();

	if (player->GetName() == "Ally")
		m_Name = "AllyBullet";
	mPlayerAttack = new_Actor<PlayerGunAttack>(
		world, gameManager, this, 0.0f, mCounter, 2.0f, id, damage);

	m_World->AddActor(ActorGroup::PlayerAttack, mPlayerAttack);

	const GSvector3 lFront = mVelocity;
	const GSvector3 lUp = m_Rotate.getAxisY().normalize();
	GSvector3 lLeft = lUp.cross(lFront);

	m_Rotate.setAxisX(lLeft);
	m_Rotate.setAxisY(lUp);
	m_Rotate.setAxisZ(lFront);
}

void SpeedBullet::OnUpdate(float deltaTime)
{
	m_Position += mVelocity * 4;

	if (mCounter <= 0)
	{
		Dead();
		mPlayerAttack->Dead();
	}

	HitField();
	mCounter--;
}

void SpeedBullet::OnDraw()const
{
	GSmatrix4 projection(m_Rotate);
	projection.setPosition(m_Position);

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(projection);
	gsDrawMesh((GSuint)MeshName::SpeedBullet);
	glPopMatrix();

	//GetBody().Draw();
}

void SpeedBullet::OnCollide(Actor& other)
{
	if (other.GetName() != "Boss")
		Dead();
}

void SpeedBullet::HitField()
{
	if (m_World->GetField()->Collision(GetBody()))
		Dead();
}

