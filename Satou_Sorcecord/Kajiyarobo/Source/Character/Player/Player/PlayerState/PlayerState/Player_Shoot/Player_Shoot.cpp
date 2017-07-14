#include "Player_Shoot.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../Attack/PlayerBullet/SpeedBullet/SpeedBullet.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../../Wepon/WeponType/WeponType.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../../../../Utility/Move/Move.h"
#include "../../../Player.h"
#include "../../../../../../Base/Actor/Camera/Camera.h"
#include "../../../../../../Utility/Enum/SoundName.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"


Player_Shoot::Player_Shoot(
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

void Player_Shoot::OnInitialize()
{
	mCounter = 20;
	pAnimation->ChangeMotion(15);

	gsPlaySE((GSuint)SoundName::LaserSE);

	GSmatrix4 lBorn = pAnimation->GetMatrices().at(4);
	GSvector3 lPosition = lBorn.getPosition() + GSvector3(0.0f, 1.5f, 0.0f);

	int lID = pID->GetID();

	float l_Range = (pGameManager->GetPlayerWepon()->GetRangeLv() - 1) * 20;
	pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<SpeedBullet>(
		pWorld, lPosition, pGameManager, pPlayer,
		l_Range, lID, pPlayer->Damage()));
}

void Player_Shoot::Update(float deltaTime)
{
	GSvector3 lLeft = pWorld->GetCamera()->GetRotate().getAxisX();

	GSvector3 lVelocity = pMove->Velocity(lLeft);

	//ˆÚ“®‚·‚é‘¬“x
	float speed = pMove->Speed();
	lVelocity *= speed;

	mVelocity = lVelocity * 0.8f * deltaTime;

	if (Dead() == true)
		return;
	if (mCounter <= 0)
		mNextState = PlayerStateName::ShootNormal;

	if (pMenu->GetCurrentState() != MenuStateName::Close)
	{
		mNextState = PlayerStateName::OpenMenu;
		return;
	}
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_X) && mCounter <= 13)
	{
		mNextState = PlayerStateName::Shoot;
		return;
	}
	Rotate();

	mCounter -= deltaTime;
}

void Player_Shoot::HoldDraw()const
{
	WeponDraw();
}

void Player_Shoot::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_Shoot::Shutdown()
{

}

