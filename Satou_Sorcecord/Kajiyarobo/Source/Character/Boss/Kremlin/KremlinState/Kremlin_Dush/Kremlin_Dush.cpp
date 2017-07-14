#include "Kremlin_Dush.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../Base/Actor/Actor/Actor.h"
#include "../../../../../Utility/Math/Math.h"
#include "../../../Boss/BossStateName/BossStateName.h"


Kremlin_Dush::Kremlin_Dush(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
	, mTargetVelocity(0.0f, 0.0f, 0.0f)
	, mTargetPosition(0.0f, 0.0f, 0.0f)
{

}

void Kremlin_Dush::OnInitialize()
{
	pAnimation->ChangeMotion(16);
	mCounter = 60 * 7;
}

void Kremlin_Dush::OnUpdate(float deltaTime)
{
	float lAngle = TargetAngle();
	if (lAngle > 1.0f)
		mRotateAngle = -1.0f;
	else if (lAngle < -1.0f)
		mRotateAngle = 1.0f;
	else
		mRotateAngle = 0.0f;

	/*ターゲットの位置を取得*/
	mTargetPosition = TargetPosition();
	/*ターゲット方向のベクトル*/
	mTargetVelocity = mTargetPosition - pBoss->GetPosition();
	mTargetVelocity.normalize();

	mVelocity = mTargetVelocity * 2;
}

void Kremlin_Dush::Change()
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
	if (Math::Distance(mTargetPosition, pBoss->GetPosition()) <= 50 ||
		mCounter <= 0)
	{
		mNextState = BossStateName::Wait;
		return;
	}
}

void Kremlin_Dush::Shutdown()
{

}