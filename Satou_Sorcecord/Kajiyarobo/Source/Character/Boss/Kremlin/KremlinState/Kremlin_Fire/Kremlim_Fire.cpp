#include "Kremlin_Fire.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../Attack/EnemyAttack/EnemyAttack.h"
#include "../../../../Effect/Explosion/Explosion.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../../Attack/AttackID/AttackID.h"

Kremlin_Fire::Kremlin_Fire(IWorld& world, Actor& boss,
	AnimationMesh& animation, BossHP& hp, AttackID& id)
	: AbstractBoss(&world, &boss, &animation, &hp, &id)
	, mAngle(0.0f)
{

}

void Kremlin_Fire::OnInitialize()
{
	pAnimation->ChangeMotion(6);
	mCounter = pAnimation->GetMotionEndTime();


}

void Kremlin_Fire::OnUpdate(float deltaTime)
{
	if (mCounter == 30)
	{
		int lID = pID->GetID();
		pWorld->AddActor(ActorGroup::EnemyAttack, new_Actor<EnemyAttack>(
			pWorld, pBoss, 70.0f, 20.0f, 20.0f, lID, 200));
		pWorld->AddActor(ActorGroup::Effect, new_Actor<Explosion>(pWorld, pBoss, 70.0f));
	}
	else if (mCounter >= 40)
	{
		mAngle = -TargetAngle() / 2;
		mRotateAngle = mAngle;
	}
	else
		mRotateAngle = 0.0f;

}

void Kremlin_Fire::Change()
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

void Kremlin_Fire::Shutdown()
{

}