#include "Kremlin_KnockBack.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossStateName/BossStateName.h"

Kremlin_KnockBack::Kremlin_KnockBack(IWorld& world, AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, nullptr, &animation, &hp, nullptr)
{

}

void Kremlin_KnockBack::OnInitialize()
{
	pAnimation->ChangeMotion(14);
	mCounter = pAnimation->GetMotionEndTime();
}

void Kremlin_KnockBack::OnUpdate(float deltaTime)
{

}

void Kremlin_KnockBack::Change()
{
	if (Dead() == true)
		return;
	if (mCounter <= 0)
		mNextState = BossStateName::Wait;
}

void Kremlin_KnockBack::Shutdown()
{

}