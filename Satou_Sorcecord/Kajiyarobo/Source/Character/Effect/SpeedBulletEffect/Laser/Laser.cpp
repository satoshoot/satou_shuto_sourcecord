#include "Laser.h"
#include "../../../../Utility/Enum/MeshName.h"


Laser::Laser(
	IWorld* world, const GSvector3 position, GameManager* gameManager,
	GSvector3& velocity, float speed, float count)
	: Actor(world, "Effect", position, BoundingSphere(0.0f), gameManager)
	, mCounter(count)
	, mVelocity(velocity)
	, mSpeed(speed)
{

}

void Laser::OnUpdate(float deltaTime)
{
	m_Position += mVelocity * mSpeed;

	if (mCounter <= 0)
		Dead();

	mCounter -= deltaTime;
}

void Laser::OnDraw()const
{
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);

	static const GSrect lRect(-0.2f, 0.2f, 0.2f, -0.2f);
	const GScolor lColor(0.8f, 0.8f, 0.3f, 1.0f);
	gsDrawSprite3D((GSuint)MeshName::SpeedBulletEffect, &m_Position, &lRect, NULL, &lColor, NULL, 0.0f);

	glPopAttrib();
}

void Laser::OnCollide(Actor& other)
{

}
