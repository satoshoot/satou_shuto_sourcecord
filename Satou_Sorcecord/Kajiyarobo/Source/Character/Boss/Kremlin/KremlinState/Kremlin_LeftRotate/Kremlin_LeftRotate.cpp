#include "Kremlin_LeftRotate.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"

Kremlin_LeftRotate::Kremlin_LeftRotate(IWorld& world, Actor& boss,
	AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
{

}

void Kremlin_LeftRotate::OnInitialize()
{
	mCounter = 60 * 5;
	pAnimation->ChangeMotion(2);
}

void Kremlin_LeftRotate::OnUpdate(float deltaTime)
{
	mRotateAngle = -0.5f;
}

void Kremlin_LeftRotate::Change()
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
	if (mCounter <= 0)
	{
		mNextState = BossStateName::Look;
		return;
	}
	if (TargetAngle() <= 15 &&
		TargetAngle() >= -15)
	{
		mNextState = BossStateName::Roar;
		return;
	}

}

void Kremlin_LeftRotate::Shutdown()
{

}
