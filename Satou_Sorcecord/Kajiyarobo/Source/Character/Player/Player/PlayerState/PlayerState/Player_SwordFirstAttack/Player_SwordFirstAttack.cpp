#include "Player_SwordFirstAttack.h"
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

Player_SwordFirstAttack::Player_SwordFirstAttack(
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

void Player_SwordFirstAttack::OnInitialize()
{
	mCounter = 45;
	pAnimation->ChangeMotion(5);
}

void Player_SwordFirstAttack::Update(float deltaTime)
{
	if (mCounter == 37)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);

		//����̍U���͈͂Ŕ���̑傫����ς���
		float radius =
			7.0f + 0.8f * pGameManager->GetPlayerWepon()->GetRangeLv();
		//ID�擾
		int lID = pID->GetID();
		//�U������
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSwordAttack>(
			pWorld, pGameManager, pPlayer, 6.0f, 20, radius, lID, pPlayer->Damage()));
	}
	if (Dead() == true)
		return;
	if (mCounter <= 28)
	{
		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
		{
			RotateTarget();
			//�U��2�Ɉڍs
			mNextState = PlayerStateName::SwordSecondAttack;
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
		//�ʏ�ɖ߂�
		mNextState = PlayerStateName::Normal;
		return;
	}

	mCounter -= deltaTime;
}

void Player_SwordFirstAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SwordFirstAttack::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_SwordFirstAttack::Shutdown()
{

}
