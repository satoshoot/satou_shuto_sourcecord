#include "Player_ShootRapid.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../Attack/PlayerBullet/RapidBullet/RapidBullet.h"
#include "../../../Player.h"
#include "../../../../../../Utility/Move/Move.h"
#include "../../../../../../Base/Actor/Camera/Camera.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../../Wepon/WeponSpecialSkill/WeponSpecialSkill.h"
#include "../../../../../../Utility/Enum/SoundName.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"


Player_ShootRapid::Player_ShootRapid(
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
	, mShotCount(0)
{

}

void Player_ShootRapid::OnInitialize()
{
	pAnimation->ChangeMotion(15);
	GSmatrix4 lBorn = pAnimation->GetMatrices().at(4);
	GSvector3 lPosition = lBorn.getPosition() + GSvector3(0.0f, 2.0f, 0.0f)
		+ pPlayer->GetRotate().getAxisZ().normalize() * 4;

	int lID = pID->GetID();

	if (pPlayer->GetName() == "Player" &&
		pGameManager->GetPlayerWepon()->GetSpecialSkill() == WeponSpecialSkill::IceLaser)
	{
		if (mShotCount % 2 == 0)
			gsPlaySE((GSuint)SoundName::LaserSE);

		mCounter = 7;

		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<RapidBullet>(
			pWorld, lPosition, pGameManager, pPlayer, lID, 30.0f,
			pGameManager->GetPlayerWepon()->GetSpecialSkill(), 7.0f, 9.0f, pPlayer->Damage()));
		return;
	}

	gsPlaySE((GSuint)SoundName::LaserSE);
	mCounter = 12;

	pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<RapidBullet>(
		pWorld, lPosition, pGameManager, pPlayer, lID, 25.0f,
		pGameManager->GetPlayerWepon()->GetSpecialSkill(), 2.0f, 5.0f, pPlayer->Damage()));
}

void Player_ShootRapid::Update(float deltaTime)
{
	GSvector3& left = pWorld->GetCamera()->GetRotate().getAxisX().normalize();

	//ˆÚ“®—Í‚ð‘ã“ü
	GSvector3 lVelocity = pMove->Velocity(left);

	//ˆÚ“®‚·‚é‘¬“x
	float speed = pMove->Speed();
	lVelocity *= speed;

	mVelocity = lVelocity * 0.8f * deltaTime;

	if (Dead() == true)
		return;
	if (pMenu->GetCurrentState() != MenuStateName::Close)
	{
		mNextState = PlayerStateName::OpenMenu;
		return;
	}
	if (mCounter <= 5 && gsXBoxPadButtonState(0, GS_XBOX_PAD_X))
	{
		mNextState = PlayerStateName::ShootRapid;
		return;
	}
	if (mCounter <= 0)
	{
		mNextState = PlayerStateName::ShootNormal;
		return;
	}
	Rotate();

	mCounter -= deltaTime;
}

void Player_ShootRapid::HoldDraw()const
{
	WeponDraw();
}

void Player_ShootRapid::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_ShootRapid::Shutdown()
{
	mShotCount++;
}
