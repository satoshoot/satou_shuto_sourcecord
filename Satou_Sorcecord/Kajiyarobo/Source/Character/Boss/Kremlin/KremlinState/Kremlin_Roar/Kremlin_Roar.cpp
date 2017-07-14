#include "Kremlin_Roar.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../BossThink/BossThink.h"

Kremlin_Roar::Kremlin_Roar(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
{

}

void Kremlin_Roar::OnInitialize()
{
	pAnimation->ChangeMotion(1);
	mCounter = pAnimation->GetMotionEndTime();
}

void Kremlin_Roar::OnUpdate(float deltaTime)
{ }

void Kremlin_Roar::Change()
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
	else if (mCounter <= 0)
		mNextState = BossThink::Think(pBoss, TargetPosition(), pWorld);
}

void Kremlin_Roar::Shutdown()
{

}