#include "Player_Guard.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Player.h"
#include "../../../../../../Base/GameManager/GameManager.h"
#include "../../../../../../Wepon/Wepon/Wepon.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"
#include "../../../PlayerHP/PlayerHP.h"
#include "../../../../../Attack/EnemyAttack/EnemyAttack.h"
#include "../../../../../../Utility/Enum/SoundName.h"

Player_Guard::Player_Guard(
	Player* player,
	AnimationMesh* animation,
	Menu* menu,
	PlayerHP* hp,
	GameManager* gameManager)
	: AbstractPlayer(nullptr, nullptr, player, animation, nullptr, menu, hp, nullptr, gameManager)
{

}

void Player_Guard::OnInitialize()
{
	pAnimation->ChangeMotion(10);
}

void Player_Guard::Update(float deltaTime)
{
	if (Dead() == true)
		return;
	if (mCounter <= 0)
		mVelocity = GSvector3(0.0f, 0.0f, 0.0f);

	RotateMove(-1);

	mCounter -= deltaTime;

	if (pMenu->GetCurrentState() != MenuStateName::Close)
	{
		mNextState = PlayerStateName::OpenMenu;
		return;
	}
	if (gsXBoxPadButtonState(0, GS_XBOX_PAD_A))
		return;

	mNextState = PlayerStateName::Normal;

}

void Player_Guard::HoldDraw()const
{
	WeponDraw();
}

void Player_Guard::Collide(Actor& other)
{
	if (other.GetName() == "EnemyAttack")
	{
		gsPlaySE((GSuint)SoundName::GuardSE);

		EnemyAttack& lAttack = dynamic_cast<EnemyAttack&>(other);
		pHP->Damage(0, lAttack.GetID());

		GSvector3 lVelocity = pPlayer->GetPosition() - other.GetPosition();
		lVelocity.normalize();
		lVelocity.y = 0.0f;
		mVelocity = lVelocity * 3;

		const int lRand = 3 * pGameManager->GetPlayerWepon()->GetDefenseLv();

		if (gsRand(0, lRand) == 0)
		{
			mNextState = PlayerStateName::GuardBreak;
			return;
		}
		mCounter = 5;
	}
}

void Player_Guard::Shutdown()
{
	mVelocity = GSvector3(0.0f, 0.0f, 0.0f);
}