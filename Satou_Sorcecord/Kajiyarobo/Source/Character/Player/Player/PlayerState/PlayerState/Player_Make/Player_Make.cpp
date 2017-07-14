#include "Player_Make.h"
#include "../../../../../../Menu/Menu/Menu.h"
#include "../../../../../../Menu/MenuStateName/MenuStateName.h"
#include "../../../../PlayerStateName/PlayerStateName.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../../../Utility/Enum/MeshName.h"

Player_Make::Player_Make(
	IWorld* world,
	Player* player,
	AnimationMesh* animation,
	Menu* menu,
	PlayerHP* hp,
	Shield* shield,
	GameManager* gameManager)
	: AbstractPlayer(world, nullptr, player, animation, nullptr, menu, hp, shield, gameManager)
{

}

void Player_Make::OnInitialize()
{
	pAnimation->ChangeMotion(3);
}

void Player_Make::Update(float deltaTime)
{
	if (Dead() == true)
		return;
	if (pMenu->GetCurrentState() == MenuStateName::Close)
		mNextState = PlayerStateName::Normal;
}

void Player_Make::HoldDraw()const
{
	//‰EŽè
	const GSmatrix4& lRightHand = pAnimation->GetMatrices().at(4);

	gsDisable(GS_SKIN_MESH);

	glPushMatrix();
	glMultMatrixf(lRightHand);
	gsDrawMesh((GSuint)MeshName::Hummer);
	glPopMatrix();

	//¶Žè
	const GSmatrix4& lLeftHand = pAnimation->GetMatrices().at(7);

	glPushMatrix();
	glMultMatrixf(lLeftHand);
	gsDrawMesh((GSuint)MeshName::MakeWepon);
	glPopMatrix();
}

void Player_Make::Collide(Actor& other)
{
	CollideDamage(other);
}

void Player_Make::Shutdown()
{

}