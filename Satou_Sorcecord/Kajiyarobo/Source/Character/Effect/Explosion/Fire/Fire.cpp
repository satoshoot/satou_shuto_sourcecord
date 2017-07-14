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
	//�e�탌���_�����O���[�h�̑ޔ�(���̏ꏊ���ύX����Ȃ��悤�ɂ���)
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//���C�e�B���O���I�t�ɂ���
	glDisable(GL_LIGHTING);
	//���o�b�t�@�ɏ������݂��s��Ȃ�
	glDepthMask(GL_FALSE);
	//���Z�̃u�����h��L���ɂ���
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);

	//�RD�X�v���C�g�̕\��
	static const GSrect body(-4.0f, 4.0f, 4.0f, -4.0f);
	const GScolor color(1.0f, 0.5f, 0.2f, mTimer / 20.0f);
	gsDrawSprite3D((GSuint)TextureName::Fire, &m_Position, &body, NULL, &color, NULL, 0.0f);
	//�e�탌���_�����O���[�h�̕��A
	glPopAttrib();

}