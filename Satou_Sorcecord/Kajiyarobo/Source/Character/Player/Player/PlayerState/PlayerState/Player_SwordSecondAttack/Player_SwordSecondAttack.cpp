#include "Player_SwordSecondAttack.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../Attack/PlayerAttack/PlayerSwordAttack.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Player.h"
#include "../../../../../../Utility/Enum/SoundName.h"

Player_SwordSecondAttack::Player_SwordSecondAttack(
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

void Player_SwordSecondAttack::OnInitialize()
{
	mCounter = 60;
	pAnimation->ChangeMotion(6);
}

void Player_SwordSecondAttack::Update(float deltaTime)
{
	if (mCounter == 48)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);

		float radius =
			7.0f + 0.8f * pGameManager->GetPlayerWepon()->GetRangeLv();
		int id = pID->GetID();

		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSwordAttack>(
			pWorld, pGameManager, pPlayer, 7.0f, 13, radius, id, pPlayer->Damage()));
	}
	if (Dead() == true)
		return;
	if (mCounter <= 40)
	{
		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
		{
			RotateTarget();
			//UŒ‚3‚ÉˆÚs
			mNextState = PlayerStateName::SwordThirdAttack;
			return;
		}
		if (gsXBoxPadButtonState(0, GS_XBOX_PAD_A))
		{
			mNextState = PlayerStateName::Guard;
			return;
		}
	}
	if (mCounter <= 0)
	{
		//’Êí‚É–ß‚é
		mNextState = PlayerStateName::Normal;
		return;
	}

	mCounter -= deltaTime;
}

void Player_SwordSecondAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SwordSecondAttack::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_SwordSecondAttack::Shutdown()
{

}
