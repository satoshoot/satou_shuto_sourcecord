#include "Player_SwordFourthAttack.h"
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

Player_SwordFourthAttack::Player_SwordFourthAttack(
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

void Player_SwordFourthAttack::OnInitialize()
{
	mCounter = 65;
	pAnimation->ChangeMotion(8);
}

void Player_SwordFourthAttack::Update(float deltaTime)
{
	if (mCounter == 39)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);

		//•Ší‚ÌUŒ‚”ÍˆÍ‚Å”»’è‚Ì‘å‚«‚³‚ð•Ï‚¦‚é
		float radius =
			9.0f + 0.8f * pGameManager->GetPlayerWepon()->GetRangeLv();
		int id = pID->GetID();

		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSwordAttack>(
			pWorld, pGameManager, pPlayer, 6.0f, 10, radius, id, pPlayer->Damage()));
	}
	if (Dead() == true)
		return;
	if (mCounter <= 30)
	{
		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
		{
			RotateTarget();
			//UŒ‚5‚ÉˆÚs
			mNextState = PlayerStateName::SwordFifthAttack;
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

void Player_SwordFourthAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SwordFourthAttack::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_SwordFourthAttack::Shutdown()
{

}
