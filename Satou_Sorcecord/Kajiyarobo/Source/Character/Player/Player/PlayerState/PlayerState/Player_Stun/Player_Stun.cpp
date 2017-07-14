#include "Player_Stun.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"
#include "../../../../../../Utility/Enum/MeshName.h"

Player_Stun::Player_Stun(
	Player* player,
	AnimationMesh* animation,
	Menu* menu,
	Shield* shield,
	GameManager* gameManager)
	: AbstractPlayer(nullptr, nullptr, player, animation, nullptr, menu, nullptr, shield, gameManager)
{

}

void Player_Stun::OnInitialize()
{
	pAnimation->ChangeMotion(20);
	mCounter = 30.0f;
}

void Player_Stun::Update(float deltaTime)
{

	if (mCounter <= 0)
		mNextState = PlayerStateName::Normal;

	mCounter -= deltaTime;
}

void Player_Stun::HoldDraw()const
{
	if (pMenu->GetCurrentState() == MenuStateName::Close)
	{
		WeponDraw();
		return;
	}
	const GSmatrix4& lRightHand = pAnimation->GetMatrices().at(4);

	gsDisable(GS_SKIN_MESH);

	glPushMatrix();
	glMultMatrixf(lRightHand);
	gsDrawMesh((GSuint)MeshName::Hummer);
	glPopMatrix();
}

void Player_Stun::Collide(Actor& other)
{

}

void Player_Stun::Shutdown()
{ }