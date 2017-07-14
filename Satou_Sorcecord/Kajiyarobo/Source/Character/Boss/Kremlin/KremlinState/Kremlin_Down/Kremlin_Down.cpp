#include "Kremlin_Down.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossStateName/BossStateName.h"

Kremlin_Down::Kremlin_Down(IWorld& world, AnimationMesh& animation, BossHP& hp)
	:AbstractBoss(&world, nullptr, &animation, &hp, nullptr)
	, mDownState(false)
{

}

void Kremlin_Down::OnInitialize()
{
	pAnimation->ChangeMotion(11);
	mCounter = pAnimation->GetMotionEndTime();
	mDownState = false;
}

void Kremlin_Down::OnUpdate(float deltaTime)
{
	if (mCounter <= 5 && mDownState == false)
	{
		pAnimation->ChangeMotion(12);

		const float& lRand = gsRandf(60 * 10, 60 * 15);
		mCounter = lRand;
		mDownState = true;
	}
}

void Kremlin_Down::Change()
{
	if (Dead() == true)
		return;
	if (mCounter <= 0 && mDownState == true)
		mNextState = BossStateName::Roar;
}

void Kremlin_Down::Shutdown()
{

}