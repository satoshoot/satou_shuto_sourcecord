#include "Kremlin_Wait.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../BossThink/BossThink.h"
#include "../../../Boss/BossTarget/BossTarget.h"

Kremlin_Wait::Kremlin_Wait(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
{

}

void Kremlin_Wait::OnInitialize()
{
	mTarget = BossTarget::Player;
	pAnimation->ChangeMotion(15);
	mCounter = gsRandf(20, 60 * 2);
}

void Kremlin_Wait::OnUpdate(float deltaTime)
{ }

void Kremlin_Wait::Change()
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
		mNextState = BossThink::Think(pBoss, TargetPosition(), pWorld);
}

void Kremlin_Wait::Shutdown()
{

}