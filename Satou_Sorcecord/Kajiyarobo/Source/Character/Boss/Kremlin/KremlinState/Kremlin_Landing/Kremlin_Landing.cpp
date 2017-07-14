#include "Kremlin_Landing.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossStateName/BossStateName.h"

Kremlin_Landing::Kremlin_Landing(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp)
	:AbstractBoss(&world, &boss, &animation, &hp, nullptr)
{

}

void Kremlin_Landing::OnInitialize()
{
	pAnimation->ChangeMotion(4);
	mCounter = pAnimation->GetMotionEndTime();
}

void Kremlin_Landing::OnUpdate(float deltaTime)
{ }

void Kremlin_Landing::Change()
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
		mNextState = BossStateName::Wait;
		return;
	}
}

void Kremlin_Landing::Shutdown()
{

}