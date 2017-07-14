#include "Player_SwordThirdAttack.h"
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


Player_SwordThirdAttack::Player_SwordThirdAttack(
	IWorld* world,
	AttackID* id,
	Player* player,
	AnimationMesh* animation,
	Move* move,
	Menu* menu,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	:AbstractPlayer(world, id, player, animation, move, menu, hp, shield, gameManager)
{

}

void Player_SwordThirdAttack::OnInitialize()
{
	mCounter = 55;
	pAnimation->ChangeMotion(7);
}

void Player_SwordThirdAttack::Update(float deltaTime)
{
	if (mCounter == 35)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);

		float radius =
			9.0f + 0.8f * pGameManager->GetPlayerWepon()->GetRangeLv();
		int lID = pID->GetID();

		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSwordAttack>(
			pWorld, pGameManager, pPlayer, 6.0f, 10, radius, lID, pPlayer->Damage()));
	}
	if (Dead() == true)
		return;
	if (mCounter <= 30)
	{
		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
		{
			RotateTarget();
			//UŒ‚4‚ÉˆÚs
			mNextState = PlayerStateName::SwordFourthAttack;
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

void Player_SwordThirdAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SwordThirdAttack::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_SwordThirdAttack::Shutdown()
{

}
