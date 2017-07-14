#include "Player_ShootNormal.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../../Utility/Move/Move.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/Actor.h"
#include "../../../../../../Wepon/WeponType/WeponType.h"
#include "../../../../../../Base/Actor/Camera/Camera.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"


Player_ShootNormal::Player_ShootNormal(
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

void Player_ShootNormal::OnInitialize()
{
	pAnimation->ChangeMotion(18);
}

void Player_ShootNormal::Update(float deltaTime)
{
	GSvector3& left = pWorld->GetCamera()->GetRotate().getAxisX().normalize();

	//ˆÚ“®—Í‚ð‘ã“ü
	GSvector3 lVelocity = pMove->Velocity(left);

	if (pMenu->GetCurrentState() != MenuStateName::Close)
	{
		mNextState = PlayerStateName::OpenMenu;
		return;
	}
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X))
	{
		if (pGameManager->GetPlayerWepon()->GetShotSpeed() <= 3)
			mNextState = PlayerStateName::Shoot;
		else if (pGameManager->GetPlayerWepon()->GetShotSpeed() <= 5)
			mNextState = PlayerStateName::ShootRapid;
	}
	else if (pGameManager->GetPlayerWepon()->GetWeponType() != WeponType::Gun)
		mNextState = PlayerStateName::Normal;


	//ˆÚ“®‚·‚é‘¬“x
	float speed = pMove->Speed();
	lVelocity *= speed;

	mVelocity = lVelocity * 1.3f * deltaTime;

	Rotate();
}

void Player_ShootNormal::HoldDraw()const
{
	WeponDraw();
}

void Player_ShootNormal::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_ShootNormal::Shutdown()
{

}
