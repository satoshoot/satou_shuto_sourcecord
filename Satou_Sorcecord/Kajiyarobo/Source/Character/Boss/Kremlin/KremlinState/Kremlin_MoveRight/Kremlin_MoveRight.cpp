#include "Kremlin_MoveRight.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../Base/Actor/Actor/Actor.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../../../Base/Actor/World/IWorld.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../../../Utility/Math/Math.h"
#include "../../../BossThink/BossThink.h"


Kremlin_MoveRight::Kremlin_MoveRight(IWorld& world, Actor& boss,
	AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
	, mEndRotate(false)
{

}

void Kremlin_MoveRight::OnInitialize()
{
	pAnimation->ChangeMotion(3);
	mTarget = BossTarget::MovePosition;
	mMovePosition = -pBoss->GetRotate().getAxisX().normalize() * 200 + pBoss->GetPosition();
	mEndRotate = false;
	mCounter = 60 * 5;
}

void Kremlin_MoveRight::OnUpdate(float deltaTime)
{
	if (TargetAngle() >= -10.0f)
	{
		mRotateAngle = -2.0f;
		mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
		return;
	}

	mRotateAngle = 0.0f;
	pAnimation->ChangeMotion(16);

	GSvector3 lVelocity = mMovePosition - pBoss->GetPosition();
	lVelocity.normalize();
	mVelocity = lVelocity * 2;

	mEndRotate = true;

}

void Kremlin_MoveRight::Change()
{
	if (Dead() == true)
		return;
	if (BossDown() == true)
	{
		mNextState = BossStateName::Down;
		return;
	}
	if (BossKnockBack() == true)
	{
		mNextState = BossStateName::KnockBack;
		return;
	}
	if (BossThink::PlayerHidden(pBoss, mMovePosition, pWorld) &&
		mEndRotate == true)
	{
		mNextState = BossStateName::Wait;
		return;
	}
	if (Math::Distance(pBoss->GetPosition(), mMovePosition) <= 50 || mCounter <= 0)
	{
		mTarget = BossTarget::Player;
		mNextState = BossStateName::Look;
		return;
	}
}

void Kremlin_MoveRight::Shutdown()
{

}