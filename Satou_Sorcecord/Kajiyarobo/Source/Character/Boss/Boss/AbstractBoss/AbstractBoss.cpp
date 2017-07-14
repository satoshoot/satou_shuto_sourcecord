#include "AbstractBoss.h"
#include "../BossStateName/BossStateName.h"
#include "../../../../Utility/Math/Math.h"
#include "../../../../Base/Actor/World/IWorld.h"
#include "../../../../Base/Actor/Actor/Actor.h"
#include "../BossTarget/BossTarget.h"
#include "../BossHP/BossHP.h"

AbstractBoss::AbstractBoss(
	IWorld* world, Actor* boss, AnimationMesh* animation, BossHP* hp, AttackID* id)
	: pWorld(world)
	, pBoss(boss)
	, pAnimation(animation)
	, mNextState(BossStateName::None)
	, mVelocity(0.0f, 0.0f, 0.0f)
	, mCounter(0)
	, mTarget(BossTarget::None)
	, mRotateAngle(0.0f)
	, pBossHP(hp)
	, mMovePosition(0.0f, 0.0f, 0.0f)
	, pID(id)
{

}

void AbstractBoss::Initialize()
{
	mNextState = BossStateName::None;
	mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
	OnInitialize();
}

void AbstractBoss::Update(float deltaTime)
{
	OnUpdate(deltaTime);
	mCounter -= deltaTime;
}

BossStateName AbstractBoss::NextState()const
{
	return mNextState;
}

GSvector3 AbstractBoss::GetVelocity()const
{
	return mVelocity;
}

float AbstractBoss::TargetAngle()const
{
	if (mTarget == BossTarget::Player)
		return PlayerAngle();
	else if (mTarget == BossTarget::MovePosition)
		return MovePositionAngle();

	/*ターゲットしていないとき*/
	return 0.0f;
}

float AbstractBoss::PlayerAngle()const
{
	GSvector3 lPlayerVector(pWorld->FindActor("Player")->GetPosition() - pBoss->GetPosition());
	lPlayerVector.normalize();
	const float lPlayerAngle =
		Math::ArcTangent(lPlayerVector.z, lPlayerVector.x);

	GSvector3 lBossFront(pBoss->GetRotate().getAxisZ());
	lBossFront.normalize();
	const float lBossAngle = Math::ArcTangent(lBossFront.z, lBossFront.x);

	float lResult = lBossAngle - lPlayerAngle;

	/*180度までに直す*/
	if (lResult < 0)
		lResult *= -1;

	if (lResult >= 180)
	{
		if (lBossAngle >= lPlayerAngle)
			lResult = lResult - 360;
		else if (lPlayerAngle >= lBossAngle)
			lResult = 360 - lResult;
	}
	else if (lPlayerAngle >= lBossAngle)
		lResult *= -1;

	return lResult;
}

float AbstractBoss::MovePositionAngle()const
{
	GSvector3 lMovePositionVector(mMovePosition - pBoss->GetPosition());
	lMovePositionVector.normalize();
	const float lMoveAngle =
		Math::ArcTangent(lMovePositionVector.z, lMovePositionVector.x);

	GSvector3 lBossFront(pBoss->GetRotate().getAxisZ());
	lBossFront.normalize();
	const float lBossAngle = Math::ArcTangent(lBossFront.z, lBossFront.x);

	float lResult = lBossAngle - lMoveAngle;

	/*180度までに直す*/
	if (lResult < 0)
		lResult *= -1;

	if (lResult >= 180)
	{
		if (lBossAngle >= lMoveAngle)
			lResult = lResult - 360;
		else if (lMoveAngle >= lBossAngle)
			lResult = 360 - lResult;
	}
	else if (lMoveAngle >= lBossAngle)
		lResult *= -1;

	return lResult;
}

bool AbstractBoss::BossKnockBack()const
{
	return pBossHP->KnockBack();
}

bool AbstractBoss::BossDown()
{
	if (pBossHP->Stun())
		return true;

	return false;
}

bool AbstractBoss::Dead()
{
	if (pBossHP->Dead() == true)
	{
		mNextState = BossStateName::Dead;
		return true;
	}
	return false;
}

float AbstractBoss::GetRotateAngle()const
{
	return mRotateAngle;
}

BossTarget AbstractBoss::GetTarget()const
{
	return mTarget;
}

void AbstractBoss::SetTarget(BossTarget& target)
{
	mTarget = target;
}

/*ターゲットしたプレイヤーの位置*/
GSvector3 AbstractBoss::TargetPosition()
{
	if (mTarget == BossTarget::MovePosition)
		return mMovePosition;

	/*ターゲットしていない場合*/
	return  pWorld->FindActor("Player")->GetPosition();
}