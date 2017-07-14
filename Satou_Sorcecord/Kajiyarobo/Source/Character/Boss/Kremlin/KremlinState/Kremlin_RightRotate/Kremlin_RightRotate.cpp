#include "kremlin_RightRotate.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"


Kremlin_RightRotate::Kremlin_RightRotate(IWorld& world, Actor& boss,
	AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
{

}

void Kremlin_RightRotate::OnInitialize()
{
	mCounter = 60 * 5;
	pAnimation->ChangeMotion(3);
}

void Kremlin_RightRotate::OnUpdate(float deltaTime)
{
	mRotateAngle = 0.5f;

}

void Kremlin_RightRotate::Change()
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
		mNextState = BossStateName::Roar;

}

void Kremlin_RightRotate::Shutdown()
{

}
