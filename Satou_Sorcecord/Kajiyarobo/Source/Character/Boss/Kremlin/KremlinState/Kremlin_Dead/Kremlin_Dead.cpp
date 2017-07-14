#include "Kremlin_Dead.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"

Kremlin_Dead::Kremlin_Dead(AnimationMesh& mesh, BossHP& hp)
	: AbstractBoss(nullptr, nullptr, &mesh, &hp, nullptr)
{

}

void Kremlin_Dead::OnInitialize()
{
	pAnimation->ChangeMotion(17);
	mCounter = pAnimation->GetMotionEndTime() + 60;
}

void Kremlin_Dead::OnUpdate(float deltaTime)
{
	if (mCounter <= 0)
	{
		pAnimation->ChangeMotion(18);
		return;
	}

	mCounter -= deltaTime;
}

void Kremlin_Dead::Change()
{ }

void Kremlin_Dead::Shutdown()
{ }