#include "Kremlin_Punch.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../Attack/EnemyAttack/EnemyBodyAttack/EnemyBodyAttack.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../../Attack/AttackID/AttackID.h"

Kremlin_Punch::Kremlin_Punch(IWorld& world, Actor& boss,
	AnimationMesh& animation, BossHP& hp, AttackID& id)
	: AbstractBoss(&world, &boss, &animation, &hp, &id)
	, mAngle(0.0f)
{

}

void Kremlin_Punch::OnInitialize()
{
	pAnimation->ChangeMotion(9);
	mCounter = pAnimation->GetMotionEndTime();

	mAngle = -TargetAngle() / (mCounter - 48);
}

void Kremlin_Punch::OnUpdate(float deltaTime)
{
	if (mCounter == 48)
	{
		int lID = pID->GetID();
		pWorld->AddActor(ActorGroup::Effect, new_Actor<EnemyBodyAttack>(
			pWorld, pAnimation, 15, 1.0f, 20.0f, 15.0f, lID, 100));
	}
	else if (mCounter >= 48)
		mRotateAngle = mAngle;
	else
		mRotateAngle = 0.0f;
}

void Kremlin_Punch::Change()
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
		mNextState = BossStateName::Wait;
}

void Kremlin_Punch::Shutdown()
{

}