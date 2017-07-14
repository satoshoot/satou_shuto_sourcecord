#include "Kremlin_Rush.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../Attack/EnemyAttack/EnemyBodyAttack/EnemyBodyAttack.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../../Attack/AttackID/AttackID.h"

Kremlin_Rush::Kremlin_Rush(IWorld& world, Actor& boss,
	AnimationMesh& animation, BossHP& hp, AttackID& id)
	: AbstractBoss(&world, &boss, &animation, &hp, &id)
{

}

void Kremlin_Rush::OnInitialize()
{
	pAnimation->ChangeMotion(7);
	mCounter = pAnimation->GetMotionEndTime();
}

void Kremlin_Rush::OnUpdate(float deltaTime)
{
	if (mCounter == 110)
	{
		int lBornID = 6;
		int lID = pID->GetID();
		for (int i = 0; i < 4; i++)
		{
			pWorld->AddActor(ActorGroup::EnemyAttack, new_Actor<EnemyBodyAttack>(
				pWorld, pAnimation, lBornID, 1.0f, 50.0f, 20.0f, lID, 150));
			lBornID++;
		}
		mVelocity = pWorld->FindActor("Player")->GetPosition() - pBoss->GetPosition();
		mVelocity.normalize();

		mVelocity *= 2.5f;
		mVelocity.y = 0.0f;

	}
	else if (mCounter <= 60.0f)
		mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
}

void Kremlin_Rush::Change()
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
		mNextState = BossStateName::Wait;
}

void Kremlin_Rush::Shutdown()
{

}