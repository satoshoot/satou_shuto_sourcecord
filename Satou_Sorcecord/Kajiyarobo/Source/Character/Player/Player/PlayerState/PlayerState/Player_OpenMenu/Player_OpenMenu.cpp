#include "Player_OpenMenu.h"
#include "../../../../../../Base/Actor/World/IWorld.h"
#include "../../../../../../Base/Actor/Camera/Camera.h"
#include "../../../../../../Utility/Move/Move.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"
#include "../../../../../../Utility/Enum/MeshName.h"

Player_OpenMenu::Player_OpenMenu(
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

void Player_OpenMenu::OnInitialize()
{

}

void Player_OpenMenu::Update(float deltaTime)
{
	int lAnimationID = 0;

	GSvector3& left = pWorld->GetCamera()->GetRotate().getAxisX().normalize();

	//移動力を代入
	GSvector3 lVelocity = pMove->Velocity(left);


	//ダッシュアニメーションに変える
	if (pMove->Speed() >= 0.7f)
		lAnimationID = 1;


	//移動する速度
	float speed = pMove->Speed();
	lVelocity *= speed;

	mVelocity = lVelocity * 1.3f * deltaTime;

	pAnimation->ChangeMotion(lAnimationID);

	if (Dead() == true)
		return;
	if (pMenu->GetCurrentState() == MenuStateName::MakeTime)
	{
		mNextState = PlayerStateName::Make;
		return;
	}
	if (pMenu->GetCurrentState() == MenuStateName::Close)
	{
		mNextState = PlayerStateName::Normal;
		return;
	}
	Rotate();
}

void Player_OpenMenu::HoldDraw()const
{
	const GSmatrix4& lRightHand = pAnimation->GetMatrices().at(4);

	gsDisable(GS_SKIN_MESH);

	glPushMatrix();
	glMultMatrixf(lRightHand);
	gsDrawMesh((GSuint)MeshName::Hummer);
	glPopMatrix();
}

void Player_OpenMenu::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_OpenMenu::Shutdown()
{

}