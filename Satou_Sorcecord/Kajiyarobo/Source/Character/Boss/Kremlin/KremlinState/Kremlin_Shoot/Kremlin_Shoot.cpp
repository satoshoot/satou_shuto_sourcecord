#include "Kremlin_Shoot.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../Attack/EnemyBullet/EnemyMeteorBullet/EnemyMeteorBullet.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../../Effect/Explosion/Explosion.h"
#include "../../../../Attack/AttackID/AttackID.h"

Kremlin_Shoot::Kremlin_Shoot(IWorld& world, Actor& boss,
	AnimationMesh& animation, BossHP& hp, AttackID& id)
	: AbstractBoss(&world, &boss, &animation, &hp, &id)
{

}

void Kremlin_Shoot::OnInitialize()
{
	pAnimation->ChangeMotion(8);
	mCounter = pAnimation->GetMotionEndTime();
}

void Kremlin_Shoot::OnUpdate(float deltaTime)
{
	if (mCounter == 70)
	{
		const GSmatrix4 lMatrix = pAnimation->GetMatrices().at(14);
		GSvector3 lPosition = lMatrix.getPosition();

		lPosition += pBoss->GetRotate().getAxisZ().normalize() * 10.0f;

		pWorld->AddActor(ActorGroup::Effect, new_Actor<Explosion>(
			pWorld, lPosition));

	}
	if (mCounter == 30)
	{
		int lID = pID->GetID();

		GSvector3& lTargetPosition = pWorld->FindActor("Player")->GetPosition();
		lTargetPosition += GSvector3(0.0f, 50.0f, 0.0f);

		pWorld->AddActor(ActorGroup::Effect, new_Actor<EnemyMeteorBullet>(
			pWorld, lTargetPosition, 30.0f, 13.0f, lID, 100));
	}
}

void Kremlin_Shoot::Change()
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

void Kremlin_Shoot::Shutdown()
{

}