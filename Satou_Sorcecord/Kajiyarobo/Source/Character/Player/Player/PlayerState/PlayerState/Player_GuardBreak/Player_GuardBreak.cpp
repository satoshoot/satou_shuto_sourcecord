#include "Player_GuardBreak.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"

Player_GuardBreak::Player_GuardBreak(
	Player* player,
	AnimationMesh* animation,
	Menu* menu,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	: AbstractPlayer(nullptr, nullptr, player, animation, nullptr, menu, hp, shield, gameManager)
{

}

void Player_GuardBreak::OnInitialize()
{
	pAnimation->ChangeMotion(16);
	mCounter = pAnimation->GetMotionEndTime();
}

void Player_GuardBreak::Update(float deltaTime)
{
	if (mCounter <= 0)
	{
		mNextState = PlayerStateName::Normal;
		return;
	}
	if (pMenu->GetCurrentState() != MenuStateName::Close)
	{
		mNextState = PlayerStateName::OpenMenu;
		return;
	}
	mCounter -= deltaTime;
}

void Player_GuardBreak::HoldDraw()const
{
	WeponDraw();
}

void Player_GuardBreak::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_GuardBreak::Shutdown()
{

}