#include "Player_SpearSecondAttack.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../Attack/PlayerAttack/PlayerSpearAttack.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../Player.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../../Utility/Enum/SoundName.h"


Player_SpearSecondAttack::Player_SpearSecondAttack(
	IWorld* world,
	AttackID* id,
	Player* player,
	AnimationMesh* animation,
	Move* move,
	Menu* menu,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	: AbstractPlayer(world, id, player, animation, move, menu, hp, shield, gameManager)
{

}

void Player_SpearSecondAttack::OnInitialize()
{
	mCounter = 60;
	pAnimation->ChangeMotion(14);
}

void Player_SpearSecondAttack::Update(float deltaTime)
{
	if (mCounter == 40)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);

		int lID = pID->GetID();

		//UŒ‚”»’è
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, 9.0f, 4, 13.0f, lID, pPlayer->Damage()));
	}
	else if (mCounter == 20)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);

		int lID = pID->GetID();

		//UŒ‚”»’è
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, 9.5f, 4, 13.0f, lID, pPlayer->Damage()));
	}

	if (Dead() == true)
		return;
	if (mCounter <= 0)
	{
		mNextState = PlayerStateName::Normal;
		return;
	}

	mCounter -= deltaTime;
}

void Player_SpearSecondAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SpearSecondAttack::Collide(Actor& other)
{

}

void Player_SpearSecondAttack::Shutdown()
{

}
