#include "Player_Dead.h"
#include "../../../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../PlayerHP/PlayerHP.h"

Player_Dead::Player_Dead(Player* player, AnimationMesh* mesh, GameManager* gameManager)
	: AbstractPlayer(nullptr, nullptr, player, mesh, nullptr, nullptr, nullptr, nullptr, gameManager)
{

}

void Player_Dead::OnInitialize()
{
	mCounter = 120;
	pAnimation->ChangeMotion(19);
}

void Player_Dead::Update(float deltaTime)
{
	mCounter -= deltaTime;
}

void Player_Dead::HoldDraw()const
{
	WeponDraw();
}

void Player_Dead::Collide(Actor& other)
{ }

void Player_Dead::Shutdown()
{ }