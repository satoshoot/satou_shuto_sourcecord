#include "Player_SpearDushAttack.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../Player.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../Attack/PlayerAttack/PlayerSpearAttack.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../../Utility/Enum/SoundName.h"

Player_SpearDushAttack::Player_SpearDushAttack(
	IWorld* world,
	AttackID* id,
	Player* player,
	AnimationMesh* animation,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	: AbstractPlayer(world, id, player, animation, nullptr, nullptr, hp, shield, gameManager)
{

}

void Player_SpearDushAttack::OnInitialize()
{
	mGravity = 1.3f;
	mCounter = 80;
	pAnimation->ChangeMotion(11);
}

void Player_SpearDushAttack::Update(float deltaTime)
{
	if (mCounter >= 25)
	{
		GSvector3 lFront = pPlayer->GetRotate().getAxisZ().normalize();

		mVelocity = lFront / 2.0f;
	}
	else
		mVelocity = GSvector3(0.0f, 0.0f, 0.0f);

	if (mCounter <= 65)
	{
		mVelocity.y = mGravity;
		mGravity -= 0.08f;
	}

	if (mCounter == 45)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);
		int lID = pID->GetID();

		//UŒ‚
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, 6.0f, 40, 5.0f, lID, pPlayer->Damage()));
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, 11.0f, 40, 5.0f, lID, pPlayer->Damage()));
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, 16.0f, 40, 5.0f, lID, pPlayer->Damage()));
	}

	if (Dead() == true)
		return;
	if (mCounter <= 20 && gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
	{
		mNextState = PlayerStateName::SpearFirstAttack;
		return;
	}
	else if (mCounter <= 0)
	{
		mNextState = PlayerStateName::Normal;
		return;
	}

	mCounter -= deltaTime;
}

void Player_SpearDushAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SpearDushAttack::Collide(Actor& other)
{

}

void Player_SpearDushAttack::Shutdown()
{
	mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
}