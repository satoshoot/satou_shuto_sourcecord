#include "AbstractPlayer.h"
#include "../PlayerStateName/PlayerStateName.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Wepon/Wepon/Wepon.h"
#include "../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../Attack/EnemyAttack/EnemyAttack.h"
#include "../Player/PlayerHP/PlayerHP.h"
#include "../../../Item/Shield/Shield.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../Player/Player.h"
#include "../../../Base/Actor/Camera/Camera.h"
#include "../../../Base/Actor/Camera/CameraStateName/CameraStateName.h"
#include "../../../Utility/Move/Move.h"
#include "../../../Menu/Menu/Menu.h"
#include "../../../Menu/MenuStateName/MenuStateName.h"


AbstractPlayer::AbstractPlayer(
	IWorld* world,
	AttackID* id,
	Player* player,
	AnimationMesh* animation,
	Move* move,
	Menu* menu,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	: pWorld(world)
	, mCounter(0)
	, mNextState(PlayerStateName::None)
	, pID(id)
	, pPlayer(player)
	, pAnimation(animation)
	, pMove(move)
	, pMenu(menu)
	, pGameManager(gameManager)
	, mVelocity(0.0f, 0.0f, 0.0f)
	, pHP(hp)
	, pShield(shield)
	, mRotate(GS_MATRIX4_IDENTITY)
{

}

void AbstractPlayer::Initialize()
{
	mNextState = PlayerStateName::None;
	mRotate = pPlayer->GetRotate();
	OnInitialize();
}

PlayerStateName AbstractPlayer::ChangeState()
{
	return mNextState;
}


GSvector3 AbstractPlayer::GetVelocity()const
{
	return mVelocity;
}

GSmatrix4 AbstractPlayer::GetRotate()const
{
	return mRotate;
}

void AbstractPlayer::WeponDraw()const
{
	//ƒ{[ƒ“‚Ì‚S”Ô–Ú‚É‚­‚Á‚Â‚­(‰EŽè)
	const GSmatrix4& wepon = pAnimation->GetMatrices().at(4);

	gsDisable(GS_SKIN_MESH);

	glPushMatrix();
	glMultMatrixf(wepon);
	gsDrawMesh(pGameManager->GetPlayerWepon()->GetMeshID());
	glPopMatrix();
}

void AbstractPlayer::CollideDamage(Actor& other)
{
	if (other.GetName() == "EnemyAttack")
	{
		EnemyAttack& lAttack = dynamic_cast<EnemyAttack&>(other);
		if (pShield->Guard() == true &&
			pHP->Damage(0, lAttack.GetID()))
		{
			pShield->Hit();
			return;
		}
		if (pHP->Damage(lAttack.Damage(), lAttack.GetID()))
			mNextState = PlayerStateName::Stun;
	}
}
bool AbstractPlayer::Dead()
{
	if (pHP->Dead())
	{
		mNextState = PlayerStateName::Dead;
		return true;
	}
	return false;
}

void AbstractPlayer::RotateMove(int reverse)
{
	if (mVelocity.x != 0.0f || mVelocity.z != 0.0f)
	{
		GSvector3 lNormalizeVelocity = mVelocity;
		lNormalizeVelocity.y = 0.0f;
		lNormalizeVelocity.normalize();
		GSvector3 lUp = mRotate.getAxisY().normalize();
		GSvector3 lFront = lNormalizeVelocity;
		lFront *= reverse;

		GSvector3 lLeft = lUp.cross(lFront);

		mRotate.setAxisZ(lFront);
		mRotate.setAxisX(lLeft);
		mRotate.setAxisY(lUp);
	}
}

void AbstractPlayer::RotateTarget()
{
	if (pWorld->GetTargetEnemyName(pPlayer->GetPosition()) != "None")
	{
		if (pWorld->GetCamera()->GetCameraState() == CameraStateName::PlayerLockon)
		{
			GSvector3 lFrontVelocity = pWorld->GetCamera()->GetTargetPosition() - pPlayer->GetPosition();

			lFrontVelocity.y = 0.0f;
			lFrontVelocity.normalize();

			GSvector3 lUp = mRotate.getAxisY().normalize();

			GSvector3 lFront = lFrontVelocity;
			GSvector3 lLeft = lUp.cross(lFront);

			mRotate.setAxisZ(lFront);
			mRotate.setAxisX(lLeft);
			mRotate.setAxisY(lUp);
			return;
		}
		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
			RotateAttack();
	}
}

void AbstractPlayer::RotateAttack()
{
	if (pMove->Speed() <= 0.3f &&
		pMenu->GetCurrentState() == MenuStateName::Close)
	{
		GSvector3 lFront = pWorld->FindActor(pWorld->GetTargetEnemyName(pPlayer->GetPosition()))->
			GetPosition() - pPlayer->GetPosition();
		lFront.y = 0.0f;
		lFront.normalize();
		GSvector3 lUp = mRotate.getAxisY().normalize();

		GSvector3 lLeft = lUp.cross(lFront);

		mRotate.setAxisZ(lFront);
		mRotate.setAxisX(lLeft);
		mRotate.setAxisY(lUp);
	}

}

void AbstractPlayer::Rotate()
{
	RotateMove(1);
	RotateTarget();
}