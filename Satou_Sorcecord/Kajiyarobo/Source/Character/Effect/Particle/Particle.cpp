#include "Particle.h"
#include "../../../Utility/Enum/TextureName.h"

Particle::Particle(IWorld* world, GSvector3& position, GameManager* gameManager)
	: Actor(world, "Effect", position, BoundingSphere(0.0f), gameManager)
	, mGravity(0.0f)
	, mCounter(gsRandf(10.0f, 30.0f))
{
	const float lVelocityX = gsRandf(-1.7f, 1.7f);
	const float lVelocityY = gsRandf(-0.5f, 1.2f);
	const float lVelocityZ = gsRandf(-1.7f, 1.7f);

	mVelocity = GSvector3(lVelocityX, lVelocityY, lVelocityZ);

}

void Particle::OnUpdate(float deltaTime)
{

	mVelocity.y += mGravity;
	mGravity -= 0.002f;

	m_Position += mVelocity;

	if (mCounter <= 0)
		Dead();

	mCounter -= deltaTime;
}

void Particle::OnDraw()const
{
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	//glEnable(GL_BLEND);


	static const GSrect lRect(-0.0f, 0.0f, 64.0f, 64.0f);
	const GScolor lColor(1.0f, 0.6f, 0.4f, 1.0f);
	const GSvector2 l_Scale(0.007f, 0.007f);
	gsDrawSprite3D((GSuint)TextureName::Particle, &m_Position, &lRect, NULL, &lColor, &l_Scale, 0.0f);

	glPopAttrib();
}
