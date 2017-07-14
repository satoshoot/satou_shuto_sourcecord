#include "KremlinStateManager.h"
#include "../../Boss/BossStateName/BossStateName.h"

/*AbstractBoss*/
#include "../KremlinState/Kremlin_Idle/Kremlin_Idle.h"
#include "../KremlinState/Kremlin_LeftRotate/Kremlin_LeftRotate.h"
#include "../KremlinState/Kremlin_Look/Kremlin_Look.h"
#include "../KremlinState/Kremlin_RightRotate/kremlin_RightRotate.h"
#include "../KremlinState/Kremlin_Roar/Kremlin_Roar.h"
#include "../KremlinState/Kremlin_Fire/Kremlin_Fire.h"
#include "../KremlinState/Kremlin_Punch/Kremlin_Punch.h"
#include "../KremlinState/Kremlin_Wait/Kremlin_Wait.h"
#include "../KremlinState/Kremlin_Shoot/Kremlin_Shoot.h"
#include "../KremlinState/Kremlin_Rush/Kremlin_Rush.h"
#include "../KremlinState/Kremlin_Walk/Kremlin_Walk.h"
#include "../KremlinState/Kremlin_Down/Kremlin_Down.h"
#include "../KremlinState/Kremlin_KnockBack/Kremlin_KnockBack.h"
#include "../KremlinState/Kremlin_Dush/Kremlin_Dush.h"
#include "../KremlinState/Kremlin_Jump/Kremlin_Jump.h"
#include "../KremlinState/Kremlin_Landing/Kremlin_Landing.h"
#include "../KremlinState/Kremlin_MoveLeft/Kremlin_MoveLeft.h"
#include "../KremlinState/Kremlin_MoveRight/Kremlin_MoveRight.h"
#include "../KremlinState/Kremlin_Dead/Kremlin_Dead.h"

KremlinStateManager::KremlinStateManager() :
	m_CurrendBoss(nullptr),
	m_CurrentState(BossStateName::Idle)
{
}

void KremlinStateManager::Initialize(IWorld & world, Actor & boss, AnimationMesh & animation, BossHP & hp, AttackID & id)
{
	/*ó‘Ô‚Ì’Ç‰Á*/
	AddState(world, boss, animation, hp, id);
	m_CurrentState = BossStateName::Idle;
	m_CurrendBoss = m_StateMap[m_CurrentState];
	m_CurrendBoss->Initialize();
}

void KremlinStateManager::Update(float deltaTime)
{
	m_CurrendBoss->Update(deltaTime);
}

void KremlinStateManager::ChangeState()
{
	if (m_CurrendBoss->NextState() != BossStateName::None)
	{
		BossTarget lTarget = m_CurrendBoss->GetTarget();
		m_CurrendBoss->Shutdown();
		m_CurrentState = m_CurrendBoss->NextState();
		m_CurrendBoss = m_StateMap[m_CurrentState];
		m_CurrendBoss->SetTarget(lTarget);
		m_CurrendBoss->Initialize();
	}
}

void KremlinStateManager::Change()
{
	m_CurrendBoss->Change();
}

void KremlinStateManager::Move(GSvector3 & position)
{
	position += m_CurrendBoss->GetVelocity();
}

void KremlinStateManager::RotateY(GSmatrix4 & rotate)
{
	rotate.rotateY(m_CurrendBoss->GetRotateAngle());
}

void KremlinStateManager::AddState(IWorld& world, Actor& boss, AnimationMesh& animation,
	BossHP& hp, AttackID& id)
{
	m_StateMap.clear();
	m_StateMap[BossStateName::Idle] = std::make_shared<Kremlin_Idle>(world, boss, animation, hp);
	m_StateMap[BossStateName::LeftRotate] = std::make_shared<Kremlin_LeftRotate>(world, boss, animation, hp);
	m_StateMap[BossStateName::Look] = std::make_shared<Kremlin_Look>(world, boss, animation, hp);
	m_StateMap[BossStateName::RightRotate] = std::make_shared<Kremlin_RightRotate>(world, boss, animation, hp);
	m_StateMap[BossStateName::Roar] = std::make_shared<Kremlin_Roar>(world, boss, animation, hp);
	m_StateMap[BossStateName::Fire] = std::make_shared<Kremlin_Fire>(world, boss, animation, hp, id);
	m_StateMap[BossStateName::Punch] = std::make_shared<Kremlin_Punch>(world, boss, animation, hp, id);
	m_StateMap[BossStateName::Wait] = std::make_shared<Kremlin_Wait>(world, boss, animation, hp);
	m_StateMap[BossStateName::Shoot] = std::make_shared<Kremlin_Shoot>(world, boss, animation, hp, id);
	m_StateMap[BossStateName::Rush] = std::make_shared<Kremlin_Rush>(world, boss, animation, hp, id);
	m_StateMap[BossStateName::Walk] = std::make_shared<Kremlin_Walk>(world, boss, animation, hp);
	m_StateMap[BossStateName::Down] = std::make_shared<Kremlin_Down>(world, animation, hp);
	m_StateMap[BossStateName::KnockBack] = std::make_shared<Kremlin_KnockBack>(world, animation, hp);
	m_StateMap[BossStateName::Dush] = std::make_shared<Kremlin_Dush>(world, boss, animation, hp);
	m_StateMap[BossStateName::Jump] = std::make_shared<Kremlin_Jump>(world, boss, animation, hp);
	m_StateMap[BossStateName::Landing] = std::make_shared<Kremlin_Landing>(world, boss, animation, hp);
	m_StateMap[BossStateName::MoveLeft] = std::make_shared<Kremlin_MoveLeft>(world, boss, animation, hp);
	m_StateMap[BossStateName::MoveRight] = std::make_shared<Kremlin_MoveRight>(world, boss, animation, hp);
	m_StateMap[BossStateName::Dead] = std::make_shared<Kremlin_Dead>(animation, hp);
}
