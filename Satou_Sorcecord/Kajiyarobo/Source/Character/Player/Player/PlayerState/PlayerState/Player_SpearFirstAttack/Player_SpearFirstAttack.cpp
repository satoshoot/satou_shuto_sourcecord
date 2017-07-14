#include "Player_SpearFirstAttack.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../../Base/Actor/Actor/Actor.h"
#include "../../../../../Attack/PlayerAttack/PlayerSpearAttack.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../Player.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../../Utility/Enum/SoundName.h"

Player_SpearFirstAttack::Player_SpearFirstAttack(
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
	, mAttackCount(0)
{

}

void Player_SpearFirstAttack::OnInitialize()
{
	mCounter = 30;
	mAttackCount++;

	int lAnimationID = 12;
	if (mAttackCount == 2 || mAttackCount == 4)
		lAnimationID = 13;

	pAnimation->ChangeMotion(lAnimationID);
}

void Player_SpearFirstAttack::Update(float deltaTime)
{
	if (Dead() == true)
		return;
	if (mCounter <= 18 && gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X) && mAttackCount >= 4)
	{
		RotateTarget();
		mNextState = PlayerStateName::SpearSecondAttack;
		mAttackCount = 0;
	}
	else if (mCounter <= 18 && gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
	{
		RotateTarget();
		mNextState = PlayerStateName::SpearFirstAttack;
	}
	else if (mCounter <= 0)
	{
		mNextState = PlayerStateName::Normal;
		mAttackCount = 0;
	}

	if (mCounter == 23)
	{
		gsPlaySE((GSuint)SoundName::SpearSE);

		int lID = pID->GetID();

		float lFront = 7.0f - (5 - pGameManager->GetPlayerWepon()->GetRangeLv()) / 3;

		//UŒ‚”»’è
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, lFront, 8, 5.0f, lID, pPlayer->Damage()));
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, lFront * 2, 8, 5.0f, lID, pPlayer->Damage()));
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSpearAttack>(
			pWorld, pGameManager, pPlayer, lFront * 3, 8, 5.0f, lID, pPlayer->Damage()));
	}

	mCounter -= deltaTime;
}

void Player_SpearFirstAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SpearFirstAttack::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_SpearFirstAttack::Shutdown()
{
	if (mNextState != PlayerStateName::SpearFirstAttack)
		mAttackCount = 0;
}