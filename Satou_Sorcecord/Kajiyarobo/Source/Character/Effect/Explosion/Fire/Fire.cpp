#include "Fire.h"
#include "../../../../Utility/Enum/TextureName.h"
#include "../../../../Base/Actor/Actor/Actor.h"

Fire::Fire(IWorld* world, Actor* enemy, float front)
	:Actor(world, "Fire", GSvector3(0.0f, 0.0f, 0.0f), BoundingSphere(0.0f), nullptr)
	, mTimer(20.0f)
{
	const GSfloat pitch = gsRandf(0.0f, 360.0f);
	const GSfloat yaw = gsRandf(0.0f, 360.0f);
	const GSfloat speed = gsRandf(1.0f, 5.0f);

	mVelocity = GSvector3::createFromPitchYaw(pitch, yaw) * speed;

	GSvector3 lVelocity = enemy->GetRotate().getAxisZ().normalize() * front;

	m_Position = enemy->GetPosition() + lVelocity;
}

Fire::Fire(IWorld* world, GSvector3& position)
	: Actor(world, "Fire", position, BoundingSphere(0.0f), nullptr)
	, mTimer(20.0f)
	, mVelocity(0.0f, 0.0f, 0.0f)
{
	const GSfloat pitch = gsRandf(0.0f, 360.0f);
	const GSfloat yaw = gsRandf(0.0f, 360.0f);
	const GSfloat speed = gsRandf(1.0f, 5.0f);

	mVelocity = GSvector3::createFromPitchYaw(pitch, yaw) * speed;

}

void Fire::OnUpdate(float deltaTime)
{
	m_Position += mVelocity * deltaTime;
	mVelocity *= 0.8f * deltaTime;
	if (mTimer <= 0.0f)
		Dead();

	mTimer -= deltaTime;
}

void Fire::OnDraw()const
{
	//各種レンダリングモードの退避(他の場所が変更されないようにする)
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ライティングをオフにする
	glDisable(GL_LIGHTING);
	//ｚバッファに書き込みを行わない
	glDepthMask(GL_FALSE);
	//加算のブレンドを有効にする
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);

	//３Dスプライトの表示
	static const GSrect body(-4.0f, 4.0f, 4.0f, -4.0f);
	const GScolor color(1.0f, 0.5f, 0.2f, mTimer / 20.0f);
	gsDrawSprite3D((GSuint)TextureName::Fire, &m_Position, &body, NULL, &color, NULL, 0.0f);
	//各種レンダリングモードの復帰
	glPopAttrib();

}