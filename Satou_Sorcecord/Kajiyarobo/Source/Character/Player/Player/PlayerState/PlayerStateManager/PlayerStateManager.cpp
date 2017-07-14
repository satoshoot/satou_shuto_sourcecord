#include "PlayerStateManager.h"
#include "../../../PlayerStateName/PlayerStateName.h"
#include "../PlayerState/Player_Normal/Player_Normal.h"
#include "../PlayerState/Player_SwordDushAttack/Player_SwordDushAttack.h"
#include "../PlayerState/Player_SwordFirstAttack/Player_SwordFirstAttack.h"
#include "../PlayerState/Player_SwordSecondAttack/Player_SwordSecondAttack.h"
#include "../PlayerState/Player_SwordThirdAttack/Player_SwordThirdAttack.h"
#include "../PlayerState/Player_SwordFourthAttack/Player_SwordFourthAttack.h"
#include "../PlayerState/Player_SwordFifthAttack/Player_SwordFifthAttack.h"
#include "../PlayerState/Player_SpearDushAttack/Player_SpearDushAttack.h"
#include "../PlayerState/Player_SpearFirstAttack/Player_SpearFirstAttack.h"
#include "../PlayerState/Player_SpearSecondAttack/Player_SpearSecondAttack.h"
#include "../PlayerState/Player_ShootNormal/Player_ShootNormal.h"
#include "../PlayerState/Player_Shoot/Player_Shoot.h"
#include "../PlayerState/Player_ShootRapid/Player_ShootRapid.h"
#include "../PlayerState/Player_OpenMenu/Player_OpenMenu.h"
#include "../PlayerState/Player_Make/Player_Make.h"
#include "../PlayerState/Player_Guard/Player_Guard.h"
#include "../PlayerState/Player_GuardBreak/Player_GuardBreak.h"
#include "../PlayerState/Player_Dead/Player_Dead.h"
#include "../PlayerState/Player_Stun/Player_Stun.h"

PlayerStateManager::PlayerStateManager(
	IWorld* world,
	AttackID* id,
	Player* player,
	AnimationMesh* animation,
	Move* move,
	Menu* menu,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	: mCurrentState(PlayerStateName::Normal)
{
	mStateMap[PlayerStateName::Normal] =
		new Player_Normal(world, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::SwordDushAttack] =
		new Player_SwordDushAttack(world, id, player, animation, hp, shield, gameManager);

	mStateMap[PlayerStateName::SwordFirstAttack] =
		new Player_SwordFirstAttack(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::SwordSecondAttack] =
		new Player_SwordSecondAttack(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::SwordThirdAttack] =
		new Player_SwordThirdAttack(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::SwordFourthAttack] =
		new Player_SwordFourthAttack(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::SwordFifthAttack] =
		new Player_SwordFifthAttack(world, id, player, animation, move, hp, shield, gameManager);

	mStateMap[PlayerStateName::SpearDushAttack] =
		new Player_SpearDushAttack(world, id, player, animation, hp, shield, gameManager);

	mStateMap[PlayerStateName::SpearFirstAttack] =
		new Player_SpearFirstAttack(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::SpearSecondAttack] =
		new Player_SpearSecondAttack(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::ShootNormal] =
		new Player_ShootNormal(world, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::Shoot] =
		new Player_Shoot(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::ShootRapid] =
		new Player_ShootRapid(world, id, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::OpenMenu] =
		new Player_OpenMenu(world, player, animation, move, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::Make] = new Player_Make(world, player, animation, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::Guard] = new Player_Guard(player, animation, menu, hp, gameManager);

	mStateMap[PlayerStateName::GuardBreak] = new Player_GuardBreak(player, animation, menu, hp, shield, gameManager);

	mStateMap[PlayerStateName::Dead] = new Player_Dead(player, animation, gameManager);

	mStateMap[PlayerStateName::Stun] = new Player_Stun(player, animation, menu, shield, gameManager);

	mCurrentPlayer = mStateMap[mCurrentState];
}

void PlayerStateManager::Initialize()
{
	mCurrentPlayer->Initialize();
}

void PlayerStateManager::Update(float deltaTime)
{
	mCurrentPlayer->Update(deltaTime);
}

void PlayerStateManager::HoldDraw()const
{
	mCurrentPlayer->HoldDraw();
}

void PlayerStateManager::Collide(Actor& other)
{
	mCurrentPlayer->Collide(other);
}

void PlayerStateManager::Shutdown()
{
	mCurrentPlayer->Shutdown();
}

void PlayerStateManager::ChangeState()
{
	if (mCurrentPlayer->ChangeState() != PlayerStateName::None)
	{
		mCurrentPlayer->Shutdown();
		mCurrentState = mCurrentPlayer->ChangeState();
		mCurrentPlayer = mStateMap[mCurrentState];
		mCurrentPlayer->Initialize();
	}
}

GSvector3 PlayerStateManager::GetVelocity()const
{
	return mCurrentPlayer->GetVelocity();
}

GSmatrix4 PlayerStateManager::GetRotate()const
{
	return mCurrentPlayer->GetRotate();
}

PlayerStateName PlayerStateManager::GetCurrentState()const
{
	return mCurrentState;
}