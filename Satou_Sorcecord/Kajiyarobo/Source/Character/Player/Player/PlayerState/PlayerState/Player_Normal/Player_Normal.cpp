#include "Player_Normal.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../../Utility/Move/Move.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../../Wepon/WeponType/WeponType.h"
#include "../../../Player.h"
#include "../../../../../../Base/Actor/Camera/Camera.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"
#include "../../../PlayerHP/PlayerHP.h"

Player_Normal::Player_Normal(
	IWorld* world,
	Player* player,
	AnimationMesh* animation,
	Move* move,
	Menu* menu,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	: AbstractPlayer(world, nullptr, player, animation, move, menu, hp, shield, gameManager)
{

}

void Player_Normal::OnInitialize()
{
	mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
}

void Player_Normal::Update(float deltaTime)
{
	int lAnimationID = 0;

	GSvector3& left = pWorld->GetCamera()->GetRotate().getAxisX().normalize();

	//�ړ��͂���
	GSvector3 lVelocity = pMove->Velocity(left);

	//�ړ����鑬�x
	float speed = pMove->Speed();
	lVelocity *= speed;

	mVelocity = lVelocity * 1.3f * deltaTime;

	//�_�b�V���A�j���[�V�����ɕς���
	if (speed >= 0.7f)
		lAnimationID = 1;

	pAnimation->ChangeMotion(lAnimationID);

	if (Dead() == true || pHP->Dead())
		return;
	if (pMenu->GetCurrentState() != MenuStateName::Close)
	{
		mNextState = PlayerStateName::OpenMenu;
		return;
	}
	if (pGameManager->GetPlayerWepon()->GetWeponType() == WeponType::Gun)
	{
		mNextState = PlayerStateName::ShootNormal;
		return;
	}

	if (gsXBoxPadButtonState(0, GS_XBOX_PAD_A))
	{
		mNextState = PlayerStateName::Guard;
		return;
	}

	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
	{
		if (pGameManager->GetPlayerWepon()->GetWeponType() == WeponType::Sword)
		{
			if (speed >= 0.7f)
			{
				//�ړ����Ă��鎞�̓_�b�V���A�^�b�N
				mNextState = PlayerStateName::SwordDushAttack;
				return;
			}
			else
			{
				RotateTarget();
				//���U��1
				mNextState = PlayerStateName::SwordFirstAttack;
				return;
			}
		}
		if (pGameManager->GetPlayerWepon()->GetWeponType() == WeponType::Spear)
		{
			if (speed >= 0.7f)
			{
				//�ړ����Ă��鎞�̓_�b�V���A�^�b�N
				mNextState = PlayerStateName::SpearDushAttack;
				return;
			}
			else
			{
				RotateTarget();
				//���U���P
				mNextState = PlayerStateName::SpearFirstAttack;
				return;
			}
		}
	}

	Rotate();
}

void Player_Normal::HoldDraw()const
{
	WeponDraw();
}

void Player_Normal::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_Normal::Shutdown()
{

}

