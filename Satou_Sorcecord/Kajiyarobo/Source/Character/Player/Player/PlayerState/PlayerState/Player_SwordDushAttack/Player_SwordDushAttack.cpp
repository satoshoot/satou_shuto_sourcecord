#include "Player_SwordDushAttack.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../Attack/PlayerAttack/PlayerSwordAttack.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../Player.h"
#include "../../../../../../Utility/Enum/SoundName.h"

Player_SwordDushAttack::Player_SwordDushAttack(
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

void Player_SwordDushAttack::OnInitialize()
{
	mCounter = 55;
	pAnimation->ChangeMotion(7);
	mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
}

void Player_SwordDushAttack::Update(float deltaTime)
{
	if (mCounter == 32)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);
		//����̍U���͈͂Ŕ���̑傫����ς���
		float radius =
			9.0f + 0.8f * pGameManager->GetPlayerWepon()->GetRangeLv();
		//ID�擾
		int lID = pID->GetID();

		//�U������
		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSwordAttack>(
			pWorld, pGameManager, pPlayer, 6.0f, 8, radius, lID,
			pPlayer->Damage()));
	}
	if (mCounter >= 30)
	{
		//�U�����̈ړ�
		GSvector3 front = pPlayer->GetRotate().getAxisZ().normalize();
		mVelocity = front / 2;
	}
	else
		mVelocity = GSvector3(0.0f, 0.0f, 0.0f);

	if (Dead() == true)
		return;
	if (mCounter <= 25)
	{
		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
		{
			//�U��2�Ɉڍs
			mNextState = PlayerStateName::SwordFirstAttack;
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

void Player_SwordDushAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SwordDushAttack::Collide(Actor& other)
{

}

void Player_SwordDushAttack::Shutdown()
{
	mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
}