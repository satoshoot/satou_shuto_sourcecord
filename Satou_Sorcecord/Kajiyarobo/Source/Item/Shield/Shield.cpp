#include "Shield.h"
#include "../../Character/Player/Player/Player.h"
#include "../../Utility/Enum/MeshName.h"

Shield::Shield(Player* player)
	: Actor(nullptr, "Shield", GSvector3(0.0f, 0.0f, 0.0f), BoundingSphere(5.0f), nullptr)
	, pPlayer(player)
	, mGuard(false)
	, mAngle(0.0f)
{

}

void Shield::OnUpdate(float deltaTime)
{
	m_Position = pPlayer->GetPosition();
	m_Rotate = pPlayer->GetRotate();

	m_Rotate.rotateY(mAngle);
	mAngle += deltaTime * 0.5f;
}

void Shield::OnDraw()const
{
	if (mGuard == false)
		return;

	GSmatrix4 projection(m_Rotate);
	projection.setPosition(m_Position);

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(projection);
	gsDrawMesh((GSuint)MeshName::Shield);
	glPopMatrix();
}

void Shield::OnCollide(Actor& other)
{ }

void Shield::UseItem()
{
	mGuard = true;
}

bool Shield::Guard()const
{
	return mGuard;
}

void Shield::Hit()
{
	mGuard = false;
}