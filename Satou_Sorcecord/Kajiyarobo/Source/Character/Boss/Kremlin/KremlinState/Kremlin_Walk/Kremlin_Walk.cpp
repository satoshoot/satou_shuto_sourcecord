#include "Kremlin_Walk.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../Base/Actor/Actor/Actor.h"
#include "../../../../../Utility/Math/Math.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../BossThink/BossThink.h"

Kremlin_Walk::Kremlin_Walk(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp)
	: AbstractBoss(&world, &boss, &animation, &hp, nullptr)
{

}

void Kremlin_Walk::OnInitialize()
{
	pAnimation->ChangeMotion(13);
	mCounter = 60 * 7;
}

void Kremlin_Walk::OnUpdate(float deltaTime)
{
	float lAngle = TargetAngle();
	if (lAngle > 1.0f)
		mRotateAngle = -0.2f;
	else if (lAngle < -1.0f)
		mRotateAngle = 0.2f;
	else
		mRotateAngle = 0.0f;

	GSvector3 lVelocity = pBoss->GetRotate().getAxisZ().normalize();

	mVelocity = lVelocity * 0.2f;

}

void Kremlin_Walk::Change()
{
	GSvector3& lTargetPosition = pWorld->FindActor("Player")->GetPosition();
	float lDistance = Math::Distance(lTargetPosition, pBoss->GetPosition());

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
	if (lDistance <= 150 || mCounter <= 0)
		mNextState = BossThink::Think(pBoss, TargetPosition(), pWorld);
}

void Kremlin_Walk::Shutdown()
{

}