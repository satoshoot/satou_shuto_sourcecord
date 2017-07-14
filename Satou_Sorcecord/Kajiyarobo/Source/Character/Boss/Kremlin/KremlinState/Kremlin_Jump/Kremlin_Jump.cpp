#include "Kremlin_Jump.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../Base/Actor/Actor/Actor.h"
#include "../../../../../Utility/Math/Math.h"
#include "../../../Boss/BossStateName/BossStateName.h"

Kremlin_Jump::Kremlin_Jump(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
	, mTargetPosition(0.0f, 0.0f, 0.0f)
	, mTargetVelocity(0.0f, 0.0f, 0.0f)
{

}

void Kremlin_Jump::OnInitialize()
{
	pAnimation->ChangeMotion(5);
	mCounter = pAnimation->GetMotionEndTime();

	mTargetPosition = TargetPosition();

	mTargetVelocity = mTargetPosition - pBoss->GetPosition();
	mTargetVelocity.normalize();
}

void Kremlin_Jump::OnUpdate(float deltaTime)
{
	float lAngle = TargetAngle();
	if (lAngle > 1.0f)
		mRotateAngle = -1.0f;
	else if (lAngle < -1.0f)
		mRotateAngle = 1.0f;
	else
		mRotateAngle = 0.0f;

	if (mCounter <= pAnimation->GetMotionEndTime() - 30)
		mVelocity = mTargetVelocity * 5;
}

void Kremlin_Jump::Change()
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
	if (Math::Distance(mTargetPosition, pBoss->GetPosition()) <= 50.0f ||
		mCounter <= 10)
		mNextState = BossStateName::Landing;
}

void Kremlin_Jump::Shutdown()
{

}