#include "RapidBullet.h"
#include "../../../../Base/Actor/World/IWorld.h"
#include "../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../Effect/SpeedBulletEffect/Laser/Laser.h"
#include "../../../../Base/Actor/EventMessage/EventMessage.h"
#include "../../../../Utility/Math/Math.h"
#include "../../../Effect/Particle/Particle.h"
#include "../../../../Utility/Enum/TextureName.h"
#include "../../PlayerAttack/PlayerGunAttack.h"
#include "../../../../Wepon/WeponType/WeponType.h"
#include "../../../../Utility/Enum/MeshName.h"
#include "../../../../Wepon/WeponSpecialSkill/WeponSpecialSkill.h"
#include "../../../../Base/Actor/Field/Field.h"

RapidBullet::RapidBullet(
	IWorld* world, GSvector3& position, GameManager* gameManager, Actor* player, int& id,
	float& counter, const WeponSpecialSkill& skill, float& pitchSwing, float& yawSwing, int& damage)
	: Actor(world, "PlayerBullet", position, BoundingSphere(1.0f), gameManager)
	, mCounter(counter)
	, mPlayerAttack(nullptr)
	, mSkill(skill)
{
	//プレイヤーの前方向ベクトル
	const GSvector3 lFront = player->GetRotate().getAxisZ().normalize();

	//2次元に直す
	const GSvector2 lVec2_PitchFront(1.0f, lFront.y);
	//ピッチの回転角度を求める
	const float lPitchAngle = Math::ArcTangent(lVec2_PitchFront.x, lVec2_PitchFront.y);

	//2次元に直す
	const GSvector2 lVec2_YawFront(lFront.z, lFront.x);
	//ヨーの回転角度を求める
	const float lYawAngle = Math::ArcTangent(lVec2_YawFront.x, lVec2_YawFront.y);

	//ランダムで進む方向を変える
	const GSfloat lPitch = gsRandf(lPitchAngle - pitchSwing, lPitchAngle + pitchSwing);
	const GSfloat lYaw = gsRandf(lYawAngle - yawSwing, lYawAngle + yawSwing);

	mVelocity = GSvector3::createFromPitchYaw(lPitch, lYaw);

	if (player->GetName() == "Ally")
		m_Name = "AllyBullet";
	mPlayerAttack = new_Actor<PlayerGunAttack>(
		world, gameManager, this, 0.0f, mCounter, 2.0f, id, damage);

	m_World->AddActor(ActorGroup::PlayerAttack, mPlayerAttack);

	SetFront();
}

void RapidBullet::OnUpdate(float deltaTime)
{
	m_Position += mVelocity * 4;


	if (mCounter <= 0)
	{
		Dead();
		mPlayerAttack->Dead();
	}

	HitField();
	mCounter -= deltaTime;
}

void RapidBullet::OnDraw()const
{
	GSmatrix4 projection(m_Rotate);
	projection.setPosition(m_Position);

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(projection);
	if (mSkill != WeponSpecialSkill::IceLaser)
		gsDrawMesh((GSuint)MeshName::RapidBullet);
	else
		gsDrawMesh((GSuint)MeshName::Laser);

	glPopMatrix();

	//GetBody().Draw();

}

void RapidBullet::OnCollide(Actor& other)
{
	if (other.GetName() != "Boss")
		Dead();
}

void RapidBullet::SetFront()
{
	const GSvector3 lFront = mVelocity;
	const GSvector3 lLeft = m_Rotate.getAxisY().cross(lFront);
	m_Rotate.setAxisZ(lFront);
	m_Rotate.setAxisX(lLeft);
}

void RapidBullet::HitField()
{
	if (m_World->GetField()->Collision(GetBody()))
		Dead();
}
