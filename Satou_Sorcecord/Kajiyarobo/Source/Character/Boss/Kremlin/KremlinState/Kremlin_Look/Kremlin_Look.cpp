#include "Kremlin_Look.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../BossThink/BossThink.h"


Kremlin_Look::Kremlin_Look(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
	, mAngle(0.0f)
{

}

void Kremlin_Look::OnInitialize()
{
	pAnimation->ChangeMotion(10);
	mCounter = pAnimation->GetMotionEndTime();

	//‰ñ‚é‘¬“x
	mAngle = -TargetAngle() / (mCounter - 40);
}

void Kremlin_Look::OnUpdate(float deltaTime)
{
	if (mCounter <= pAnimation->GetMotionEndTime() - 20 && mCounter >= 20)
		mRotateAngle = mAngle;
	else
		mRotateAngle = 0.0f;
}

void Kremlin_Look::Change()
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
	if (mCounter <= 0.0f)
		mNextState = BossThink::LookThink(pBoss, TargetPosition(), pWorld);
}

void Kremlin_Look::Shutdown()
{

}

