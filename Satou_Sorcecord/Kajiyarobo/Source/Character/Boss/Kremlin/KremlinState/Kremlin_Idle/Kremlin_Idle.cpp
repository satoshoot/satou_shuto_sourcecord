#include "Kremlin_Idle.h"
#include "../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../Base/Actor/Actor/Actor.h"
#include "../../../../../Utility/Math/Math.h"
#include "../../../Boss/BossStateName/BossStateName.h"
#include "../../../Boss/BossTarget/BossTarget.h"
#include "../../../../../Utility/AnimationMesh/AnimationMesh.h"

Kremlin_Idle::Kremlin_Idle(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp) :
	AbstractBoss(&world, &boss, &animation, &hp, nullptr),
	m_PrevHP(0)
{

}

void Kremlin_Idle::OnInitialize()
{
	pAnimation->ChangeMotion(0);
}

void Kremlin_Idle::OnUpdate(float deltaTime)
{ 

}

void Kremlin_Idle::Change()
{
	if (BossDown())
		mNextState = BossStateName::Down;
	else if (BossKnockBack())
		mNextState = BossStateName::KnockBack;


	if (Math::Distance(pWorld->FindActor("Player")->GetPosition(), pBoss->GetPosition()) <= 200.0f)
	{
		mTarget = BossTarget::Player;
		IdleNextState();
	}
}

void Kremlin_Idle::Shutdown()
{

}

void Kremlin_Idle::IdleNextState()
{
	if (Dead() == true)
		return;
	if (TargetAngle() <= -30)
	{
		mNextState = BossStateName::RightRotate;
		return;
	}
	if (TargetAngle() >= 30)
	{
		mNextState = BossStateName::LeftRotate;
		return;
	}
	mNextState = BossStateName::Roar;

}