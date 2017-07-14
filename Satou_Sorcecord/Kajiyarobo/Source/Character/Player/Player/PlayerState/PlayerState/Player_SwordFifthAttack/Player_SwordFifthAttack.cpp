#include "Player_SwordFifthAttack.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../../Attack/AttackID/AttackID.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../../../Attack/PlayerAttack/PlayerSwordAttack.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Player.h"
#include "../../../../../../Utility/Move/Move.h"
#include "../../../../../../Base/Actor/Camera/Camera.h"
#include "../../../../../../Utility/Enum/SoundName.h"

Player_SwordFifthAttack::Player_SwordFifthAttack(
	IWorld* world,
	AttackID* id,
	Player* player,
	AnimationMesh* animation,
	Move* move,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	:AbstractPlayer(world, id, player, animation, move, nullptr, hp, shield, gameManager)
{

}

void Player_SwordFifthAttack::OnInitialize()
{
	mCounter = 100;
	pAnimation->ChangeMotion(9);
	mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
}

void Player_SwordFifthAttack::Update(float deltaTime)
{
	if (mCounter <= 60 && mCounter >= 20)
	{
		GSvector3& lLeft = pWorld->GetCamera()->GetRotate().getAxisX().normalize();
		GSvector3 front = pMove->Velocity(lLeft) * deltaTime;
		mVelocity = front / 5;
	}
	else
		mVelocity = GSvector3(0.0f, 0.0f, 0.0f);

	if (mCounter == 20 || mCounter == 40 || mCounter == 60)
	{
		gsPlaySE((GSuint)SoundName::SwordSE);

		float radius =
			12.0f + 0.8f * pGameManager->GetPlayerWepon()->GetRangeLv();
		int lID = pID->GetID();

		pWorld->AddActor(ActorGroup::PlayerAttack, new_Actor<PlayerSwordAttack>(
			pWorld, pGameManager, pPlayer, 0.0f, 10, radius, lID,pPlayer->Damage()));
	}
	if (Dead() == true)
		return;
	if (mCounter <= 0)
	{
		//’Êí‚É–ß‚é
		mNextState = PlayerStateName::Normal;
		return;
	}

	mCounter -= deltaTime;
}

void Player_SwordFifthAttack::HoldDraw()const
{
	WeponDraw();
}

void Player_SwordFifthAttack::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_SwordFifthAttack::Shutdown()
{

}
